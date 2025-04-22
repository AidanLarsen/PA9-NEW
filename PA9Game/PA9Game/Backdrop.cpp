#include "Backdrop.hpp"

Backdrop::Backdrop(const std::string imgDirectory, const std::string imgDirectory2)
{
	if (!backdropTexture.loadFromFile(imgDirectory) || !groundTexture.loadFromFile(imgDirectory2)) {

		std::cerr << "Error\nCould not load texture from directory.\n";

	}
	else {

		bSprite.emplace(backdropTexture);
		gSprite.emplace(groundTexture);
		
		gSprite->setPosition({ 0u, 650u });
	}
}

void Backdrop::drawBackdrop(sf::RenderWindow& window)
{
	if (bSprite) {

		window.draw(*bSprite);
		window.draw(*gSprite);
	}
}

//void Backdrop::animateBackdrop()
//{
//	const int frameWidth = 1365;
//	const int maxFrames = 3;
//	rect.position.x += frameWidth;
//	if (rect.position.x >= frameWidth * maxFrames)
//	{
//		rect.position.x = 0u;
//	}
//	
//	bSprite->setTextureRect(rect);
//}

void Backdrop::setPosition(float x, float y)
{
	if (bSprite)
	{
		bSprite->setPosition({x, y});
	}
}
