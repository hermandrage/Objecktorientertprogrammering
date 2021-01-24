

#ifndef dummy_hpp
#define dummy_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Dummy {
public:
    int *num;
    Dummy() {
        num = new int(0);
    }
    Dummy(const Dummy& dum);
    ~Dummy() {
        delete num;
    }
    Dummy operator=(Dummy rsh){
        swap(num, rsh.num);
        return *this;
    }
};

void dummyTest(); 

#endif /* dummy_hpp */
