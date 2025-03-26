#include <iostream>
#include <vector>
#include <string>
#include "Room.h"
using namespace std;
Room::Room(){
}
Room::Room(string code1,string number1,string status1,string tariff1){
    this->code=code1;
    this->number=number1;
    this->status=status1;
    this->tariff=tariff1;
}
string Room::getCode(){
    return code;
}
string Room::getNumber(){
    return number;
}
string Room::getStatus(){
    return status;
}
string Room::getTariff(){
    return tariff;
}
string Room::getFull(){
    return code+";"+number+";"+status+";"+tariff;
}
Room::~Room(){
}