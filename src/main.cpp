#include <SFML/Graphics.hpp>

void update(sf::RenderWindow &window);
void draw(sf::RenderWindow &window);

int main() {
    // Create the main window (calls RenderWindow's constructor and assign an object to variable "window")
    sf::RenderWindow window(sf::VideoMode({800, 600}), "RPG Game");

    // Start the game loop
    while (window.isOpen()) {
        update(window);
        draw(window);
    }
}

void update(sf::RenderWindow &window) {
    // Process events
    while (const std::optional event = window.pollEvent()) {
        // Close window: exit
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void draw(sf::RenderWindow &window) {
    // Clear screen
    window.clear();

    // Drawing goes here

    // Update the window
    window.display();
}