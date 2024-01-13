#ifndef IOBJECT_HPP
#define IOBJECT_HPP

#include <SFML/Graphics.hpp>
#include <HackathonLib/Type.hpp>

class IObject {
public:
    virtual ~IObject() = default;

    virtual void update(float deltaTime) = 0;
    virtual void handleInput(sf::RenderWindow& window) = 0;
    virtual sf::FloatRect getBoundingBox() const = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;

    virtual bool isCollision(const sf::FloatRect& shape) const = 0;
    virtual void handleCollision(const sf::FloatRect& shape, enum Type) = 0;
};

#endif // IOBJECT_HPP