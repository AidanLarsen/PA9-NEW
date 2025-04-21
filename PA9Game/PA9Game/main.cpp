#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Player.hpp"



int main()
{
    
    float initial = 0.0f;

    sf::RenderWindow window (sf::VideoMode({ 1000, 800}), "SFML works!");

    const std::string character = "Sprite.png";

    std::vector<GameObject> platforms;
    platforms.emplace_back(sf::Vector2f( 1000, 40 ), sf::Vector2f(0, 760 ), sf::Color::Green);
    platforms.emplace_back(sf::Vector2f(120, 50), sf::Vector2f(300, 620), sf::Color::Green);
  
    Player player(character);

    // checks if jump was intitiated previously
    bool prevJump = false;

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
            player.setVelocityY(-30.0f);
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
        player.setScale(0.2, 0.2);
        for (const auto& platform : platforms)
        {
            window.draw(platform.shape);
        }
        player.drawEntity(window);
        window.display();

    }
}