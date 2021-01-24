
#include "car.hpp" 

Car::Car(int freeseats){
    this->freeSeats=freeseats;
}
    
bool Car::hasFreeSeats() const{
    if (freeSeats>0){
        return true;
    }
    return false;
}

void Car::reserveFreeSeat(){
    freeSeats--;
}
