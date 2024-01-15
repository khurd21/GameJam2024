#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    virtual void unfreeze();
private:
    virtual bool isFrozen() const;

    virtual void freeze();

    sf::CircleShape m_shape;
    sf::RectangleShape m_collisionShape;
    sf::Texture m_texture;
    sf::Color m_originalColor;

    sf::SoundBuffer m_coin1Buffer;
    sf::SoundBuffer m_coin2Buffer;
    sf::SoundBuffer m_crowBuffer;
    sf::SoundBuffer m_freezingBuffer;
    sf::SoundBuffer m_clockBuffer;
    sf::Sound m_coin1Sound;
    sf::Sound m_coin2Sound;
    sf::Sound m_crowSound;
    sf::Sound m_freezingSound;
    sf::Sound m_clockSound;

    float m_movementSpeed{ 10.0f };
    bool m_isFrozen{ false };
    float m_freezeDuration{ 2.5f };
    float m_freezeTimer{ 0.0f };
};

#endif // CHARACTER_HPP