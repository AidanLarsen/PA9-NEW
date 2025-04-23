#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>

class GameObject {
public:
    sf::RectangleShape shape;
    GameObject(sf::Vector2f newSize, sf::Vector2f newPos, sf::Color newColor) {
        shape.setPosition(newPos);
        shape.setSize(newSize);
        shape.setFillColor(newColor);

    }
private:
    
};