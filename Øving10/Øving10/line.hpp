
#ifndef line_hpp
#define line_hpp
#include "shape.hpp"
#include "Image.h"
#include <stdio.h>
#include <iostream>

class Line: public Shape{
public:
    Line(Color farge, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2);
    void draw(Image &bilde);
private:
    unsigned int x1, y1, x2, y2;
    int y, x;
};

#endif /* line_hpp */
