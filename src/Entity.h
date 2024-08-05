#ifndef ENTITY.H
#define ENTITY .H

#include <vector>
#include <string>
#include "./EntityManager.h"
#include "Component.h"

class EntityManager;

class Entity
{
private:
    EntityManager &manager;
    std::vector<Component *> components;
    bool isActive;

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