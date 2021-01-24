
#include "Canvas.hpp"
#include "Image.h"

void Canvas::addShape(Shape *form){
    former.push_back(form); 
}
void Canvas::rasterizeTo(Image &bilde){
    for (unsigned int i=0; i<former.size(); i++) {
        former[i]->draw(bilde);
    }
}
