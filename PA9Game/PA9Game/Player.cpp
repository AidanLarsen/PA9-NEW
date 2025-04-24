#include "Player.hpp"


// both of these check for collisions with enemies
void Player::collidedWithFlyingEnemy(std::vector<FlyingEnemy>& enemies)
{
	for (const auto& enemy : enemies)
	{
		if (pSprite->getGlobalBounds().findIntersection(enemy.getGlobalBoundsofEnemy()))
		{

			sf::Vector2f initVec(startingPoint.first, startingPoint.second);
			pSprite->setPosition(initVec);

		}
	}
	return;
}

void Player::collidedWithGroundEnemy(std::vector<GroundEnemy>& enemies)
{
	for (const auto& enemy : enemies)
	{
		if (pSprite->getGlobalBounds().findIntersection(enemy.getGlobalBoundsofGroundEnemy()))
		{

			sf::Vector2f initVec(startingPoint.first, startingPoint.second);
			pSprite->setPosition(initVec);

		}
	}
	return;
}

//checks if the player ran into the platforms and applies collision
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

//checks and applies gravity
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
		pSprite->move({ 0, 0.25f }); 
	}
	
}

// player movement
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


// is the player jump, continuously appling a change to the velocity
void Player::jump()
{
	pSprite->move({ 0, velocityY });
	velocityY += .15;
}
