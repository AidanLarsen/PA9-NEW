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
    sf::Clock deltaClock;
    sf::RenderWindow window(sf::VideoMode({ 1536u, 1024u }), "SFML works!");

    Backdrop backdrop("Backdrop1.png", "Ground.png");

    GroundEnemy testEnemy("GroundEnemy.png", 100, 100, 500, 0, 0, 330, 460);

    FlyingEnemy testEnemy2("EnemySky.png", 500, 500, 500, 0, 0, 400, 420);

    std::vector<GameObject> platforms;
    platforms.emplace_back(sf::Vector2f(1000, 40), sf::Vector2f(0, 760), sf::Color::Green);
    platforms.emplace_back(sf::Vector2f(120, 50), sf::Vector2f(300, 520), sf::Color::Green);

    std::vector<GameObject> sideColPlatforms;
    sideColPlatforms.emplace_back(sf::Vector2f(120, 45), sf::Vector2f(300, 525), sf::Color::Red);
    sideColPlatforms.emplace_back(sf::Vector2f(.1, 800), sf::Vector2f(-1, 0), sf::Color::Green);
    sideColPlatforms.emplace_back(sf::Vector2f(.1, 800), sf::Vector2f(1000, 0), sf::Color::Green);
    Player player("Sprite.png", 250, 250, 0, 0, 273, 409);
    Animation animationManager;
    // checks if jump was initiated previously
    bool prevJump = false;
    bool allowedToJump = false;

    player.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
    player.getSpriteVectors()[1] = sf::Vector2i{ 258u, 0u };
    player.getSpriteVectors()[2] = sf::Vector2i{ 1380u, 0u };
    player.getSpriteVectors()[3] = sf::Vector2i{ 860u, 0u };

    testEnemy.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
    testEnemy.getSpriteVectors()[1] = sf::Vector2i{ 300u, 0u };
    testEnemy.getSpriteVectors()[2] = sf::Vector2i{ 940u, 0u };
    testEnemy.getSpriteVectors()[3] = sf::Vector2i{ 1230u, 0u };

    testEnemy2.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
    testEnemy2.getSpriteVectors()[1] = sf::Vector2i{ 900u, 0u };
    testEnemy2.getSpriteVectors()[2] = sf::Vector2i{ 1425u, 0u };
    testEnemy2.getSpriteVectors()[3] = sf::Vector2i{ 2300u, 0u };

    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();

        allowedToJump = false;
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
            animationManager.animate(player, Direction::Up, deltaTime);
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
            animationManager.animate(player, Direction::Right, deltaTime);
            player.moveRight();
            player.checkRightCol(sideColPlatforms);
        }



        // right movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            animationManager.animate(player, Direction::Left, deltaTime);
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

        testEnemy.setScale(0.2, 0.2);

        testEnemy2.setScale(0.9, 0.9);

        testEnemy.update();
        testEnemy2.update();
        animationManager.animate(testEnemy, testEnemy.getDirection(), deltaTime);
        animationManager.animate(testEnemy2, testEnemy2.getDirection(), deltaTime);
     
        testEnemy.drawEntity(window);

        testEnemy2.drawEntity(window);
        
        player.drawEntity(window);
        window.display();

    }
}