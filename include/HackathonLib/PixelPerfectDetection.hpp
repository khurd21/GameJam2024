#ifndef PIXEL_PERFECT_DETECTION_HPP
#define PIXEL_PERFECT_DETECTION_HPP

#include <SFML/Graphics.hpp>

bool pixelPerfectCollision(const sf::Image& mask1, const sf::Vector2f& position1,
                           const sf::Image& mask2, const sf::Vector2f& position2);

bool getIntersection(const sf::Image& mask1, const sf::Vector2f& position1,
                     const sf::Image& mask2, const sf::Vector2f& position2,
                     sf::IntRect& intersection);

bool pixelPerfectCollision(const sf::Image& mask, const sf::Vector2f& position,
                           const sf::FloatRect& boundingBox);

bool getIntersection(const sf::Image& mask, const sf::Vector2f& position,
                     const sf::FloatRect& boundingBox, sf::IntRect& intersection);

#endif // PIXEL_PERFECT_DETECTION_HPP