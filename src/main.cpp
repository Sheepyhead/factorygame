#include <iostream>
#include <SFML/Window.hpp>

void main() {
    sf::Window window(sf::VideoMode(800,600), "Hello World!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}