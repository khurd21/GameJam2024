#ifndef SCORES_HPP
#define SCORES_HPP

#include <HackathonLib/Runners/IRunner.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <tuple>
const inline std::string default_filename="resources/ski_jump_data.csv";
class ScoreRunner : public IRunner {
public:
    ScoreRunner(sf::RenderWindow* window, std::string filename=default_filename);
    virtual void run() override;

    void loadScoresFromFile(const std::string& filename);
    void drawUsername();
    void drawScores();
    void updateCurrentUsernameText();
    void addScore(int score);
    void saveScores();


private:
    sf::RenderWindow* m_window;
    sf::Text i_text;
    sf::Font i_font;

    sf::Text help_text_1;
    sf::Text help_text_2; 

    std::vector<std::tuple<std::string, int>> scores; // Store up to 10 username-score tuples ex. [("John", 69), ("Andy", 20), ....] CHANGE LATER TO BE ONLY 10 ENTIRES MAX
    std::string current_username; // Store the current user's username
    std::string m_filename;
    sf::Text current_username_text;


    sf::Texture background_texture; // Background texture (image)
    sf::Sprite background_sprite;   // Background Sprite
 
    sf::Texture sign_texture;
    sf::Sprite  sign_sprite;

}; // class Scores

#endif // SCORES_HPP