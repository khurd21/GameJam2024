#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <HackathonLib/Objects/IObject.hpp>
#include <HackathonLib/Type.hpp>

class Character : public IObject {
public:
    Character(float x, float y, float radius);
    virtual void update(float deltaTime) override;
    virtual void handleInput(sf::RenderWindow& window) override;
    virtual sf::FloatRect getBoundingBox() const override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual bool isCollision(const sf::FloatRect& shape) const override;
    virtual void handleCollision(const sf::FloatRect& shape, Type type) override;

private:
    sf::CircleShape m_shape;
    float m_movementSpeed{ 10.0f };
};

#endif // CHARACTER_HPP