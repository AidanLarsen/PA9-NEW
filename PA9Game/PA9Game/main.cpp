#pragma once
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Entity.hpp"
#include "Backdrop.hpp"
#include "Player.hpp"
#include "Animation.hpp"
#include "GroundEnemy.hpp"
#include "FlyingEnemy.hpp"

int main()
{

    float initial = 0.0f;


    sf::RenderWindow window(sf::VideoMode({ 1536u, 1024u }), "SFML works!");

    const std::string platformImg = "platform.png";
    const std::string character = "Sprite.png";
    const std::string character2 = "Lebron.png";
    Backdrop backdrop("Backdrop1.png", "Ground.png");

    std::vector<GroundEnemy> groundEnemies;
    groundEnemies.emplace_back(character, 100, 100, 500);
    
    std::vector<FlyingEnemy> flyingEnemies;
    flyingEnemies.emplace_back(character2, 500, 500, 500);
   

    std::vector<GameObject> platforms;
    platforms.emplace_back(sf::Vector2f(10000, 400), sf::Vector2f(0, 760), platformImg);
    platforms.emplace_back(sf::Vector2f(120, 50), sf::Vector2f(300, 520), platformImg);

    std::vector<GameObject> sideColPlatforms;
    sideColPlatforms.emplace_back(sf::Vector2f(120, 45), sf::Vector2f(300, 525), platformImg);
    sideColPlatforms.emplace_back(sf::Vector2f(.1, 800), sf::Vector2f(-1, 0), platformImg);
    sideColPlatforms.emplace_back(sf::Vector2f(.1, 800), sf::Vector2f(1000, 0), platformImg);
    Player player(character, 250, 250);

    // checks if jump was initiated previously
    bool prevJump = false;


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!player.isGrounded(platforms))
        {
            player.checkGravity(platforms);
        }


        //moniters if the player is at the maximum jump height
        if (player.isJumping() && player.getPositionY() <= initial - 200.0f)
        {
            player.setVelocityY(0.0f);
            if (player.isGrounded(platforms))
            {
                player.setJumping(false);
            }
        }

        // checks if the player has completed the jumping arc
        if (player.isJumping() && player.getVelocityY() >= 0)
        {
            player.setVelocityY(0.0f);
            if (player.isGrounded(platforms))
            {
                player.setJumping(false);
            }

        }

        // this ensures that only one jump is preformed even if the user holds down the space bar
        bool jumpNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

        if (jumpNow && !prevJump && player.isGrounded(platforms)) //!player.isJumping())
        {
            player.setJumping(true);
            // we can mess with setting the velocity depending on how high we want to jump
            player.setVelocityY(-30.0f);
            initial = player.getPositionY();
        }

        prevJump = jumpNow;

        //initiates the jump
        if (player.isJumping())
        {
            player.jump();

        }


       



        // left movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            player.moveRight();
            player.checkRightCol(sideColPlatforms);
        }



        // right movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            player.moveLeft();
            player.checkLeftCol(sideColPlatforms);

        }

        if (player.checkTopCol(sideColPlatforms))
        {
            player.moveDown();
            player.setJumping(false);
        }

        window.clear();
        backdrop.drawBackdrop(window);
        player.setScale(0.2, 0.2);
        for (const auto& platform : platforms)
        {
            window.draw(platform.shape);
        }
        for (const auto& sideCol : sideColPlatforms)
        {
            window.draw(sideCol.shape);
        }

        for (auto& groundEnemy : groundEnemies)
        {
            groundEnemy.setScale(.2, .2);

        }
        for (auto& groundEnemy : groundEnemies)
        {
            groundEnemy.drawEntity(window);
            
        }

        for (auto& flyingEnemy : flyingEnemies)
        {
            flyingEnemy.setScale(0.9, 0.9);
        }
        

        for (auto& groundEnemy : groundEnemies)
        {
            groundEnemy.update();
        }
        
        for (auto& flyingEnemy : flyingEnemies)
        {
            flyingEnemy.update();
        }
        for (auto& flyingEnemy : flyingEnemies)
        {
            flyingEnemy.drawEntity(window);
        }

       // testEnemy.drawEntity(window);

        
        player.drawEntity(window);
        window.display();

    }
}