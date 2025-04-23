#pragma once
#include "Entity.hpp"
#include "Object.hpp"
#include "FlyingEnemy.hpp"
#include "GroundEnemy.hpp"

class Player : public Entity
{
public:
	Player() = default;
	explicit Player(const std::string imgDirectory, float x, float y)
		: Entity(imgDirectory, x, y), velocityY(0.0f), jumping(false), health(3), coins(0)
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
	//void jump();

	int getHealth() const {
		return health;
	}

private:

	int health;
	int coins;
	bool jumping;
	float velocityY;
	
};