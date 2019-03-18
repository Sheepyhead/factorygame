#include <iostream>
#include <SFML/Graphics.hpp>

void main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "Hello World!");

    std::string fileName = "..\\graphics\\angery.png";
    sf::Texture texture;
    if (!texture.loadFromFile(fileName))
    {
        std::cerr << "FAILED LOADING TEXTURE FILE " << fileName << std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(sprite);

        window.display();
    }
}