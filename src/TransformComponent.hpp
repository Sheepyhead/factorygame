#include <unordered_map>

#include "Entity.hpp"

struct TransformComponent {
    float X;
    float Y;
    uint64_t ZOrder;
};

namespace
{
std::unordered_map<Entity, TransformComponent> TransformComponents = [] {
    std::unordered_map<Entity, TransformComponent> map;
    return map;
}();
}

void AddComponent(const Entity &entity, const TransformComponent &transformComponent)
{
    TransformComponents[entity] = transformComponent;
}

void RemoveComponent(const Entity &entity, const TransformComponent &transformComponent = {})
{
    TransformComponents.erase(entity);
}