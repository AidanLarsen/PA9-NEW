#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <utility>
#include "Animation.hpp"

class FlyingEnemy : public Entity {
public:

	FlyingEnemy(sf::Texture& texture, float x, float y, float distance, unsigned rectX, unsigned rectY, unsigned width, unsigned height) : Entity(texture, x, y, rectX, rectY, width, height)
	{

		leftBound = x;

		rightBound = x + distance;

		velocity = { 0.2f, 0.f };

	}

	sf::FloatRect getGlobalBoundsofEnemy() const{

		return pSprite->getGlobalBounds();

	}

	void update();
	Direction getDirection() const
	{
		if (velocity.x > 0)
			return Direction::Right;
		else if (velocity.x < 0)
			return Direction::Left;
		else
			return Direction::Up;
	}
private:

	sf::Vector2f velocity;
	float leftBound, rightBound;

};