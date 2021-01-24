
#ifndef person_hpp
#define person_hpp

#include <stdio.h>


#include <iostream>
#include "car.hpp"
using namespace std;


class Person{
public:
    Person(string nameValue, string epostValue);
    Person(string nameValue, string emailValue, Car* bil);
    
    
    void setEmail();
    string getName() const;
    string getEmail()const;
    bool hasAvailableSeats() const;
    bool operator<(const Person& other) const;
    bool operator==(const Person& p2) const;
private:
    string name;
    string email;
    Car *bil;
};
ostream& operator<<(ostream& os, const Person& p);




#endif /* person_hpp */
