#pragma once
#include "Entity.hpp"

class Flag : public Entity
{
public:
	Flag() = default;
	explicit Flag(const sf::Texture& texture, float x, float y, unsigned rectX, unsigned rectY, unsigned width, unsigned height)
		: Entity(texture, x, y, rectX, rectY, width, height)
	{

	}
};