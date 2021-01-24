
#include "main.hpp"
#include "card.hpp"
#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <ctype.h>

int main(){
    /*//cout << suitToString(2) << endl;
    //cout << rankToString(5) << endl;
    CardStruct aceOfSpades;
    aceOfSpades.r=ACE;
    aceOfSpades.s=SPADES;
    //cout << toString(aceOfSpades) << endl;
    //cout << toStringShort(aceOfSpades) << endl;
    
    
    Card mittKort;
    mittKort.initialize(SPADES, ACE);
    

    cout << mittKort.toString() << endl;
    cout << mittKort.toStringShort() << endl;
    
    CardDeck minKortstokk;
    minKortstokk.print();
    cout << endl;
    minKortstokk.shuffle();
    minKortstokk.print();
    minKortstokk.printShort();
    
    for(int i=0; i<5; i++){
        cout << minKortstokk.drawCard().toString() << endl;
    }
    */ 
    srand(time(nullptr));
    blackJack spill;
    //spill.drawInitialCards();
    spill.playGame();
     
    return 0;
}
