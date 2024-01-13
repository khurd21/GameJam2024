#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <HackathonLib/Character.hpp>
#include <HackathonLib/Wall.hpp>

#include <memory>

class Game {
public:

    Game();
    void run();

private:
    std::unique_ptr<sf::RenderWindow> m_window = nullptr;
    Character m_character{0.0f, 0.0f, 30.0f};
    Wall m_wall{500.0f, 500.0f, 200.0f, 100.0f};
    Wall m_wall2{1000, 1000, 20, 20};

}; // class Game

#endif // GAME_HPP