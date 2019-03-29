#ifndef _TRANSFORM_COMPONENT_H
#define _TRANSFORM_COMPONENT_H

#include <unordered_map>

#include "Entity.hpp"

struct TransformComponent {
    float X;
    float Y;
    uint64_t ZOrder;
};

namespace __ENGINE__
{
std::unordered_map<Entity, TransformComponent> TransformComponents = [] {
    std::unordered_map<Entity, TransformComponent> map;
    return map;
}();
}
using namespace __ENGINE__;

void AddComponent(const Entity &entity, const TransformComponent &transformComponent)
{
    TransformComponents[entity] = transformComponent;
}

void RemoveComponent(const Entity &entity, const TransformComponent &transformComponent = {})
{
    TransformComponents.erase(entity);
}

#endif // _TRANSFORM_COMPONENT_H