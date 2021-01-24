
#include "matirx.hpp"

Matrix::Matrix():rows(0), colums(0){
    matrise=nullptr;
    
}
Matrix::Matrix(int nRows, int nColumns):rows(nRows), colums(nColumns){
    matrise=new double*[nRows];
    for (int i=0; i<nRows; i++) {
        matrise[i]=new double[nColumns];
        for (int j=0; j<nColumns; j++) {
            matrise[i][j]=0;
            
        }
    }
}
Matrix::Matrix(int nRows): Matrix(nRows, nRows){
    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nRows; j++) {
            if(i==j){
                matrise[i][j]=1;
            }
            /*else{
                matrise[i][j]=0;
            }*/
            
        }
    }
}
Matrix::Matrix(const Matrix& rhs): Matrix(rhs.getWidth(), rhs.getHeight()){
     cout << "Brukte kopikonstruktør\n";
    //this->colums=rhs.colums;
    //this->rows=rhs.rows;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<colums; j++) {
            this->matrise[i][j]=rhs.matrise[i][j];
        }
    }
    
}

Matrix::~Matrix(){
    /*for (int i=0; i<rows; i++) {
        delete []matrise[i];
        matrise[i]=nullptr;
    }
    delete []matrise;
    matrise=nullptr;*/
    //delete []matrise;
    //matrise=nullptr;
    killmatrix();
    
}

double Matrix::get(int row, int col) const{
    return matrise[row][col];
}
void Matrix::set(int row, int col, double value){
    matrise[row][col]=value;
}

int Matrix::getHeight() const{
    return colums;
}
int Matrix::getWidth() const{
    return rows; 
}

bool Matrix::isValid() const{
    //return !!nullptr;
    // return matrise == nullptr;
    if (matrise==nullptr) {
        return false;
    }
    return true; 
}

ostream& operator<<(ostream& os, const Matrix& m){
    if(!m.isValid()){
        os<<"Ugyldig matrise" << endl;
    }
    else{
        for (int i=0; i<m.getWidth(); i++) {
            for (int j=0; j<m.getHeight(); j++) {
                os << m.get(i, j) << "\t";
            }
            os << endl; 
        }
    }
    return os;
}
Matrix Matrix::operator=(Matrix rhs){
    swap(rows, rhs.rows);
    swap(colums, rhs.colums);
    /*for (int i=0; i<rows; i++) {
     for (int j=0; j<colums; j++) {
     swap(matrise[i][j],rhs.matrise[i][j]);
     }
     }*/
    swap(matrise,rhs.matrise);
    return *this;
}
Matrix & Matrix::operator+=(Matrix rhs){
    if((rows!=rhs.rows)||(colums!=rhs.colums)){
        //this->matrise=nullptr;
        this->killmatrix();
        return *this;
    }
    for (int i =0; i<rows; i++) {
        for (int j=0; j<colums; j++) {
            (*this).matrise[i][j]+=rhs.matrise[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator+(Matrix rhs){
    Matrix nyMattis(*this);
    nyMattis+=rhs;
    return nyMattis;
}
void Matrix::killmatrix(){
    for (int i=0; i<rows; i++) {
        delete []matrise[i];
        matrise[i]=nullptr;
    }
    delete []matrise;
    matrise=nullptr;
    colums=0;
    rows=0;
}





