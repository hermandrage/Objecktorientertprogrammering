
#include "vector.hpp"
#include "Matrix.h"
#include <cmath>

Vektor::Vektor():Matrix(){}
Vektor::Vektor(int nRows):Matrix(nRows, 1, 0){}
Vektor::Vektor(const Matrix & other):Matrix(){
    if (other.getColumns()==1) {
        Matrix::operator=(other);
    }
}

void Vektor::set(int row, double value){
    Matrix::set(row, 0, value);
}
double Vektor::get(int row)const{
    return Matrix::get(row, 0);
}
double Vektor::dot(const Vektor &rhs) const{
    if (getRows()==rhs.getRows()) {
        int pirkkProd=0;
        for (int i=0; i<getRows(); i++) {
            pirkkProd+=rhs.get(i);
        }
        return pirkkProd;
    }
    return nan("");
}
double Vektor::lengthSquared() const{
    return dot(*this);
}
double Vektor::length() const{
    return sqrt(lengthSquared());
}


