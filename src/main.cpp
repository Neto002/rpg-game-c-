#include <SFML/Graphics.hpp>

int main() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    // Create the main window (calls RenderWindow's constructor and assign an object to variable "window")
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "RPG Game",
        sf::Style::Default,
        sf::State::Windowed,
        settings
    );

    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color(250, 150, 100));
    shape.setPosition(sf::Vector2f(100, 100));

    sf::RectangleShape rectangleShape(sf::Vector2f(120, 50));
    rectangleShape.setFillColor(sf::Color(250, 150, 100));
    rectangleShape.setPosition(sf::Vector2f(250, 100));

    sf::CircleShape octagon(50.0f, 8);
    octagon.setFillColor(sf::Color(250, 150, 100));
    octagon.setPosition(sf::Vector2f(400, 100));

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const std::optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        // Drawing goes here
        window.draw(shape);
        window.draw(rectangleShape);
        window.draw(octagon);

        // Update the window
        window.display();
    }
}
