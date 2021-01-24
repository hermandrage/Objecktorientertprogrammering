#include "cannonball.hpp"
#include <iostream>
#include <cmath>
#include "utilities.hpp"
using namespace std;

double acclY(){
    return -9.81;
}
double velT(double initVelocityY, double time){
    return initVelocityY + acclY()*time;
}
double posX(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time;
}

double posY(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time + (acclY()*time*time/2);
}

void printTime(){
    int tid;
    cout <<"Skriv inn tid i sekunder" << endl;
    cin >> tid;
    int timer = tid/3600;
    int min = (tid%3600)/60;
    int sek = tid- (timer*3600)-min*60;
    cout << "Timer: " << timer << ", minutter: " << min << ", Sekunder: " << sek << endl;
}

double flightTime(double initVelocityY){
    return -2*initVelocityY/acclY();
}

void getUserInput(double* theta, double* absVelocity){
    cout << "Skriv inn for theta og absVelocity" << endl;
    cin >> *theta >> *absVelocity;
}

double degToRad(double deg){
    return deg*3.1415/180;
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity*cos(degToRad(theta));
}
double getVelocityY(double theta, double absVelocity){
    return absVelocity*sin(degToRad(theta));
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY){
    *velocityX= getVelocityX(theta, absVelocity);
    *velocityY= getVelocityY(theta, absVelocity);
}

double getDistanceTraveled(double velocityX, double velocityY){
    return velocityX*flightTime(velocityY);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return getDistanceTraveled(velocityX, velocityY)-distanceToTarget;
}

void playTargetPractice(){
    int disttarget = randomWithLimits(1000,100);
    
    double thetta=0;
    double absfart=0;
    double fartX=0;
    double fartY=0;
    double avstand=0;
    
    for (int i=0; i<10; i++){
        getUserInput(&thetta, &absfart);
        getVelocityVector(thetta, absfart, &fartX, &fartY);
        avstand=targetPractice(disttarget, fartX, fartY);
        cout << avstand << endl;
        if (abs(avstand)<=5){
            cout << "Gratulerer! du vant!" << endl;
            break;
        }
        if (i>=9) {
            cout << "Du tapte" << endl;
        }
    }
}
