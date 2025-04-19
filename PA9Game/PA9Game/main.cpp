#include <SFML/Graphics.hpp>
#include "Object.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1000, 800 }), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    std::vector<GameObject> objects;
    objects.emplace_back(sf::Vector2f{ 1000, 50 }, sf::Vector2f{ 0, 750 }, sf::Color::Green);
    objects.emplace_back(sf::Vector2f{ 100, 50 }, sf::Vector2f{ 200, 550 }, sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        for (const auto& object : objects)
        {
            window.draw(object.shape);
        }
        window.display();
    }
}