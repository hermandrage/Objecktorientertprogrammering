

#include <iostream>
using namespace std;
#include "car.hpp" 
#include "person.hpp" 
#include "meeting.hpp"

int main(){
    
    Car NissanMicra(4);
    Car SAAB(3);
    Person simen("Simen","simen@stud.ntnu.no", &NissanMicra);
    cout << simen;
    
    Person Herman("Herman","hermandr@stud.ntnu.no", &SAAB);
    Person Magne("Magne","Magne@ntnu.no");
    Person OJ("OJ","OJ@ntnu.no");
    Meeting meet1(1,10,12,TRH,"Tull",&simen);
    Meeting meet2(1,11,13,TRH,"Fjas",&simen);
    Meeting meet3(1,12,14,AAL,"Tøys",&Magne);
    meet1.addParticipant(&Herman);
    meet1.addParticipant(&Magne);
    cout << "potential codriver" << endl;
    for (auto p : meet1.findPotentialCoDriving()) {
        cout << *p << endl;
    }
    //meet1.findPotentialCoDriving();
    //meet1.meetings.clear()
    
    
    return 0;
}
