#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Entity.hpp"
#include "Backdrop.hpp"

int main()
{
    

    sf::RenderWindow window (sf::VideoMode({ 1536u, 1024u}), "SFML works!");

    const std::string character = "Sprite.png";
    Backdrop test1("Backdrop1.png", "Ground.png");
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
        test1.drawBackdrop(window);
        test.drawEntity(window);
        window.display();

    }
}