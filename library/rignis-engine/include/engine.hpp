#ifndef __HEADER_RIGNIS_ENGINE__
#define __HEADER_RIGNIS_ENGINE__

#include "screen.hpp"
#include "engine_configuration.hpp"

namespace rignis
{
    class GameEngine
    {
    public:
        void create(const GameEngineConfiguration &configuration);
        void destroy();
        void resume();
        void pause();
        void setFrameRate(int frameRate);
        void addScreen(const GameScreen &screen);
        void removeScreen(const GameScreen &screen);

    private:
        sf::RenderWindow *window = nullptr;
    };
};
#endif