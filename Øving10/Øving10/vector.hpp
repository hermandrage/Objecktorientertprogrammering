#include <iostream>
#include "Matrix.h"
using namespace std; 

#ifndef vector_hpp
#define vector_hpp

#include <stdio.h>

class Vektor: public Matrix{
public:
    Vektor();
    explicit Vektor(int nRows);
    Vektor(const Matrix & other);
    void set(int row, double value);
    double get(int row) const;
    double dot(const Vektor &rhs) const;
    double lengthSquared() const;
    double length() const;
};



#endif /* vector_hpp */
