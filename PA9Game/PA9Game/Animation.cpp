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
	case (Direction::Right):
		if (deltaClock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (entity.getRect()->position == sf::Vector2i{ 365u, 512u })
			{
				entity.getRect()->position = sf::Vector2i{ 365u, 0u };
			}
			else
			{
				entity.getRect()->position = sf::Vector2i{ 365u, 512u };
			}
			entity.getSprite()->setTextureRect(*entity.getRect());
			deltaClock.restart();
		}
		break;
	}
}
