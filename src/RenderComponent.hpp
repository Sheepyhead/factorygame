#ifndef _RENDER_COMPONENT_H
#define _RENDER_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "TransformComponent.hpp"
#include "Entity.hpp"

struct RenderComponent
{
    sf::Sprite sprite;
};

namespace __ENGINE__
{
std::unordered_map<Entity, RenderComponent> RenderComponents = [] {
    std::unordered_map<Entity, RenderComponent> map;
    return map;
}();
}
using namespace __ENGINE__;

void AddComponent(const Entity &entity, const RenderComponent &renderComponent)
{
    RenderComponents[entity] = renderComponent;
}

void RemoveComponent(const Entity &entity, const RenderComponent &renderComponent = {})
{
    RenderComponents.erase(entity);
}

void RenderComponentSystem(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    for (const Entity &entity : Entities)
    {
        RenderComponent renderComponent;
        try {
            renderComponent = RenderComponents.at(entity);
        } catch (const std::out_of_range &exception) {
            return;
        }

        TransformComponent transformComponent;
        try // TODO: Extract this out into some kinda generic static function?
        {
            transformComponent = TransformComponents.at(entity);
        }
        catch (const std::out_of_range &exception)
        {
            // TODO: Define engine-specific exception set
            return;
        }
        
        window.draw(renderComponent.sprite);
    }
    window.display();
}

#endif // _RENDER_COMPONENT_H