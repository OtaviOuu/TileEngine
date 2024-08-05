#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <SDL2/SDL.h>
#include "../EntityManager.h"
#include "../../lib/glm/glm.hpp"
#include "../Game.h"

class TransformComponent : public Component
{
public:
    glm::vec2 positiion;
    glm::vec2 velocity;
    int width;
    int height;
    int scale;

    TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
    {
        positiion = glm::vec2(posX, posY);
        velocity = glm::vec2(velX, velY);
        width, height, scale = w, h, s;
    }

    void Initialize() override {};

    void Update(float deltaTime) override
    {
        positiion.x += velocity.x * deltaTime;
        positiion.y += velocity.y * deltaTime;
    };

    void Render() override
    {
        SDL_Rect retangulo = {
            (int)positiion.x,
            (int)positiion.y,
            height,
            width};

        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(Game::renderer, &retangulo);
    }
};

#endif
