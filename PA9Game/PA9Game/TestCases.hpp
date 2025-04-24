#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GroundEnemy.hpp"
#include "Object.hpp"

bool gameLoopTest()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Game Loop Test");
	sf::Clock deltaClock;
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		window.clear(sf::Color::Blue);
		window.display();
        
		std::cout << "Game loop has been running for " << deltaClock.getElapsedTime().asSeconds() << " seconds." << std::endl;
	}
	std::cout << "Game loop test completed successfully!" << std::endl;
	return true;
}


bool testCreateCharacter()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Character Creation Test");
	// Load texture
	sf::Texture playerTex;
	if (!playerTex.loadFromFile("Sprite.png"))
	{
		std::cout << "Failed to load player texture!" << std::endl;
		return false;
	}
	Player player(playerTex, 100, 500, 0, 0, 273, 409);
	std::cout << "Player created successfully!" << std::endl;

	player.setScale(0.2f, 0.2f);
	std::cout << "Player scale set successfully!" << std::endl;
	player.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
	std::cout << "Player sprite vector 0 set successfully!" << std::endl;
	player.getSpriteVectors()[1] = sf::Vector2i{ 258u, 0u };
	std::cout << "Player sprite vector 1 set successfully!" << std::endl;
	player.getSpriteVectors()[2] = sf::Vector2i{ 1380u, 0u };
	std::cout << "Player sprite vector 2 set successfully!" << std::endl;
	player.getSpriteVectors()[3] = sf::Vector2i{ 860u, 0u };
	std::cout << "Player sprite vector 3 set successfully!" << std::endl;
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		window.clear();
		player.drawEntity(window);
		window.display();
	}
	std::cout << "Player drawn successfully!" << std::endl;
	return true;
}

bool testAnimate()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Animation test");

    // Load texture for enemy
    sf::Texture groundEnemyTex;
    if (!groundEnemyTex.loadFromFile("GroundEnemy.png"))
        return false;

    GroundEnemy groundEnemy(groundEnemyTex, 200, 455, 400, 0, 0, 330, 460);

    groundEnemy.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
    groundEnemy.getSpriteVectors()[1] = sf::Vector2i{ 300u, 0u };
    groundEnemy.getSpriteVectors()[2] = sf::Vector2i{ 940u, 0u };
    groundEnemy.getSpriteVectors()[3] = sf::Vector2i{ 1230u, 0u };

    sf::Clock deltaClock;
    Animation animationManager;

    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        groundEnemy.update();
        animationManager.animate(groundEnemy, groundEnemy.getDirection(), deltaTime);
        groundEnemy.setScale(0.20f, 0.20f);

        window.clear();
        groundEnemy.drawEntity(window);
        window.display();
    }
	std::cout << "Animation test completed successfully!" << std::endl;
    return true;
}

bool testPlayerMovement()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Player Movement Test");

    sf::Clock deltaClock;

    sf::Texture playerTex;
    if (!playerTex.loadFromFile("Sprite.png"))
    {
        std::cout << "Failed to load player texture!" << std::endl;
        return false;
    }

    Player player(playerTex, 100, 500, 0, 0, 273, 409);
    player.setScale(0.2f, 0.2f);

    player.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
    player.getSpriteVectors()[1] = sf::Vector2i{ 258u, 0u };
    player.getSpriteVectors()[2] = sf::Vector2i{ 1380u, 0u };
    player.getSpriteVectors()[3] = sf::Vector2i{ 860u, 0u };

    std::vector<GameObject> platforms;
    platforms.emplace_back(sf::Vector2f(800, 40), sf::Vector2f(0, 560), sf::Color::Green);

    bool prevJump = false;
    float jumpStartY = 0.0f;

    Animation animationManager;

    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Gravity
        if (!player.isGrounded(platforms))
        {
            player.checkGravity(platforms);
        }

        // Jump logic
        bool jumpNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
        if (jumpNow && !prevJump && player.isGrounded(platforms))
        {
			std::cout << "Entering jump logic\n";
            player.setJumping(true);
            player.setVelocityY(-10.0f); // Jump height
            jumpStartY = player.getPositionY();
        }
        prevJump = jumpNow;

        if (player.isJumping())
        {
			std::cout << "Jumping\n";
            player.jump();

            // Limit jump height
            if (player.getPositionY() <= jumpStartY - 200.0f || player.getVelocityY() >= 0)
            {
                player.setVelocityY(0.0f);
                if (player.isGrounded(platforms))
                    player.setJumping(false);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
			std::cout << "Moving right\n";
            player.moveRight();
            animationManager.animate(player, Direction::Right, deltaTime);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
			std::cout << "Moving left\n";
            player.moveLeft();
            animationManager.animate(player, Direction::Left, deltaTime);
        }

        window.clear();
        for (const auto& platform : platforms)
        {
            window.draw(platform.shape);
        }
        player.drawEntity(window);
        window.display();
    }
	std::cout << "Player movement test completed successfully!" << std::endl;
    return true;
}

bool testCollision()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Collision Test");
    sf::Clock deltaClock;

    // Load texture
    sf::Texture playerTex;
    if (!playerTex.loadFromFile("Sprite.png"))
        return false;

    Player player(playerTex, 100, 100, 0, 0, 273, 409);
    player.setScale(0.2f, 0.2f);

    player.getSpriteVectors()[0] = sf::Vector2i{ 0u, 0u };
    player.getSpriteVectors()[1] = sf::Vector2i{ 258u, 0u };
    player.getSpriteVectors()[2] = sf::Vector2i{ 1380u, 0u };
    player.getSpriteVectors()[3] = sf::Vector2i{ 860u, 0u };

    // Floating platform
    std::vector<GameObject> platforms;
    platforms.emplace_back(sf::Vector2f(200, 30), sf::Vector2f(300, 400), sf::Color::Blue);
    platforms.emplace_back(sf::Vector2f(800, 40), sf::Vector2f(0, 560), sf::Color::Green);


    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (!player.isGrounded(platforms))
            player.checkGravity(platforms);

        // Manual controls
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.moveLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.moveRight();

        window.clear();
        for (const auto& platform : platforms)
            window.draw(platform.shape);
        player.drawEntity(window);
        window.display();
    }
	std::cout << "Collision test completed successfully!" << std::endl;
    return true;
}
