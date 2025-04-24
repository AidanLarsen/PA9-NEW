#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <map>

/*
The animation class handles all the animation side stuff.
The general idea is to use a spritesheet, and have an intRect capture different positions within that spritesheet
in order to update the sprite's texture to have an animated effect.
*/

enum class Direction { Up, Down, Left, Right };


class Animation
{
public:
	Animation() = default;
	void animate(Entity& entity, Direction direction, sf::Time& deltaTime);
	std::map<Entity*, float> animationTimers;
};