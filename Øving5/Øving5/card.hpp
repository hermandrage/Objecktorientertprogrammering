
#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string> 
#include <random>
using namespace std;

enum Suit{CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank{TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

void test();
string suitToString(int farge);
string rankToString(int rank);
struct CardStruct{
    Suit s;
    Rank r;
};
string toString(CardStruct kort);
string toStringShort(CardStruct kort);

class Card{
private:
    Suit s;
    Rank r;
    bool invalid;
public:
    Card(){
        invalid=true;
    }
    Card(Suit s, Rank r){
        initialize(s, r);
    }
    void initialize(Suit s, Rank r);
    Suit gets();
    Rank getr();
    string toString();
    string toStringShort();
};

class CardDeck{
public:
    CardDeck(){
        currentCardIndex=0;
        for(int i=0; i<4; i++){
            for (int j=2; j<=14; j++){
                cards.push_back(Card(Suit(i),Rank(j)));
            }
        }
        shuffle();
    }
    void print();
    void printShort();
    void shuffle();
    Card drawCard();
private:
    void swap(int index1, int index2);
    vector<Card> cards;
    int currentCardIndex;
    //void swap(int index1, int index2);
};

class blackJack{
public:
    bool isAce(Card *kort);
    int getCardValue(Card *kort);
    int getPlayerCardValue(Card *kort);
    int getDealerCardValue(Card *kort, int dealerHand);
    bool askPlayerDrawCard();
    void drawInitialCards();
    void playGame(); 
private:
    CardDeck deck;
    int playerHand;
    int dealerHand;
    int playerCardsDrawn;
    int dealerCardsDrawn;
    
};





