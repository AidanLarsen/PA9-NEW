#include <iostream>
#include <SFML/Graphics.hpp>

#include "Object.hpp"

#include "GroundEnemy.hpp"
#include "FlyingEnemy.hpp"

#include "Entity.hpp"

int main()
{



    sf::RenderWindow window (sf::VideoMode({1000, 800}), "SFML works!");


    const std::string character = "Sprite.png";

    const std::string character2 = "Lebron.png";
  
    //Entity test(character);

    GroundEnemy testEnemy(character, 100, 100, 500);

    FlyingEnemy testEnemy2(character2, 500, 500, 500);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        
        window.clear();

        testEnemy.setScale(0.2, 0.2);

        testEnemy2.setScale(0.9, 0.9);

        testEnemy.update();

        testEnemy2.update();

        testEnemy.drawEntity(window);

        testEnemy2.drawEntity(window);

        window.display();

    }
}