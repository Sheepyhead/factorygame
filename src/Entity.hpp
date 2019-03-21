#ifndef _ENTITY_H
#define _ENTITY_H

#include <cstdint>
#include <vector>

using Entity = std::uint64_t;
std::vector<Entity> Entities = [] {
    std::vector<uint64_t> v;
    return v;
}();
Entity CreateEntity() {
    Entity entity;
    if (Entities.empty())
        entity = 0;
    else
        entity = Entities.back() + 1;

    Entities.push_back(entity);

    return entity;
}
#endif // _ENTITY_H