#include "Player.hpp"




void Player::checkLeftCol(std::vector<GameObject> objects)
{
	for (const auto& object : objects)
	{
		if (pSprite->getGlobalBounds().findIntersection(object.shape.getGlobalBounds()))
		{
			pSprite->move({ 0.2, 0 });
		}
	}
}

void Player::checkRightCol(std::vector<GameObject> objects)
{
	for (const auto& object : objects)
	{
		if (pSprite->getGlobalBounds().findIntersection(object.shape.getGlobalBounds()))
		{
			pSprite->move({ -0.2, 0 });
		}
	}
}

bool Player::checkTopCol(std::vector<GameObject> objects)
{
	bool collided = false;
	for (const auto& object : objects)
	{
		if (pSprite->getGlobalBounds().findIntersection(object.shape.getGlobalBounds()))
		{
			collided = true;
		}
	}
	return collided;
}

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
		pSprite->move({ 0, 0.25f }); // Apply gravity
	}
	
}

void Player::moveRight()
{
	pSprite->move({ 0.2, 0 });
}

void Player::moveLeft()
{
	pSprite->move({ -0.2, 0 });
}

void Player::moveDown()
{
	pSprite->move({ 0, .1 });
}



void Player::jump()
{
	pSprite->move({ 0, velocityY });
	velocityY += .15;
}
