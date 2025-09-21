#include "engine.hpp"
#include <iostream>

void rignis::GameEngine::create(const GameEngineConfiguration &configuration)
{
    std::cout << "Rignis - Game Engine -- Start";
    if (window != nullptr)
    {
        std::cerr << "Rignis - Game Engine existing window not closed\n";
        return;
    }
    if (configuration.getWidth() <= 0)
    {
        std::cerr << "Rignis - Game Engine Invalid width";
    }
    if (configuration.getHeight() <= 0)
    {
        std::cerr << "Rignis - Game Engine Invalid height";
    }
    this->window = new sf::RenderWindow(
        sf::VideoMode(
            {configuration.getWidth(),
             configuration.getHeight()}),
        configuration.getTitle(),
        configuration.isFullScreen() ? sf::State::Fullscreen : sf::State::Windowed);
}

void rignis::GameEngine::destroy()
{
    std::cout << "Rignis - Game Engine -- Stop";
    if (this->window != nullptr)
    {
        this->window->close();
        this->window = nullptr;
    }
}

void rignis::GameEngine::resume()
{
    std::cout << "Rignis - Game Engine -- Resume";
}

void rignis::GameEngine::pause()
{
    std::cout << "Rignis - Game Engine -- Pause";
}

void rignis::GameEngine::addScreen(const GameScreen &screen)
{
    std::cout << "Rignis - Game Engine -- addScreen";
}

void rignis::GameEngine::removeScreen(const GameScreen &screen)
{
    std::cout << "Rignis - Game Engine -- removeScreen";
}

void rignis::GameEngine::setFrameRate(int frameRate)
{
}