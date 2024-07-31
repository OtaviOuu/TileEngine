#ifndef ENTITY.H
#define ENTITY .H

#include <vector>
#include <string>
#include "./EntityManager.h"

class Entity
{
private:
    EntityManager &manager;
    bool isActive;
    std::vector<Component *> components;

public:
    std::string name;
    Entity(EntityManager &manager);
    Entity(EntityManager &manager, std::string name);
    void Update(float deltaTime);
    void Destroy();
    void Render();
    bool IsActivate() const;
};

#endif