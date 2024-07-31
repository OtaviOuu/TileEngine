#include "EntityManager.h"

void EntityManager::ClearData()
{
    for (auto *entity : entities)
    {
        entity->Destroy();
    }
}

void EntityManager::Update(float deltaTime)
{
    for (auto *entity : entities)
    {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render()
{
    for (auto *entity : entities)
    {
        entity->Render();
    }
}

Entity &EntityManager::AddEntity(std::string name)
{
    Entity *newEntity = new Entity(*this, name);
    entities.emplace_back(newEntity);
    return *newEntity;
}

bool EntityManager::HasNoEntities() const
{
    return entities.size() == 0;
}

std::vector<Entity *> EntityManager::GetEntities() const
{
    return entities;
}

unsigned int EntityManager::GetEntityCount() const
{
    return entities.size();
}
