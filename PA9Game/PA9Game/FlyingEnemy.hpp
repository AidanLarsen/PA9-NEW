#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <utility>

class FlyingEnemy : public Entity {
public:

	FlyingEnemy(const std::string imgDirectory, float x, float y, float distance) : Entity(imgDirectory, x, y)
	{

		leftBound = x;

		rightBound = x + distance;

		velocity = { 0.2f, 0.f };

	}

	sf::FloatRect getGlobalBoundsofEnemy() const{

		return pSprite->getGlobalBounds();

	}

	void update();

private:

	sf::Vector2f velocity;
	float leftBound, rightBound;

};