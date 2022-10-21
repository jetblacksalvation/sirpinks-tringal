// sirpinks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>


int main()
{
    srand(time(NULL));
    sf::Vector2i start(rand() % 800, rand() % 800);

    sf::RectangleShape pixel({ 1,1 });
    pixel.setSize({ 1,1 });
    pixel.setFillColor(sf::Color::Green);
    std::vector<sf::Vector2i> pos;

    sf::RenderWindow window({ 800,800 }, "sirpinks");
    sf::Event event;
    //window.clear(sf::Color::White);

    int random;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == event.Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left and pos.size() != 3) {
                
                pos.push_back(sf::Mouse::getPosition(window));
                
            }

        }


        if (pos.size() == 3) {

            random = rand() % 3;
            start.x = (start.x + pos[random].x) / 2;
            start.y = (start.y + pos[random].y) / 2;
            pixel.setPosition(sf::Vector2f(start));
            //serpinski stuff
            window.draw(pixel);
            window.display();

        }

        
        
    }
}
