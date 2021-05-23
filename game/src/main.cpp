#include "../include/Game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Game");
    sf::CircleShape shape(100.f, 10);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }


        }

        window.clear(sf::Color::Magenta);
        window.draw(shape);
        window.display();
    }

    return 0;
}
