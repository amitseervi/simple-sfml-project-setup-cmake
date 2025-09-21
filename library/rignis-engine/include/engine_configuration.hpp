#ifndef __HEADER_RIGNIS_ENGINE_CONFIGURATION__
#define __HEADER_RIGNIS_ENGINE_CONFIGURATION__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

namespace rignis
{
    class GameEngineConfiguration
    {
    public:
        GameEngineConfiguration(const std::string title) : title(title)
        {
        }

        void setFullScreen(bool isFullScreen);
        void setHeight(const u_int32_t height);
        void setWidth(const u_int32_t width);

        u_int32_t getWidth() const
        {
            return width;
        }

        u_int32_t getHeight() const
        {
            return height;
        }

        std::string getTitle() const
        {
            return title;
        }

        bool isFullScreen() const
        {
            return fullScreen;
        }

    private:
        bool fullScreen = false;
        u_int32_t width = -1;
        u_int32_t height = -1;
        std::string title;
    };
};
#endif