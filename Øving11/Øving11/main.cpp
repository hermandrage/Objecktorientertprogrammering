
#include <iostream> 
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include "iterator.hpp"
#include "set_beholdere.hpp" 
#include "TemplateFunctions.hpp"
#include <ctime>
using namespace std;

int main(){
    //Oppg1------------------------------------------------
    vector<string> strenger;
    strenger.push_back("kake");
    strenger.push_back("eple");
    strenger.push_back("appelsin");
    strenger.push_back("pære");
    for (vector<string>::reverse_iterator it=strenger.rbegin(); it!=strenger.rend(); it++) {
        cout << *it << endl;
    }
    for (vector<string>::iterator it=strenger.begin(); it!=strenger.end(); it++) {
        cout << *it << endl;
    }
    byttUt(strenger, "eple", "kake");
    cout << "\n\n";
    for (vector<string>::iterator it=strenger.begin(); it!=strenger.end(); it++) {
        cout << *it << endl;
    }
    
    
    //Oppg2-----------------------------------------------
    set<int> tall;
    for (int i=1; i<=100; i++) {
        tall.insert(i);
    }
    for (int i=2; i<=50; i++) {
        for (int j=i+1; j<=100; j++) {
            if(j%i==0){
                tall.erase(j);
            }
        }
    }
    for (set<int>::iterator it=tall.begin(); it!=tall.end(); it++) {
        cout << *it << endl;
    }
    
    //Oppg3--------------------------------------------------
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    shuffle(a, 7);
    for (int i=0; i<7; i++) {
        cout << a[i] << "\t";
    }
    cout << endl << endl;
    double b[] = {1.2, 2.2, 3.2, 4.2};
    shuffle(b, 4);
    string c[] = {"one", "two", "three", "four"};
    shuffle(c, 4);
    for (int i=0; i<4; i++) {
        cout << c[i] << "\t";
    }
    cout << endl << endl;
    
    cout << maksimum("a", "c") << endl;
    
    return 0;
}
