#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <map>

enum class Direction { Up, Down, Left, Right };


class Animation
{
public:
	Animation() = default;
	void animate(Entity& entity, Direction direction, sf::Time& deltaTime);
	std::map<Entity*, float> animationTimers;
};

//class EntityPosition
//{
//public:
//	sf::Vector2i playerInitialLeft = { 1380u, 0u };
//	sf::Vector2i playerEndLeft = { 860u, 0u };
//};