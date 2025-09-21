#include "engine_configuration.hpp";

void rignis::GameEngineConfiguration::setFullScreen(bool isFullScreen)
{
    this->fullScreen = isFullScreen;
}

void rignis::GameEngineConfiguration::setHeight(const u_int32_t height)
{
    this->height = height;
}

void rignis::GameEngineConfiguration::setWidth(const u_int32_t width)
{
    this->width = width;
}
