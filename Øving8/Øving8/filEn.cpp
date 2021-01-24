
#include "filEn.hpp"
#include <iostream> 
#include <fstream> 
using namespace std;
void skrivTilFil(string filnavn){
    string ord="";
    ofstream bucky;
    bucky.open(filnavn);
    if (bucky.is_open()) {
        
    cout << "skriv inn ett og ett ord (quit for å avslutte)" << endl;
    
    while (ord!="quit") {
        ord="";
        cin >> ord;
        bucky << ord << "\n";
    }
    //cout << &bucky << endl;
    bucky.close();

    }
}
void lesFraFil(string filnavn, string nyttFilnavn){
    ifstream bucky(filnavn);
    ofstream fil2;
    fil2.open(nyttFilnavn);
    string ord;
    for (int teller =1;bucky>>ord; ++ teller) {
        //cout << ord << endl;
        fil2 << teller << ord << endl;
    }
    fil2.close(); 
    
}
