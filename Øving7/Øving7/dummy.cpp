
#include "dummy.hpp"
#include <iostream> 
using namespace std;


Dummy::Dummy(const Dummy& dum){
    this->num=new int(*(dum.num));
}

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b(a);
    Dummy c;
    c = a;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;
    *b.num = 3;
    *c.num = 5;
    cout << "a: " << *a.num << endl;
    cout << "b: " << *b.num << endl;
    cout << "c: " << *c.num << endl;
    //cin.get();
    
}
