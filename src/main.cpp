#include <iostream>
#include <SFML/Graphics.hpp>

void main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World!");

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
        static sf::Color backgroundColor = sf::Color::Black;
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    backgroundColor = backgroundColor == sf::Color::Black ? sf::Color::Green : sf::Color::Black;
                }
            }
        }

        window.clear(backgroundColor);

        window.draw(sprite);

        window.display();
    }
}