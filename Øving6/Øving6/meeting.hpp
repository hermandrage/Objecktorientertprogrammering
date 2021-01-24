
#ifndef meeting_hpp
#define meeting_hpp

#include <vector>
#include <stdio.h>
#include <iostream>
#include "car.hpp"
#include "person.hpp"
using namespace std;

enum Campus{TRH, GJO, AAL};

class Meeting{
public:
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject, Person* leader);
    int getDay();
    int getStartTime();
    int getEndTime();
    Campus getLocation();
    string getSubject();
    Person getLeader();
    void addParticipant(const Person* p);
    ~Meeting();
    vector<string> getParticipantList();
    vector<const Person*>findPotentialCoDriving(); 
    
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    vector<const Person*> participants;
    static vector<const Meeting*> meetings;
    //vector<const Meeting*> Meeting::meetings;
    
  
};
ostream& operator<<(ostream& os, const Campus& c);
ostream& operator>>(ostream& os, const Meeting& m);
#endif /* meeting_hpp */ 
