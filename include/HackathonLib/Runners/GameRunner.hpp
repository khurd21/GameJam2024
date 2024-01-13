#include <HackathonLib/Runners/IRunner.hpp>
#include <HackathonLib/Objects/Character.hpp>
#include <HackathonLib/Objects/Wall.hpp>

namespace sf {
class RenderWindow;
} // namespace sf

class GameRunner : public IRunner {
public:
    GameRunner(sf::RenderWindow* window);
    virtual void run() override;

private:

    sf::RenderWindow* m_window;
    Character m_character{800.0f, 300.0f, 30.0f};
    Wall m_wall{500.0f, 500.0f, 200.0f, 100.0f};
};