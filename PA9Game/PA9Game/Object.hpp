#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>

class GameObject {
public:
    sf::RectangleShape shape;
    GameObject(sf::Vector2f newSize, sf::Vector2f newPos, const std::string imgDirectory) {
        shape.setPosition(newPos);
        shape.setSize(newSize);
        if (!pTexture.loadFromFile(imgDirectory)) {
            std::cerr << "Error\nCould not load image from directory.\n";
            return;
        }
        pSprite.emplace(pTexture);
    }


private:
    sf::Texture pTexture;
    std::optional<sf::Sprite> pSprite;
};