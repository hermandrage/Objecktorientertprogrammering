#include <iostream>
#include "Image.h"
#include "Matrix.h"
#include "vector.hpp"
#include "shape.hpp"
#include "line.hpp"
#include "Canvas.hpp"
//inkluder andre headerfiler du lager
using namespace std;

int main(){
    Matrix toys(3,3,8);
    Matrix toys2(3,1,5);
    Vektor tull(toys2);
    cout << tull << endl << toys*tull << endl;
    
    Color crayolaFuchsia(193,84,193);
    Color rod(0,255,0);
    Image bilde(50,50);
    bilde.fill(crayolaFuchsia);
    bilde.setPixelColor(25, 25, rod);
    saveImage(bilde, "apekatt");
    
    Image bilde2(200,200);
    Line linje(crayolaFuchsia,0,100,40,50);
    linje.draw(bilde2);
    saveImage(bilde2, "Kattepus2");
    
    Image bilde3(200,200);
    Line linje3(crayolaFuchsia,0,100,50,50);
    linje.draw(bilde3);
    saveImage(bilde3, "Kattepus8");
    
    Canvas can;
    Image bilde4(200,200);
    Line linje4(crayolaFuchsia,0,200,0,200);
    Line linje5(crayolaFuchsia,50,100,0,100);
    can.addShape(&linje4);
    can.addShape(&linje5);
    can.rasterizeTo(bilde4);
    saveImage(bilde4, "Kattepus7");
    
return 0;
}
