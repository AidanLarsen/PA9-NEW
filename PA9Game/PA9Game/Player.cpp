#include "Player.hpp"




void Player::checkGravity(std::vector<GameObject> objects)
{

   
	
	bool onGround = false;

	for (const auto& object : objects)
	{
		if (pSprite->getGlobalBounds().findIntersection(object.shape.getGlobalBounds()))
		{
			onGround = true;
			break;
		}
	}

	if (!onGround)
	{
		pSprite->move({ 0, 0.15f }); // Apply gravity
	}
	
}

void Player::moveRight()
{
	pSprite->move({ 0.1, 0 });
}

void Player::moveLeft()
{
	pSprite->move({ -.1, 0 });
}



void Player::jump()
{
	pSprite->move({ 0, velocityY });
	velocityY += .15;
}
