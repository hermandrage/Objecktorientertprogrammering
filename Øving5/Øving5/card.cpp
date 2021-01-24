
#include "card.hpp" 
#include <iostream>
#include <string>
#include <sstream>

string suitToString(int farge){
    
    switch (farge){
        case 0:
            return "CLUBS";
            break;
        case 1:
            return "DIAMONDS";
            break;
        case 2:
            return "HEARTS";
            break;
        case 3:
            return "SPADES";
            break;
        default:
            break;
    }
    return "";
}
string rankToString(int rank){
    switch (rank){
        case 2:
            return "TWO";
            break;
        case 3:
            return "THRE";
        case 4:
            return "FOUR";
            break;
        case 5:
            return "FIVE";
        case 6:
            return "SIX";
            break;
        case 7:
            return "SEVEN";
        case 8:
            return "EIGHT";
            break;
        case 9:
            return "NINE";
        case 10:
            return "TEN";
        case 11:
            return "JACK";
            break;
        case 12:
            return "QUEEN";
        case 13:
            return "KING";
            break;
        case 14:
            return "ACE";
        default:
            break;
    }
    return "";
}

void test(){
    cout << Suit(SPADES) << endl;
}

string toString(CardStruct kort){
    return rankToString(kort.r) + " of " + suitToString(kort.s);
}

string toStringShort(CardStruct kort){
    string tall = to_string(kort.r);
    return suitToString(kort.s).substr(0,1) + tall;
}

void Card::initialize(Suit s, Rank r){
    this->s=s;
    this->r=r;
    invalid=false;
}
Suit Card::gets(){
    return s;
}
Rank Card::getr(){
    return r;
}

string Card::toString(){
    if (invalid){
        return "Ugyldig kort";
    }
    return rankToString(r) + " of " + suitToString(s);
}

string Card::toStringShort(){
    if (invalid){
        return "Ugyldig kort";
    }
    return suitToString(s).substr(0,1) + to_string(r);
}

void CardDeck::print(){
    for(int i=0; i<cards.size(); i++){
        cout << cards[i].toString() << endl;
    }
}
void CardDeck::printShort(){
    for (int i=0; i<cards.size(); i++){
        cout << cards[i].toStringShort() << endl;
    }
}
void CardDeck::swap(int index1, int index2){
    Card kort1=cards[index1];
    cards[index1]=cards[index2];
    cards[index2]=kort1;
}
void CardDeck::shuffle(){
    for(int i=0; i<cards.size(); i++){
        swap(i, (rand()%(cards.size())));
    }
}
Card CardDeck::drawCard(){
    currentCardIndex++;
    return cards[currentCardIndex-1];
}

bool blackJack::isAce(Card *kort){
    if((*kort).getr()==14){
        return true;
    }
    return false;
}

int blackJack::getCardValue(Card *kort){
    if ((*kort).getr()==14){
        return -1;
    }
    return (*kort).getr();
}

int blackJack::getPlayerCardValue(Card *kort){
    if(isAce(kort)){
        int verdi;
        cout << "Vil du at esset skal være 1 eller 11?" << endl;
        cin >> verdi;
        while(verdi!=1 && verdi!=11){
            cout << "ugyldig skiv inn 1 eller 11" << endl;
            cin >> verdi;
        }
        return verdi;
    }
    return getCardValue(kort);
}

int blackJack::getDealerCardValue(Card *kort, int playerHand){
    if(isAce(kort)){
        if(11+playerHand>21){
            return 1;
        }
        return 11;
    }
    return getCardValue(kort);
}

bool blackJack::askPlayerDrawCard(){
    string svar;
    cout << "Vil du ha et nytt kort?" << endl;
    cin >> svar;
    while (svar!="ja" && svar!="nei"){
        cout << "ugyldig, svar ja eller nei" << endl;
        cin >> svar;
    }
    if (svar=="ja"){
        return true;
    }
    return false;
}

void blackJack::drawInitialCards(){
    Card playerCard=deck.drawCard();
    playerHand+=getPlayerCardValue(&playerCard);
    playerCardsDrawn++;
    
    Card dealerCard=deck.drawCard();
    dealerHand+=getDealerCardValue(&dealerCard, dealerHand);
    dealerCardsDrawn++;
    
    cout << "Dealers første kort: " << dealerCard.toString() << "\n dine kort: " << playerCard.toString() << endl;
    
    playerCard=deck.drawCard();
    playerHand+=getPlayerCardValue(&playerCard);
    playerCardsDrawn++;
    
    cout << playerCard.toString() << endl;
    
    dealerCard=deck.drawCard();
    dealerHand+=getDealerCardValue(&dealerCard, dealerHand);
    dealerCardsDrawn++;
}

void blackJack::playGame(){
    deck.shuffle();
    drawInitialCards();
    bool fortsette = true;
    
    while (fortsette) {
        fortsette = false;
    if (askPlayerDrawCard()){
        Card playerCard=deck.drawCard();
        playerHand+=getPlayerCardValue(&playerCard);
        playerCardsDrawn++;
        cout << "du trakk: " << playerCard.toString() << endl; 
        fortsette = true;
    }
    if (dealerHand<17){
        Card dealerCard=deck.drawCard();
        dealerHand+=getDealerCardValue(&dealerCard, dealerHand);
        dealerCardsDrawn++;
        fortsette = true;
    }
    if (playerHand>21){
        cout << "Din poengsum er over 21. Du tapte!!" << endl;
        break;
    }
    if (playerHand==21){
        cout << "BLACK JACK!!!!Gratulerer du har vunnet!!!!!" << endl;
        break;
    }
    if (dealerHand>21){
        cout << "Dealer fikk over 21! Gratulerer du har vunnet!!!!!" << endl;
        break;
    }
    }
    if (!fortsette){
        if(playerHand > dealerHand){
            cout << "Du fikk flest poeng!! Gratulerer du har vunnet!!!!!" << endl;
        }
        else{
            cout << "Dealer fikk like mange eller fler poeng. Du tapte!!" << endl;
        }
    }
    string spilleigjen;
    cout << "Vil du spille igjen? (svar ja for å fotsettelse, alt annet avslutter spillet)" << endl;
    cin >> spilleigjen;
    if (spilleigjen=="ja") {
        playerHand=0;
        dealerHand=0;
        playerCardsDrawn=0;
        dealerCardsDrawn=0;
        playGame();
    }
    
    
}


