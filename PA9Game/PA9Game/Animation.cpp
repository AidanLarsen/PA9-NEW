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
		if (entity.getSprite()->getScale().x > 0)
			entity.getSprite()->setScale({ -1.f, 1.f });

		if (deltaClock.getElapsedTime().asSeconds() > 0.2f)
		{
			/*if (entity.getSprite()->getScale().x != -1.0f)
			{
				entity.getSprite()->setScale({ -1.0f, 1.0f });
			}*/

			if (entity.getRect()->position == sf::Vector2i{ 265u, 0u })
			{
				entity.getRect()->position.x = 0u;
				//= sf::Vector2i{ 530u, 0u };
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
	case (Direction::Right):
		if (deltaClock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (entity.getRect()->position == sf::Vector2i{ 265u, 0u })
			{
				entity.getRect()->position.x = 0u;
					//= sf::Vector2i{ 530u, 0u };
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