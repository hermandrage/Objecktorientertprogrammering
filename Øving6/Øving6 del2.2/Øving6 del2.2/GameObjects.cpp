#include "GameObjects.h"

#include "cannonball.hpp"
#include <cmath>

// implement all (member) functions in this file

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}


Cannon::Cannon(){
    shape = sf::RectangleShape(sf::Vector2f(width, length));
    shape.setOrigin(width/2, 0);
    shape.setPosition(0, 0);
    shape.setFillColor(sf::Color::Blue);
}

void Cannon::update(){
    shape.setRotation(theta-90);
}

void Cannon::draw(sf::RenderWindow& window){
    window.draw(shape); 
}

void Cannon::incrementAngle(double dtheta){
    theta+=dtheta;
}
void Cannon::decrementAngle(double dtheta){
    theta-=dtheta;
}

void Cannon::incrementVelocity(double dvel){
    velocity+=dvel;
}
void Cannon::decrementVelocity(double dvel){
    velocity-=dvel;
}

double Cannonball::getPosX() const {
    return posX(startPosX, startVelX, getAirTime());
}

double Cannonball::getPosY() const {
    return posY(startPosY, startVelY, getAirTime());
    // write your code here,
    // and change the return value
    return 0;
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}


Cannonball Cannon::shoot(){
    Cannonball kula(theta, velocity, getTipX(), getTipY());
    return kula;
}

Cannonball::Cannonball(double angle, double initial_velocity, double startPosX, double startPosY)
: startVelX(getVelocityX(angle, initial_velocity)), startVelY(getVelocityY(angle, initial_velocity)), startPosX(startPosX), startPosY(startPosY), shape(size){
    shape.setOrigin(size/2, size/2);
    shape.setFillColor(sf::Color::Green);
    
}
void Cannonball::update(){
    shape.setPosition(getPosX(), getPosY());
}
void Cannonball::draw(sf::RenderWindow& window){
    window.draw(shape); 
}



Target::Target(double size, double position): size(size),position(position){
    shape = sf::RectangleShape(sf::Vector2f(size, size));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position, size);
}

void Target::update(){}
void Target::draw(sf::RenderWindow& window){
    window.draw(shape);
}
