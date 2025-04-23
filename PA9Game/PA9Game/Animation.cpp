#include "Animation.hpp"

void Animation::animate(Entity& entity, Direction direction, sf::Clock& deltaClock)
{
	switch (direction)
	{
	case (Direction::Up):
		if (deltaClock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (entity.getRect()->position == sf::Vector2i{ 730u, 512u })
			{
				entity.getRect()->position = sf::Vector2i{ 0u, 0u };
			}
			else
			{
				entity.getRect()->position = sf::Vector2i{ 730u, 512u };
			}
			entity.getSprite()->setTextureRect(*entity.getRect());
			deltaClock.restart();
		}
		break;
	case (Direction::Left):
		if (deltaClock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (entity.getRect()->position == sf::Vector2i{ 860u, 0u }) //end pos
			{
				entity.getRect()->position = { 1380u, 0u }; //start pos
			}
			else
			{
				entity.getRect()->position = sf::Vector2i{ 860u, 0u }; // end pos
			}
			entity.getSprite()->setTextureRect(*entity.getRect());
			deltaClock.restart();
		}
		break;
	case (Direction::Right):
		if (deltaClock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (entity.getRect()->position == sf::Vector2i{ 265u, 0u })
			{
				entity.getRect()->position.x = 0u;
			}
			else
			{
				entity.getRect()->position.y = 0u;
				entity.getRect()->position.x = 265u;
			}
			entity.getSprite()->setTextureRect(*entity.getRect());
			deltaClock.restart();
		}
		break;
	}
}