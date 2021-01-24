
#include "meeting.hpp" 
#include <vector>

vector<const Meeting*>Meeting::meetings;

ostream& operator<<(ostream& os, const Campus& c){
    switch (c) {
        case TRH:
            return os << "Trondheim";
            break;
        case GJO:
            return os << "Gjøvik";
            break;
        case AAL:
            return os << "Ålesund";
            break;
        default:
            break;
    }
    return os; 
}

int Meeting::getDay(){
    return day;
}
int Meeting::getStartTime(){
    return startTime;
}
int Meeting::getEndTime(){
    return endTime;
}
Campus Meeting::getLocation(){
    return location;
}
string Meeting::getSubject(){
    return subject;
}
Person Meeting::getLeader(){
    return *leader;
}
void Meeting::addParticipant(const Person* p){
    //   std::vector<const Person*>::iterator
    for (auto it = participants.begin(); it != participants.end(); it++) {
        if (*p < **it) {
            participants.insert(it, p);
            return;
        }
    }
    participants.push_back(p); 
    //int teller = 0;
    //while((participants[teller]->getName())<(p->getName())){
    //    teller++;
}


Meeting::Meeting(int day, int startTime, int endTime, Campus location, std::string subject, Person* leader)
: day(day), startTime(startTime), endTime(endTime), location(location), subject(subject), leader(leader){
    meetings.push_back(this);
    participants.push_back(leader); 
}
//{
    //this->startTime = startTime;
    //startTime = startTime;
//}
Meeting::~Meeting(){
    for (vector<const Meeting*>::iterator it=meetings.begin(); it!=meetings.end(); it++) {
        if (*it==this) {
            meetings.erase(it);
            break;
        }
    }
}


vector<string> Meeting::getParticipantList(){
    vector<string> navn;
    for (vector<const Person*>::iterator it=participants.begin(); it!=participants.end(); it++) {
        navn.push_back((**it).getName());
    }
    return navn;
}

ostream& operator>>(ostream& os, Meeting& m){
    os << "Subject: " << m.getSubject() << endl << "Location: " << m.getLocation() << endl << "startTime: " << m.getStartTime() << endl << "Endtime: " << m.getEndTime() << endl << "Leader: " << m.getLeader() << endl << "Deltakere: " << endl;
    vector<string> deltagere=m.getParticipantList();
    
    for (vector<string>::iterator it=deltagere.begin(); it!=deltagere.end(); it++) {
        os << *it;
    }
    return os;
}

vector<const Person*>Meeting::findPotentialCoDriving(){
    vector<const Person*>sjofor;
    
    for (vector<const Person*>::iterator it=participants.begin(); it!=participants.end(); it++) {
        if ((**it).hasAvailableSeats()) {
            sjofor.push_back(*it);
        }
    }
    return sjofor;
    
}






