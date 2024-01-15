#include <vector>

#include <HackathonLib/Runners/IRunner.hpp>
#include <HackathonLib/Objects/Character.hpp>
#include <HackathonLib/Objects/Token.hpp>

namespace sf {
class RenderWindow;
} // namespace sf

class GameRunner : public IRunner {
public:
    GameRunner(sf::RenderWindow* window);
    virtual void run() override;

private:

    void setup();

    sf::RenderWindow* m_window;
    sf::Font m_font;
    sf::Text m_currentScore;
    sf::Text m_timeLeftSeconds;
    sf::Clock m_clock;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundImage;
    Character m_character{800.0f, 200.0f, 100.0f};
    std::vector<Token> m_birds;
    std::vector<Token> m_clock5;
    std::vector<Token> m_clock10;
    std::vector<Token> m_clouds;
    std::vector<Token> m_coins1;
    std::vector<Token> m_coins2;

    float m_updateInterval{ 1.0f };
    int m_score{};
    int m_timeSeconds{ 7 };
};