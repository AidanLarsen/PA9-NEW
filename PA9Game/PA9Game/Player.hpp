#pragma once
#include "Entity.hpp"
#include "Object.hpp"
#include "FlyingEnemy.hpp"
#include "GroundEnemy.hpp"
#include "flag.hpp"

class Player : public Entity
{
public:
	Player() = default;
	explicit Player(const sf::Texture& texture, float x, float y, unsigned rectX, unsigned rectY, unsigned width, unsigned height)
		: Entity(texture, x, y, rectX, rectY, width, height), velocityY(0.0f), jumping(false), health(3), coins(0)
	{

	}

	float getPositionY()
	{
		return pSprite->getPosition().y;
	}

	float getPositionX()
	{
		return pSprite->getPosition().x;
	}

	bool isJumping()
	{
		return jumping;
	}
	void setJumping(bool jump)
	{
		jumping = jump;
	}

	float getVelocityY()
	{
		return velocityY;
	}
	void setVelocityY(float newVelocity)
	{
		velocityY = newVelocity;
	}

	bool isGrounded(std::vector<GameObject> objects)
	{
		for (const auto& object : objects)
		{
			if (pSprite->getGlobalBounds().findIntersection(object.shape.getGlobalBounds()))
			{
				return true;
			}
		}
		return false;
	}

	void collidedWithFlyingEnemy(std::vector<FlyingEnemy>& enemies);
	void collidedWithGroundEnemy(std::vector<GroundEnemy>& enemies);
	void checkLeftCol(std::vector<GameObject> objects);
	void checkRightCol(std::vector<GameObject> objects);
	bool checkTopCol(std::vector<GameObject> objects);
	void checkGravity(std::vector<GameObject> objects);
	void moveRight();
	void moveLeft();
	void moveDown();
	void jump();
	void collidingWithGoal(Flag flag)
	{
		if (pSprite->getGlobalBounds().findIntersection(flag.getSprite()->getGlobalBounds()))
		{
			sf::Vector2f initVec(startingPoint.first, startingPoint.second);
			pSprite->setPosition(initVec);
		}
	}
	

	int getHealth() const {
		return health;
	}

private:

	int health;
	int coins;
	bool jumping;
	float velocityY;
	
};