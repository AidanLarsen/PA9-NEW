#pragma once
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Player.hpp"
#include "Animation.hpp"

int main()
{
    sf::Clock deltaClock;
    float initial = 0.0f;

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

        if (!player.isJumping())
        {
            player.checkGravity(platforms);
        }
        
        
        // this ensures that only one jump is preformed even if the user holds down the space bar
        bool jumpNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

        if (jumpNow && !prevJump && !player.isJumping())
        {
            player.setJumping(true);
            // we can mess with setting the velocity depending on how high we want to jump
            player.setVelocityY(-5.0f);
            initial = player.getPositionY();
        }

        prevJump = jumpNow;

        //initiates the jump
        if (player.isJumping())
        {
            player.jump();
        }


        //moniters if the player is at the maximum jump height
        if (player.isJumping() && player.getPositionY() <= initial - 200.0f)
        {
            player.setVelocityY(0.0f);
            player.setJumping(false);
        }

        // checks if the player has completed the jumping arc
        if (player.isJumping() && player.getVelocityY() >= 0)
        {
            player.setVelocityY(0.0f);
            player.setJumping(false);
        }


        // left movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.moveRight();

        }

        

        // right movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player.moveLeft();

        }


        window.clear();
        test.setScale(0.2, 0.2);
        test.drawEntity(window);
        window.display();

    }
}