#pragma once

#include "Entity.hpp"
#include "Object.hpp"

class Player : public Entity
{
public:
	Player() = default;
	explicit Player(const std::string imgDirectory)
		: Entity(imgDirectory), velocityY(0.0f), jumping(false)
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

	

	void checkGravity(std::vector<GameObject> objects);
	void moveRight();
	void moveLeft();
	void jump();
	//void jump();

private:
	bool jumping;
	float velocityY;
	
};