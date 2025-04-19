#include <SFML/Graphics.hpp>
#include "Entity.hpp"

int main()
{
    

    sf::RenderWindow window (sf::VideoMode({ 256, 420}), "SFML works!");

    const std::string character = "Sprite.png";
  
    Entity test(character);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        
        window.clear();
        test.setScale(0.2, 0.2);
        test.drawEntity(window);
        window.display();

    }
}