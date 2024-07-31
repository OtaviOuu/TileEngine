#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component
{
public:
    // Cada componente possui uma entidade dona. O dono ja está definido na memário, por isso usamos ponteiro
    Entity *owner;
    virtual ~Component() {};
    virtual void Initializate() {};
    virtual void Update(float deltaTime) {};
    virtual void Render() {};
};

#endif