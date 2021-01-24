

#ifndef LenkedeLister_hpp
#define LenkedeLister_hpp

#include <stdio.h> 
#include <iostream> 
#include <string> 
#include <list>
#include <ostream>
#include <forward_list>
using namespace std;

class Person{
public:
    Person(string fornavn, string etternavn):forNavn(fornavn), etterNavn(etternavn){}
    void settFornavn(string navn);
    void settEtternavn(string navn);
    string getForNavn();
    string getEtterNavn();
    friend ostream &operator<<(ostream &vs, Person &person);
    bool operator < (Person &P);
private:
    string forNavn;
    string etterNavn;
};

void insertOrdered(list<Person> &l, Person person);

#endif /* LenkedeLister_hpp */
