#include <HackathonLib/Runners/GameRunner.hpp>
#include <HackathonLib/Textures.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

namespace {

template <typename Tokens>
void updateToken(Tokens&& tokens, Type type, const sf::FloatRect& boundingBox, float deltaTime) {
    for (auto& token : tokens) {
        token.update(deltaTime);
        token.handleCollision(boundingBox, type);
        if (token.readyForRemoval()) {
            token.reset();
            token.setRandomPosition();
        }
    }
}

template <typename Tokens>
std::pair<int, int> updateScore(Tokens&& tokens, Type type, const sf::FloatRect& boundingBox) {
    std::pair<int, int> scoreTime;
    for (auto& token : tokens) {
        if (token.isCollision(boundingBox) && !token.getMark()) {
            token.setMark(true);
            if (Type::Bird == type) {
                scoreTime.second = -1'000'000;
            }
            else if (Type::Clock10 == type) {
                scoreTime.second += 10;
            }
            else if (Type::Clock5 == type) {
                scoreTime.second += 5;
            }
            else if (Type::Coin1 == type) {
                scoreTime.first += 1;
            }
            else if (Type::Coin2 == type) {
                scoreTime.first += 2;
            }
            else if (Type::Cloud == type) {
                scoreTime.first -= 5;
                scoreTime.second -= 10;
            }
        }
    }
    return scoreTime;
}

template <typename Items>
void draw(Items&& items, sf::RenderWindow* window) {
    if (!window) {
        return;
    }

    for (auto& item : items) {
        item.draw(*window); 
    }
}

} // namespace

GameRunner::GameRunner(sf::RenderWindow* window) : m_window(window) {

    m_font.loadFromFile("resources/fonts/ice-season.ttf");
    m_currentScore.setPosition(m_window->getSize().x - 200, 50);
    m_currentScore.setCharacterSize(24);
    m_currentScore.setFillColor(sf::Color::White);
    m_currentScore.setFont(m_font);
    m_currentScore.setString("Score: " + std::to_string(m_score));

    m_timeLeftSeconds.setPosition(m_window->getSize().x - 200, 80);
    m_timeLeftSeconds.setCharacterSize(24);
    m_timeLeftSeconds.setFillColor(sf::Color::White);
    m_timeLeftSeconds.setFont(m_font);
    m_timeLeftSeconds.setString("Time: " + std::to_string(m_timeSeconds));

    for (int i = 0; i < 3; ++i) {
        m_birds.emplace_back(birdTexture, 325.0f);
    }

    for (int i = 0; i < 2; ++i) {
        m_clouds.emplace_back(cloudTexture, 1000.0f);
    }

    for (int i = 0; i < 4; ++i) {
        m_clock5.emplace_back(time5Texture, 400.0f);
    }

    for (int i = 0; i < 1; ++i) {
        m_clock10.emplace_back(time10Texture, 150.0f);
    }

    for (int i = 0; i < 10; ++i) {
        m_coins1.emplace_back(coin1Texture, 115.0f);
    }

    for (int i = 0; i < 5; ++i) {
        m_coins2.emplace_back(coin2Texture, 135.0f);
    }
}

void GameRunner::run() {
    sf::Clock clock;
    float deltaTime{ clock.restart().asSeconds() };

    while (m_window->isOpen()) {
        for (auto event = sf::Event{}; m_window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                m_window->close();
            }
        }

        deltaTime = clock.restart().asSeconds();

        if (m_clock.getElapsedTime().asSeconds() >= m_updateInterval) {
            m_timeSeconds--;  // Decrement time every second
            m_clock.restart();  // Restart the timer
        }

        m_window->clear();
        m_character.handleInput(*m_window);
        m_character.update(deltaTime);

        const auto& boundingBox{ m_character.getBoundingBox() };
        updateToken(m_birds, Type::Bird, boundingBox, deltaTime);
        updateToken(m_clouds, Type::Cloud, boundingBox, deltaTime);
        updateToken(m_clock5, Type::Clock5, boundingBox, deltaTime);
        updateToken(m_clock10, Type::Clock10, boundingBox, deltaTime);
        updateToken(m_coins1, Type::Coin1, boundingBox, deltaTime);
        updateToken(m_coins2, Type::Coin2, boundingBox, deltaTime);

        std::vector<std::pair<int, int>> scoreTimes;
        scoreTimes.emplace_back(updateScore(m_birds, Type::Bird, boundingBox));
        scoreTimes.emplace_back(updateScore(m_clouds, Type::Cloud, boundingBox));
        scoreTimes.emplace_back(updateScore(m_clock5, Type::Clock5, boundingBox));
        scoreTimes.emplace_back(updateScore(m_clock10, Type::Clock10, boundingBox));
        scoreTimes.emplace_back(updateScore(m_coins1, Type::Coin1, boundingBox));
        scoreTimes.emplace_back(updateScore(m_coins2, Type::Coin2, boundingBox));

        bool isDead{ false };
        for (const auto [score, time] : scoreTimes) {
            if (time < -1'000) {
                isDead = true;
                continue;
            }
            m_timeSeconds += time;
            m_score += score;
        }

        if (isDead || m_timeSeconds < 0) {
            // Record the score
            return;
        }

        m_currentScore.setString("Score: " + std::to_string(m_score));
        m_timeLeftSeconds.setString("Time: " + std::to_string(m_timeSeconds));

        draw(m_birds, m_window);
        draw(m_clouds, m_window);
        draw(m_clock5, m_window);
        draw(m_clock10, m_window);
        draw(m_coins1, m_window);
        draw(m_coins2, m_window);

        m_window->draw(m_currentScore);
        m_window->draw(m_timeLeftSeconds);
        m_character.draw(*m_window);
        m_window->display();
    }

}