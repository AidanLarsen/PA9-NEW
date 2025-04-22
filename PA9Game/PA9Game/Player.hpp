#pragma once

#include "Entity.hpp"
#include "Object.hpp"

class Player : public Entity
{
public:
	Player() = default;
	explicit Player(const std::string imgDirectory, float x, float y)
		: Entity(imgDirectory, x, y), velocityY(0.0f), jumping(false)
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

	
	void checkLeftCol(std::vector<GameObject> objects);
	void checkRightCol(std::vector<GameObject> objects);
	bool checkTopCol(std::vector<GameObject> objects);
	void checkGravity(std::vector<GameObject> objects);
	void moveRight();
	void moveLeft();
	void moveDown();
	void jump();
	//void jump();

private:
	bool jumping;
	float velocityY;
	
};