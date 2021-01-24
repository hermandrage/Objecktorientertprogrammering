

#include "tegnstatistikk.hpp"

void tegnstatestikk(string filnavn){
    string streng;
    ifstream fil(filnavn);
    int statestikk[26] ={0};
    int teller=0;
    while(fil >> streng){
        for (int i=0; i<streng.length(); i++){
            if (streng[i]>='a' || streng[i]<='z') {
                statestikk[static_cast<int>(tolower(streng[i]))-'a']++;
                teller++;
            }
        }
    }
    cout << "Character statistics:\n Total number of characters: " << teller << endl;
    for (int i=0; i<26; i++) {
        cout << char('a'+i) << ": " << statestikk[i] << "\t";
        /*if (i%4==0) {
            cout << endl; 
        }*/
    }
}
