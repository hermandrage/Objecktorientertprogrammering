#pragma once
#include <stdio.h> 
#include <iostream>
using namespace std;

class Car{
public:
    Car(int freesSeats);
    bool hasFreeSeats() const;
    void reserveFreeSeat();
private:
    int freeSeats;
};


