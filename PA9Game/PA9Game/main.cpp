#pragma once
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Entity.hpp"
#include "Backdrop.hpp"
#include "Player.hpp"
#include "Animation.hpp"
#include "GroundEnemy.hpp"
#include "FlyingEnemy.hpp"
#include "flag.hpp"
#include <vector>


int main()
{
    sf::View view;
    view.setSize({ 600, 600 });
    sf::Vector2i stanced = { 0u, 0u };
    float initial = 0.0f;
    sf::Clock deltaClock;

    sf::RenderWindow window(sf::VideoMode({ 1536u, 1024u }), "Platformer");

    Backdrop backdrop("Backdrop1.png", "Ground.png");

    sf::Texture groundEnemyTex;
    groundEnemyTex.loadFromFile("GroundEnemy.png");
    std::vector<GroundEnemy> groundEnemies;
    // first floor
    groundEnemies.emplace_back(groundEnemyTex, 175, 820, 350, 0, 0, 330, 460);
    //second floor
    groundEnemies.emplace_back(groundEnemyTex, 475, 455, 300, 0, 0, 330, 460);
    groundEnemies.emplace_back(groundEnemyTex, 545, 305, 200, 0, 0, 330, 460);


    sf::Texture flyingEnemyTex;
    flyingEnemyTex.loadFromFile("EnemySky.png");
    std::vector<FlyingEnemy> flyingEnemies;
    //first floor
    flyingEnemies.emplace_back(flyingEnemyTex, 500, 650, 300, 0, 0, 400, 420);
    //second floor
    flyingEnemies.emplace_back(flyingEnemyTex, 580, 200, 600, 0, 0, 400, 420);



    std::vector<GameObject> platforms;
    //floor
    platforms.emplace_back(sf::Vector2f(1500, 40), sf::Vector2f(0, 900), sf::Color::Transparent);
    // floor 1 platform
    platforms.emplace_back(sf::Vector2f(200, 30), sf::Vector2f(300, 755), sf::Color::Green);
    // right rising platforms
    platforms.emplace_back(sf::Vector2f(250, 30), sf::Vector2f(1300, 725), sf::Color::Green);
    platforms.emplace_back(sf::Vector2f(125, 30), sf::Vector2f(1100, 625), sf::Color::Green);

    // second floor
    platforms.emplace_back(sf::Vector2f(1000, 40), sf::Vector2f(0, 525), sf::Color::Green);
    // second floor platforms
    platforms.emplace_back(sf::Vector2f(400, 40), sf::Vector2f(500, 375), sf::Color::Green);
    // second floor rising platforms
    platforms.emplace_back(sf::Vector2f(100, 40), sf::Vector2f(310, 375), sf::Color::Green);
    platforms.emplace_back(sf::Vector2f(100, 40), sf::Vector2f(175, 300), sf::Color::Green);

    // goal platform
    platforms.emplace_back(sf::Vector2f(100, 40), sf::Vector2f(20, 175), sf::Color::Green);

    std::vector<GameObject> sideColPlatforms;
    // floor 1 platform
    sideColPlatforms.emplace_back(sf::Vector2f(200, 25), sf::Vector2f(300, 760), sf::Color::Red);
    //right rising platforms
    sideColPlatforms.emplace_back(sf::Vector2f(250, 25), sf::Vector2f(1300, 730), sf::Color::Red);
    sideColPlatforms.emplace_back(sf::Vector2f(125, 25), sf::Vector2f(1100, 630), sf::Color::Red);
    // second floor
    sideColPlatforms.emplace_back(sf::Vector2f(1000, 35), sf::Vector2f(0, 530), sf::Color::Red);
    // second floor platforms
    sideColPlatforms.emplace_back(sf::Vector2f(400, 35), sf::Vector2f(500, 380), sf::Color::Red);
    // second floor rising platforms
    sideColPlatforms.emplace_back(sf::Vector2f(100, 35), sf::Vector2f(310, 380), sf::Color::Red);
    sideColPlatforms.emplace_back(sf::Vector2f(100, 35), sf::Vector2f(175, 305), sf::Color::Red);

    // goal platform
    sideColPlatforms.emplace_back(sf::Vector2f(100, 35), sf::Vector2f(20, 180), sf::Color::Red);


    //Border walls
    sideColPlatforms.emplace_back(sf::Vector2f(.1, 1000), sf::Vector2f(-1, 0), sf::Color::Green);
    sideColPlatforms.emplace_back(sf::Vector2f(.1, 1000), sf::Vector2f(1530, 0), sf::Color::Green);

    sf::Texture playerTex;
    playerTex.loadFromFile("Sprite.png");
    Player player(playerTex, 0, 750, 0, 0, 273, 409);

    sf::Texture flagTex;
    flagTex.loadFromFile("goalFlag.png");
    Flag flag(flagTex, 30, 120, 0, 0, 120, 120);

    Animation animationManager;
    // checks if jump was initiated previously
    bool prevJump = false;
    bool allowedToJump = false;

    player.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
    player.getSpriteVectors()[1] = sf::Vector2i{ 258u, 0u };
    player.getSpriteVectors()[2] = sf::Vector2i{ 1380u, 0u };
    player.getSpriteVectors()[3] = sf::Vector2i{ 860u, 0u };

    for (auto& flyingEnemy : flyingEnemies)
    {
        flyingEnemy.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
        flyingEnemy.getSpriteVectors()[1] = sf::Vector2i{ 900u, 0u };
        flyingEnemy.getSpriteVectors()[2] = sf::Vector2i{ 1425u, 0u };
        flyingEnemy.getSpriteVectors()[3] = sf::Vector2i{ 2300u, 0u };
    }
    

    for (auto& groundEnemy : groundEnemies)
    {
        groundEnemy.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
        groundEnemy.getSpriteVectors()[1] = sf::Vector2i{ 300u, 0u };
        groundEnemy.getSpriteVectors()[2] = sf::Vector2i{ 940u, 0u };
        groundEnemy.getSpriteVectors()[3] = sf::Vector2i{ 1230u, 0u };
    }
    

    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();

        allowedToJump = false;
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!player.isGrounded(platforms))
        {
            player.checkGravity(platforms);
        }

        player.collidingWithGoal(flag);

        player.collidedWithGroundEnemy(groundEnemies);

        player.collidedWithFlyingEnemy(flyingEnemies);

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
            animationManager.animate(player, Direction::Up, deltaTime);
            player.setJumping(true);
            // we can mess with setting the velocity depending on how high we want to jump
            player.setVelocityY(-10.0f);
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

        for (auto& groundEnemy : groundEnemies)
        {
            groundEnemy.setScale(.15, .15);
        }
        for (auto& groundEnemy : groundEnemies)
        {
            groundEnemy.drawEntity(window);
            
        }

        for (auto& flyingEnemy : flyingEnemies)
        {
            flyingEnemy.setScale(0.2, 0.2);
        }
        

        for (auto& groundEnemy : groundEnemies)
        {
            groundEnemy.update();
        }
      
        for (auto& flyingEnemy : flyingEnemies)
        {
            animationManager.animate(flyingEnemy, flyingEnemy.getDirection(), deltaTime);

        }
        for (auto& groundEnemy : groundEnemies)
        {
            animationManager.animate(groundEnemy, groundEnemy.getDirection(), deltaTime);

        }
      
        for (auto& flyingEnemy : flyingEnemies)
        {
            flyingEnemy.update();
        }
        for (auto& flyingEnemy : flyingEnemies)
        {
            flyingEnemy.drawEntity(window);
        }

        //view.setCenter(player.getSprite()->getPosition());
        //window.setView(view);
        flag.setScale(.3, .3);

        flag.drawEntity(window);
        player.drawEntity(window);
        window.display();

    }
}