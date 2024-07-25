#include <iostream>
#include "Constants.h"
#include "Game.h"

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

float projecTilePosX = 0.0f;
float projecTilePosY = 0.0f;
float projecTileVelX = 20.0f;
float projecTileVelY = 30.0f;

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

        if (event.key.keysym.sym == SDLK_0)
        {
            projecTilePosX += 100;
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

    projecTilePosX += projecTileVelX * deltaTime;
    projecTilePosY += projecTileVelY * deltaTime;
}

void Game::Render()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME))
    {
    }
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    SDL_Rect projecTile{
        (int)projecTilePosX,
        (int)projecTilePosY,
        10,
        10};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &projecTile);

    SDL_RenderPresent(renderer);
}

void Game::Destroy()
{

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}