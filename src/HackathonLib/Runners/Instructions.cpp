#include <HackathonLib/Runners/InstructRunner.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

InstructRunner::InstructRunner(sf::RenderWindow *window) : m_window(window)
{
    if (!background_texture.loadFromFile("resources/images/background.png"))
    {
        // handle error
    }
    background_sprite.setTexture(background_texture);

    // Load font
    if (!i_font.loadFromFile("resources/fonts/ice-season.ttf")) {
        // Handle error
    }

    // Set up the text
    i_text.setFont(i_font);
    i_text.setString("How to Play");
    i_text.setCharacterSize(80);          
    i_text.setFillColor(sf::Color::Blue); // Color of the title
    i_text.setStyle(sf::Text::Bold);
    i_text.setStyle(sf::Text::Underlined);

    // Center the title in the window
    sf::FloatRect title_bounds = i_text.getLocalBounds();
    i_text.setOrigin(title_bounds.left + title_bounds.width / 2.0f, title_bounds.top + title_bounds.height / 2.0f);
    i_text.setPosition(m_window->getSize().x / 2.0f, 50);

    // Put HELP TEXT HERE
    if (!sign_texture.loadFromFile("resources/images/sign.png"))
    {
        // handle error
    }
    sign_sprite.setTexture(sign_texture);
    // position and origin for person sprite
    sf::FloatRect sign_bounds = sign_sprite.getLocalBounds(); 
    sign_sprite.setOrigin(sign_bounds.left + sign_bounds.width / 2.0f, sign_bounds.top + sign_bounds.height / 2.0f);
    sign_sprite.setPosition(m_window->getSize().x / 2.0f, 700);

    sign_sprite.setScale(2.5, 1.7);


    // Person Sprite
    if (!person_texture.loadFromFile("resources/images/person_small.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    person_sprite.setTexture(person_texture);
    person_sprite.setScale(2.5,2.5);

    // position and origin for person sprite
    sf::FloatRect person_bounds = person_sprite.getLocalBounds();
    person_sprite.setOrigin(person_bounds.left + person_bounds.width / 2.0f, person_bounds.top + person_bounds.height / 2.0f);
    person_sprite.setPosition(1440, m_window->getSize().y / 4.0f + 100);


    // Coin1 Sprite
    if (!coin1_texture.loadFromFile("resources/images/coin1.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    coin1_sprite.setTexture(coin1_texture);

    //  position and origin for coin1 sprite
    coin1_sprite.setScale(2,2);
    sf::FloatRect coin1_bounds = coin1_sprite.getLocalBounds();
    coin1_sprite.setOrigin(coin1_bounds.left + coin1_bounds.width / 2.0f, coin1_bounds.top + coin1_bounds.height / 2.0f);
    coin1_sprite.setPosition(1380, m_window->getSize().y / 4.0f + 270);



    // Coin2 Sprite
    if (!coin2_texture.loadFromFile("resources/images/coin2.png")) { 
        std::cout << "Error loading sprite texture" << std::endl; 
    }
    
    // Set the texture to the sprite
    coin2_sprite.setTexture(coin2_texture);

    //  position and origin for coin2 sprite
    coin2_sprite.setScale(2,2);
    sf::FloatRect coin2_bounds = coin2_sprite.getLocalBounds();
    coin2_sprite.setOrigin(coin2_bounds.left + coin2_bounds.width / 2.0f, coin2_bounds.top + coin2_bounds.height / 2.0f);
    coin2_sprite.setPosition(1500, m_window->getSize().y / 4.0f + 270);



    // Time5 Sprite
    if (!time5_texture.loadFromFile("resources/images/time5.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    time5_sprite.setTexture(time5_texture);

    //  position and origin for time5 sprite
    time5_sprite.setScale(1.7,1.7);
    sf::FloatRect time5_bounds = time5_sprite.getLocalBounds();
    time5_sprite.setOrigin(time5_bounds.left + time5_bounds.width / 2.0f, time5_bounds.top + time5_bounds.height / 2.0f);
    time5_sprite.setPosition(1380, m_window->getSize().y / 4.0f + 430);



    // Time10 Sprite
    if (!time10_texture.loadFromFile("resources/images/time10.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    time10_sprite.setTexture(time10_texture);

    //  position and origin for time10 sprite
    time10_sprite.setScale(1.7,1.7);
    sf::FloatRect time10_bounds = time10_sprite.getLocalBounds();
    time10_sprite.setOrigin(time10_bounds.left + time10_bounds.width / 2.0f, time10_bounds.top + time10_bounds.height / 2.0f);
    time10_sprite.setPosition(1500, m_window->getSize().y / 4.0f + 430);



    // Bird Sprite
    if (!bird_texture.loadFromFile("resources/images/bird.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    bird_sprite.setTexture(bird_texture);

    //  position and origin for bird sprite
    bird_sprite.setScale(1.7,1.7);
    sf::FloatRect bird_bounds = bird_sprite.getLocalBounds();
    bird_sprite.setOrigin(bird_bounds.left + bird_bounds.width / 2.0f, bird_bounds.top + bird_bounds.height / 2.0f);
    bird_sprite.setPosition(1380, m_window->getSize().y / 4.0f + 580);



    // Cloud Sprite
    if (!cloud_texture.loadFromFile("resources/images/cloud.png")) {
        std::cout << "Error loading sprite texture" << std::endl;
    }
    
    // Set the texture to the sprite
    cloud_sprite.setTexture(cloud_texture);

    //  position and origin for cloud sprite
    cloud_sprite.setScale(1.7,1.7);
    sf::FloatRect cloud_bounds = cloud_sprite.getLocalBounds();
    cloud_sprite.setOrigin(cloud_bounds.left + cloud_bounds.width / 2.0f, cloud_bounds.top + cloud_bounds.height / 2.0f);
    cloud_sprite.setPosition(1520, m_window->getSize().y / 4.0f + 580);


    person_text.setFont(i_font);
    person_text.setString("Use the <- and -> keys to move the skier.");
    person_text.setCharacterSize(35);          
    person_text.setFillColor(sf::Color::White); // Color of the title
    person_text.setStyle(sf::Text::Bold);

    // Center the title in the window
    sf::FloatRect person_text_bounds = person_text.getLocalBounds();
    person_text.setOrigin(person_text_bounds.left + person_text_bounds.width / 2.0f, person_text_bounds.top + person_text_bounds.height / 2.0f);
    person_text.setPosition(m_window->getSize().x / 4.0f + 250, m_window->getSize().y / 4.0f + 100);



    coin_text.setFont(i_font);
    coin_text.setString("Gather as much coins as you can in the time provided.");
    coin_text.setCharacterSize(35);          
    coin_text.setFillColor(sf::Color::White); // Color of the title
    coin_text.setStyle(sf::Text::Bold);

    // Center the title in the window
    sf::FloatRect coin_text_bounds = coin_text.getLocalBounds();
    coin_text.setOrigin(coin_text_bounds.left + coin_text_bounds.width / 2.0f, coin_text_bounds.top + coin_text_bounds.height / 2.0f);
    coin_text.setPosition(m_window->getSize().x / 4.0f + 250, m_window->getSize().y / 4.0f + 250);


    time_text.setFont(i_font);
    time_text.setString("Increase the amount of time you have by grabbing the stopwatches.");
    time_text.setCharacterSize(30);          
    time_text.setFillColor(sf::Color::White); // Color of the title
    time_text.setStyle(sf::Text::Bold);

    // Center the title in the window
    sf::FloatRect time_text_bounds = time_text.getLocalBounds();
    time_text.setOrigin(time_text_bounds.left + time_text_bounds.width / 2.0f, time_text_bounds.top + time_text_bounds.height / 2.0f);
    time_text.setPosition(m_window->getSize().x / 4.0f + 270, m_window->getSize().y / 4.0f + 400);
 
    enemy_text.setFont(i_font);
    enemy_text.setString("Avoid being frozen by the cloud and killed instantly by the crow.");
    enemy_text.setCharacterSize(30);          
    enemy_text.setFillColor(sf::Color::White); // Color of the title
    enemy_text.setStyle(sf::Text::Bold);

    // Center the title in the window
    sf::FloatRect enemy_text_bounds = enemy_text.getLocalBounds();
    enemy_text.setOrigin(enemy_text_bounds.left + enemy_text_bounds.width / 2.0f, enemy_text_bounds.top + enemy_text_bounds.height / 2.0f);
    enemy_text.setPosition(m_window->getSize().x / 4.0f + 270, m_window->getSize().y / 4.0f + 550);

    help_text.setFont(i_font);
    help_text.setString("Press the 'Escape' key to return to the menu.");
    help_text.setCharacterSize(30);          
    help_text.setFillColor(sf::Color::White); // Color of the title
    help_text.setStyle(sf::Text::Bold);
    help_text.setStyle(sf::Text::Underlined);

    // Center the title in the window
    sf::FloatRect help_text_bounds = help_text.getLocalBounds();
    help_text.setOrigin(help_text_bounds.left + help_text_bounds.width / 2.0f, help_text_bounds.top + help_text_bounds.height / 2.0f);
    help_text.setPosition(m_window->getSize().x / 4.0f + 270, m_window->getSize().y / 4.0f + 640);

}

void InstructRunner::drawInstruct() {
    m_window->draw(background_sprite); 
    m_window->draw(sign_sprite);
    m_window->draw(i_text);
    m_window->draw(person_sprite);
    m_window->draw(person_text); 
    m_window->draw(coin1_sprite);
    m_window->draw(coin2_sprite);
    m_window->draw(coin_text);
    m_window->draw(time5_sprite);
    m_window->draw(time10_sprite);
    m_window->draw(time_text);
    m_window->draw(bird_sprite);
    m_window->draw(cloud_sprite);
    m_window->draw(enemy_text);
    m_window->draw(help_text);
}

void InstructRunner::run()
{
    std::cout << "IN INSTRUCTIONS" << std::endl;
    while (m_window->isOpen())
    {
        // Process events
        for (auto event = sf::Event{}; m_window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed) {
                m_window->close();
            } 
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                return;
            }
        }

        // Clear the window
        m_window->clear();

        // Draws everything
        drawInstruct();
        
        // Update the window
        m_window->display();
    }
}
