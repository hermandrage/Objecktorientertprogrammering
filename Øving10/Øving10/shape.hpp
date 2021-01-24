
#ifndef shape_hpp
#define shape_hpp

#include <stdio.h>
#include "Image.h"

class Shape{
public:
    Shape();
    Shape(Color farge);
    Color getColor();
    virtual void draw(Image &bilde)=0;
protected:
    Color farge;
};


#endif /* shape_hpp */
