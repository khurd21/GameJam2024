#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <HackathonLib/Objects/IObject.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <HackathonLib/PixelPerfectDetection.hpp>

constexpr inline float defaultTokenSpeed{ 400.0f };
constexpr inline float defaultFadeTimer{ 1.5f };

class Token : public IObject {
public:
    Token(const sf::Texture& texture, float movementSpeed = defaultTokenSpeed);
    virtual void update(float deltaTime) override;
    virtual void handleInput(sf::RenderWindow& window) override;
    virtual sf::FloatRect getBoundingBox() const override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual bool isCollision(const sf::FloatRect& shape) const override;
    virtual void handleCollision(const sf::FloatRect& shape, Type type) override;

    virtual void setRandomPosition();
    virtual bool readyForRemoval();
    virtual void reset();
    virtual bool getMark() {
        return m_mark;
    }

    virtual void setMark(bool mark) {
        m_mark = mark;
    }

protected:
    sf::CircleShape m_shape;
    sf::CircleShape m_collisionShape;
    sf::Texture m_texture;
    sf::Color m_originalColor;

    float m_movementSpeed{ defaultTokenSpeed };
    float m_defaultMovementSpeed{ defaultTokenSpeed };
    float m_fadeTimer{ defaultFadeTimer };
    float m_fadeDuration{ defaultFadeTimer };
    bool m_isFading{ false };
    bool m_readyForRemoval{ false };
    bool m_mark{ false };
    bool m_isLaunched{ false };
}; // class Token

#endif // TOKEN_HPP