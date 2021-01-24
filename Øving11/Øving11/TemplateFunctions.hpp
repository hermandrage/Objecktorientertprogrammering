

#ifndef TemplateFunctions_hpp
#define TemplateFunctions_hpp

#include <stdio.h>

#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

template <typename T>
void shuffle(T tabell[], int lengde){
    for (int i=0; i<lengde-1; i++) {
        int j= rand()% (lengde-i);
        swap(tabell[i],tabell[i+j]);
    }
}

template <typename T>
T maksimum(T a, T b){
    if (a>b) {
        return a;
    }
    return b;
}

#endif /* TemplateFunctions_hpp */
