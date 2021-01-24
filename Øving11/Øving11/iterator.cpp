
#include "iterator.hpp"

void byttUt(vector<string> &vektor, string old, string replacment){
    for (vector<string>::iterator it=vektor.begin(); it!=vektor.end(); it++) {
        if(*it == old){
            vektor.erase(it);
            vektor.insert(it, replacment);
        }
    }}
