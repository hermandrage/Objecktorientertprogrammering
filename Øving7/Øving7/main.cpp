
#include "dynamiskMinnehåndtering.hpp"
#include <iostream>
#include "matirx.hpp" 
#include "dummy.hpp"
using namespace std;

int main(){
    //createFibonacci();
    /*Matrix noe;
    Matrix noeannet(10);
    Matrix noeGøy(9,9);
    Matrix godMatrix(noeannet);
    cout << "Brukte kopikonstruktør i main \n";
    cout << noeannet << endl <<godMatrix << endl;
    noeannet.set(5, 5, 69);
    cout << noeannet << endl <<godMatrix << endl;
    noeannet+=godMatrix;
    cout << noeannet  << "Noe annet"<< endl;
    Matrix carl = noeannet + noeGøy;
    cout << "Noe annet: " << endl << noeannet << endl << "Noegøy: " << endl << noeGøy << endl << "Carl: " << endl << carl << endl;*/
    //dummyTest();
    Matrix A(2,2);
    Matrix B(2,2);
    Matrix C(2,2);
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);
    B.set(0, 0, 4);
    B.set(0, 1, 3);
    B.set(1, 0, 2);
    B.set(1, 1, 1);
    C.set(0, 0, 1);
    C.set(0, 1, 3);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2);
    A+=B+C;
    cout << "A : " << endl << A << endl << "B og C " << endl << B << endl << C << endl;
    
    return 0;
}
