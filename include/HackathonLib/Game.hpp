#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <HackathonLib/Runners/IRunner.hpp>

#include <memory>

class Game {
public:

    Game();
    void run();

private:
    std::unique_ptr<sf::RenderWindow> m_window = nullptr;
    std::vector<sf::FloatRect> menu_options_bounds; // a containing Global Bound Float Rects of Menu Option Positions

    sf::Texture background_texture; // Background texture (image)
    sf::Sprite background_sprite;   // Background Sprite

    sf::Texture person_texture; // Person texture (image)
    sf::Sprite person_sprite;   // Person Sprite
    sf::Music m_backgroundMusic;

    void drawMenu();   // method to handle the creation a drawing of the menu
}; // class Game

#endif // GAME_HPP