
#ifndef Canvas_hpp
#define Canvas_hpp
#include "shape.hpp"
#include "Image.h"
#include <stdio.h>
#include <iostream> 
#include <vector>
using namespace std;
class Canvas{
public:
    
    Canvas(){}
    void addShape(Shape *form);
    void rasterizeTo(Image &bilde);
private:
    vector<Shape*> former;
    
};






#endif /* Canvas_hpp */
