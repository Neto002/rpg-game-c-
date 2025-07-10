#include <cmath>
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int main() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    // Create the main window (calls RenderWindow's constructor and assign an object to variable "window")
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "RPG Game",
        sf::Style::Default,
        sf::State::Windowed,
        settings
    );

    const sf::Texture playerTexture("assets/player/textures/spritesheet.png");

    const int frameWidth = 32;
    const int frameHeight = 32;
    const int frameCount = 6;
    const float frameDuration = 0.1f;

    sf::Sprite playerSprite(playerTexture);
    playerSprite.setScale(sf::Vector2f({2, 2}));
    playerSprite.setOrigin(sf::Vector2f({frameWidth / 2.f, frameHeight / 2.f})); // Change sprite pivot to center
    playerSprite.setPosition(sf::Vector2f({frameWidth, frameHeight}));

    int currentFrame = 0;
    float elapsed = 0.f;
    sf::Clock clock;

    int yIndex = 0;

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const std::optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        const float deltaTime = clock.restart().asSeconds();
        elapsed += deltaTime;

        // Changes frame if needed
        if (elapsed > frameDuration) {
            currentFrame = (currentFrame + 1) % frameCount;
            elapsed = 0.f;

            // Set texture rect
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                yIndex = 5;
                playerSprite.setScale(sf::Vector2f({2, 2}));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                yIndex = 3;
                playerSprite.setScale(sf::Vector2f({2, 2}));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                yIndex = 4;
                playerSprite.setScale(sf::Vector2f({-2, 2}));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                yIndex = 4;
                playerSprite.setScale(sf::Vector2f({2, 2}));
            }

            playerSprite.setTextureRect(sf::IntRect({currentFrame * frameWidth, yIndex * frameHeight}, {frameWidth, frameHeight}));
        }

        // Player Movement Implementation
        const float speed = 150.f;
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            movement.y -= 1.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            movement.y += 1.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            movement.x -= 1.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            movement.x += 1.f;
        }

        // Normalize diagonal movement (magnitude == 1)
        if (movement.x != 0.f && movement.y != 0.f) {
            movement /= std::sqrt(2.f);
        }

        playerSprite.move(movement * speed * deltaTime);

        // Clear screen
        window.clear();

        window.draw(playerSprite);

        // Update the window
        window.display();
    }
}
