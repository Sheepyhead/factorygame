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

namespace
{
std::unordered_map<Entity, RenderComponent> RenderComponents = [] {
    std::unordered_map<Entity, RenderComponent> map;
    return map;
}();
}

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
        RenderComponent component = RenderComponents[entity];
        TransformComponent component = TransformComponents[entity];
        
        window.draw(component.sprite);
    }
    window.display();
}

#endif // _RENDER_COMPONENT_H