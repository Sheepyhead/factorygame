#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "RenderComponent.hpp"
#include "Entity.hpp"

struct {
    sf::RenderWindow *mainWindow;
} Globals;

void Render(sf::RenderWindow &window) {
    RenderComponentSystem(window);
}

void main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World!");
    Globals.mainWindow = &window;
    std::string fileName = "..\\graphics\\angery.png";
    sf::Texture texture;
    if (!texture.loadFromFile(fileName))
    {
        std::cerr << "FAILED LOADING TEXTURE FILE " << fileName << std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::SoundBuffer soundBuffer;
    soundBuffer.loadFromFile("..\\audio\\sound.wav");

    sf::Sound sound;
    sound.setBuffer(soundBuffer);

    sf::Event event;
    Entity entity = CreateEntity();
    RenderComponent component;
    component.sprite = sprite;
    AddComponent(entity, component);

    while (window.isOpen())
    {
        static sf::Color backgroundColor = sf::Color::Black;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Space:
                    sound.play();
                    break;
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                default:
                    break;
                }
            }
        }

        Render(window);
    }
}