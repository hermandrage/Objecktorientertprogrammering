
#ifndef matirx_hpp
#define matirx_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Matrix{
public:
    Matrix();
    explicit Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    Matrix(const Matrix & rhs); 
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getHeight() const;
    int getWidth() const;
    bool isValid() const;
    
    ~Matrix();
    Matrix operator=(Matrix rhs);
    /*{
        swap(rows, rhs.rows);
        swap(colums, rhs.colums);
        for (int i=0; i<rows; i++) {
            for (int j=0; j<colums; j++) {
                swap(matrise[i][j],rhs.matrise[i][j]);
            }
        }
        swap(matrise,rhs.matrise);
        return *this;
    }*/
    Matrix & operator+=(Matrix rhs);
    Matrix operator+(Matrix rhs);
   

private:
    void killmatrix();
    int rows;
    int colums;
    double **matrise;
    
};
 ostream& operator<<(ostream& os, const Matrix &m);



#endif /* matirx_hpp */
