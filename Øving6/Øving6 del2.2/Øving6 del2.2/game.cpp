#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "GameObjects.h"
#include "cannonball.hpp"
#include "utilities.hpp"
using namespace std;

int main () {
    srand(time(nullptr));
    Target tull(20,rand()%1200);
    
    Cannon cannon;
    std::vector<Cannonball> alleKanonkuler;
        // window size
    const double WIN_HEIGHT = 600;
    const double WIN_WIDTH = 1200;

    // create a window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // "smoother" edges - not necessary
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "TargetPractice", sf::Style::Close, settings);
    window.setFramerateLimit(30);

    // flip coordinates to make (0, 0) in lower left corner
    // in order to simplify simulation
    sf::View view(window.getView());
    view.setSize(WIN_WIDTH, -WIN_HEIGHT);
    window.setView(view);

    // start the clock
    sf::Clock clock;

    // variable indicating if the player has hit the target
    bool gameOver = false;

    // create game objects here ****


    // main loop
    while (window.isOpen()) {
        sf::Event event;
        // while there are still unhandled events
        while (window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                case sf::Keyboard::Escape:
                case sf::Keyboard::Q:
                    window.close();
                    break;
                default:
                    break;
                }
                // all events that only should be handled
                // while the game is not over, should
                // be placed here inside this if
                // (ex: moving the cannon, shooting)
                if (!gameOver) {
                    switch(event.key.code) {
                    // add case for new keyboard events here!
                    case sf::Keyboard::Up:
                        cannon.incrementVelocity();
                        break;
                    case sf::Keyboard::Down:
                        cannon.decrementVelocity();
                        break;
                    case sf::Keyboard::Right:
                        cannon.decrementAngle();
                        break;
                    case sf::Keyboard::Left:
                        cannon.incrementAngle();
                            break;
                    case sf::Keyboard::Space:
                        alleKanonkuler.push_back(cannon.shoot());
                        break;
                    default:
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }

        // add checks for landed cannonballs here,
        // also check for cannonballs hitting the target
        for (vector<Cannonball>::iterator it=alleKanonkuler.begin(); it!=alleKanonkuler.end();) {
            if(hitTarget(*it, tull)){
                gameOver=true;
            }
            if (it->hasLanded()) {
                it=alleKanonkuler.erase(it);
            }
            else{
                it++;
            }
            
        }

        // only update if game is not over
        if (!gameOver) {
            cannon.update();
            for (vector<Cannonball>::iterator it=alleKanonkuler.begin(); it!=alleKanonkuler.end(); it++) {
                (*it).update();
            }
            // update objects here
        }

        window.clear();
        // draw objects here
        tull.draw(window);
        cannon.draw(window);
        for (vector<Cannonball>::iterator it=alleKanonkuler.begin(); it!=alleKanonkuler.end(); it++) {
            (*it).draw(window);
        }
        window.display();
    }
}

