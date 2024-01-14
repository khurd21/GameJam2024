#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include <HackathonLib/Runners/IRunner.hpp>
#include <SFML/Graphics.hpp>

namespace sf {
class RenderWindow;
} // namespace sf

class InstructRunner : public IRunner {
public:
    InstructRunner(sf::RenderWindow* window);
    virtual void run() override;
    void drawInstruct();

private:

    sf::RenderWindow* m_window;
    sf::Text i_text;
    sf::Font i_font;

    sf::Text help_text;

    sf::Texture background_texture; // Background texture (image)
    sf::Sprite background_sprite;   // Background Sprite

    sf::Texture person_texture;
    sf::Sprite person_sprite;

    sf::Texture bird_texture;
    sf::Sprite  bird_sprite;

    sf::Texture cloud_texture;
    sf::Sprite  cloud_sprite;

    sf::Texture coin1_texture;
    sf::Sprite  coin1_sprite;

    sf::Texture coin2_texture;
    sf::Sprite  coin2_sprite;

    sf::Texture time5_texture;
    sf::Sprite  time5_sprite;

    sf::Texture time10_texture;
    sf::Sprite  time10_sprite;

}; // class Instructions

#endif // INSTRUCTIONS_HPP