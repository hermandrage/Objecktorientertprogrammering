
#include "person.hpp"

Person::Person(string nameValue, string emailValue) :Person(nameValue, emailValue, nullptr){;}
Person::Person(string nameValue, string emailValue, Car *bil) : name(nameValue), email(emailValue), bil(bil) {;}


void Person::setEmail(){
    cout << "Skriv e-mail" << endl;
    cin >> email;
}

string Person::getName()const{
    return name;
}
string Person::getEmail()const{
    return email;
}
bool Person::hasAvailableSeats()const{
    if (bil != nullptr){
        return bil->hasFreeSeats();
    }
    return false;
}
ostream& operator<<(ostream& os, const Person& p){
    //int a = 0;
    os << "Navn: " << p.getName() << endl;
    os << "Epost: " << p.getEmail() << endl;
    os << "Ledige seter: " << boolalpha << p.hasAvailableSeats() << endl;
    return os;
}
bool Person::operator<(const Person& other) const {
    return name<other.getName();
}
bool Person::operator==(const Person& p2) const {
    return getName()==p2.getName();
}
