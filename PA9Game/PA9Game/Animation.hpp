#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

enum class Direction { Up, Down, Left, Right };

class Animation
{
public:
	Animation() = default;
	void animate(Entity& entity, Direction direction, sf::Clock& deltaClock);
};