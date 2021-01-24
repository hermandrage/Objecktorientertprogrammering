
#include "LenkedeLister.hpp"

void Person::settFornavn(string navn){
    forNavn=navn;
}
void Person::settEtternavn(string navn){
    etterNavn=navn;
}
string Person::getForNavn(){
    return forNavn;
}
string Person::getEtterNavn(){
    return etterNavn;
}
bool Person::operator<(Person &P){
    if (etterNavn + forNavn < P.getEtterNavn() + P.getForNavn()) {
        return true;
    }
    return false;
}
ostream &operator<<(ostream &vs, Person &person){
    vs << person.getForNavn() << ", " << person.getEtterNavn();
    return vs;
}

/*void insertOrdered(forward_list<Person> &l, Person person){
    forward_list<Person>::iterator forrige;
    for (forward_list<Person>::iterator it=l.begin(); it!=l.end(); it++) {
        if (person<*it) {
            if (it!=l.begin()) {
                l.insert_after(it, person);
            }
            else{
                l.push_front(person);
            }
            return;
        }
        forrige=it;
        if (l.empty()) {
            l.push_front(person);
            return;
        }
    }
    l.insert_after(forrige, person);
}*/

void insertOrdered(list<Person> &l, Person person){
    for (list<Person>::iterator it=l.begin(); it!=l.end(); it++) {
        if (person < *it){
            l.insert(it, person);
            return;
        }
    }
    l.insert(l.end(), person);
}
