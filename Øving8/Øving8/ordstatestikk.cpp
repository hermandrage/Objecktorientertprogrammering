

#include "ordstatestikk.hpp"

void lagStatestikk(string filnavn){
    ifstream fil(filnavn);
    string linje;
    int antLinjer=0;
    int antOrd=0;
    string lengsteOrd="";
    map<string,int>ordene;
    
    while (getline(fil, linje)) {
        antLinjer++;
        stringstream ss(linje);
        string ord;
        while (ss >> ord) {
            antOrd++;
            if (ord.length()>lengsteOrd.length()) {
                lengsteOrd=ord;
            }
            if (ordene.find(ord)!=ordene.end()) {
                ordene[ord]++;
            }
            else{
                ordene[ord]=1;
            }
            
        }
    }
    cout << "Text statistics: \n Longest word: " << lengsteOrd << "\nNumber of words: " << antOrd << "\nNumber of lines: " << antLinjer << endl;
    for (auto it=ordene.begin(); it!=ordene.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}
