#include <iostream>
#include "Constants.h"
#include "Game.h"
#include "EntityManager.h"
#include "../lib/glm/glm.hpp"

EntityManager *manager;
SDL_Renderer *Game::renderer;

Game::Game()
{
    isRunning = false;
}

Game::~Game()
{
    std::cout << "Game end" << std::endl;
}

bool Game::IsRunning() const
{
    return isRunning;
}

void Game::Initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error: SDL init" << std::endl;
        return;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS);
    if (!window)
    {
        std::cerr << "Error: Window init" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cerr << "Error: Renderer init" << std::endl;
        return;
    }
    isRunning = true;
}

void Game::ProcessInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            isRunning = false;
            break;
        }

    default:
        break;
    }
}

void Game::Update()
{

    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    ticksLastFrame = SDL_GetTicks();

    // Limitando o valor do delta para permitir o debug (??)
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;
}

void Game::Render()
{
    int timeToSleep = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

    if (timeToSleep > 0 && timeToSleep <= FRAME_TARGET_TIME)
    {
        SDL_Delay(timeToSleep);
    }

    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // TODO:
    // Chamar o manager.render para renderizar todas as entidades criadas

    // Troca o front buffer pelo back buffer
    SDL_RenderPresent(renderer);
}

void Game::Destroy()
{

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
