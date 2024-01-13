#ifndef WALL_HPP
#define WALL_HPP

#include <HackathonLib/Objects/IObject.hpp>
#include <SFML/Graphics.hpp>

enum class Type;

class Wall : public IObject {
public:
    Wall(float x, float y, float width, float height);
    virtual void update(float deltaTime) override;
    virtual void handleInput(sf::RenderWindow& window) override;
    virtual sf::FloatRect getBoundingBox() const override;
    virtual void draw(sf::RenderWindow& window) const override;

    virtual bool isCollision(const sf::FloatRect& shape) const override;
    virtual void handleCollision(const sf::FloatRect& shape, enum Type) override;

private:
    sf::RectangleShape m_shape;

}; // class Wall

#endif  // WALL_HPP