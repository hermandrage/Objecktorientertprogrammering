
#include "line.hpp"

Line::Line(Color farge,unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2): x1(x1), x2(x2), y1(y1), y2(y2), Shape(farge){}

void Line::draw(Image &bilde){
    double dx=x2-x1;
    double dy=y2-y1;
    if (dy<dx) {
        for (x=x1; x<x2; x++) {

            y=static_cast<double>(((dy/dx)*(x-x1)+y1));
            bilde.setPixelColor(x, y, farge);
        }
    }
    else if (dy>=dx){
        for (y=y1; y<y2; y++) {
            x=static_cast<double>(((dx/dy)*(y-y1)+y1));
            bilde.setPixelColor(x, y, farge);
        }
    }
}
