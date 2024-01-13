#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <HackathonLib/Objects/IObject.hpp>
#include <SFML/Graphics/CircleShape.hpp>

constexpr inline float defaultTokenSpeed{ 400.0f };
constexpr inline float defaultFadeTimer{ 1.5f };

class Token : public IObject {
public:
    Token(float movementSpeed = defaultTokenSpeed);
    virtual void update(float deltaTime) override;
    virtual void handleInput(sf::RenderWindow& window) override;
    virtual sf::FloatRect getBoundingBox() const override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual bool isCollision(const sf::FloatRect& shape) const override;
    virtual void handleCollision(const sf::FloatRect& shape, Type type) override;

    void setRandomPosition(const sf::Vector2u& window);
    bool readyForRemoval() const;
    void reset();

private:
    sf::CircleShape m_shape;
    float m_movementSpeed{ defaultTokenSpeed };
    float m_fadeTimer{ defaultFadeTimer };
    bool m_isFading{ false };
    bool m_readyForRemoval{ false };
}; // class Token

#endif // TOKEN_HPP