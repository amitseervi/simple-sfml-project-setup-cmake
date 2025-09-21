#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight)
{
    float windowRatio = (float)windowWidth / (float)windowHeight;
    float viewRatio = view.getSize().x / view.getSize().y;
    float sizeX = 1.f;
    float sizeY = 1.f;
    float posX = 0.f;
    float posY = 0.f;

    // Window wider than view: pillarbox
    if (windowRatio > viewRatio)
    {
        sizeX = viewRatio / windowRatio;
        posX = (1.f - sizeX) / 2.f;
    }
    // Window taller than view: letterbox
    else
    {
        sizeY = windowRatio / viewRatio;
        posY = (1.f - sizeY) / 2.f;
    }

    view.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
    return view;
}

int main()
{
    std::cout << "Test\n";
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Example", sf::State::Fullscreen);
    window.setFramerateLimit(60);
    sf::View viewPort({400, 300}, {800, 600});
    viewPort = getLetterboxView(viewPort, 800, 600);
    sf::RectangleShape box({796, 596});
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::Red);
    box.setOutlineThickness(2.0f);
    box.setOrigin({-2, -2});
    sf::CircleShape circle(2);
    circle.setOrigin({0, 0});
    circle.setFillColor(sf::Color::Green);
    float velocityX = 0.01f;
    float velocityY = 0.02f;
    sf::Clock clock;
    float circleX = .0f;
    float circleY = .0f;
    while (window.isOpen())
    {
        int32_t dt = clock.restart().asMilliseconds();
        while (const std::optional event = window.pollEvent())
        {
            if (event.has_value())
            {

                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }

                if (auto keyEvent = event.value().getIf<sf::Event::KeyPressed>())
                {
                    if (keyEvent->code == sf::Keyboard::Key::Escape)
                    {
                        window.close();
                    }
                }

                if (auto resizeEvent = event.value().getIf<sf::Event::Resized>())
                {
                    viewPort = getLetterboxView(viewPort, resizeEvent->size.x, resizeEvent->size.y);
                }
            }
        }
        circleX -= dt * velocityX;
        circleY -= dt * velocityY;
        circle.setOrigin({circleX, circleY});
        window.setView(viewPort);
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(box);
        window.setView(window.getDefaultView());
        window.display();
    }
    std::cout << "Window closed\n";
    return 0;
}
