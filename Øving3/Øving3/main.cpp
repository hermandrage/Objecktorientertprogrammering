
#include "main.hpp"
#include "cannonball.hpp"
#include "utilities.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    /*double theta;
    double absfart;
    cout << acclY() << endl;
    cout << posX(0, 10, 2.5) << endl;
    cout << posY(0, 10, 2.5) << endl;
    cout << flightTime(10,2.5) << endl;
    printTime();
    getUserInput(&theta, &absfart);
    */
    srand(time(nullptr));
    /*for (int i=0; i<10; i++){
        cout << randomWithLimits(10,5) << endl;
    }
    */
    /*double thetta=0;
    double absfart=0;
    double fartX=0;
    double fartY=0;
    
    getUserInput(&thetta, &absfart);
    getVelocityVector(thetta, absfart, &fartX, &fartY);
    cout << "Theta(deg): " << "\n absfart" << absfart << "\n fartx: " << fartX << "\n fartY: " << endl;
    cout << degToRad(60) << endl;
    cout << targetPractice(100, fartX, fartY);
    */
    playTargetPractice();
    
}
