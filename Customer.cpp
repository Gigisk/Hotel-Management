#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
using namespace std;
Customer::Customer(){  
}
Customer::Customer(string room,string name,string guests,string address,string phone,string nationality,string passport){
   this->room=room;
   this->name=name;
   this->guests=guests;
   this->address=address;
   this->phone=phone;
   this->nationality=nationality;
   this->passport=passport;
}
string Customer::getRoom(){
    return room;
}
string Customer::getName(){
    return name;
}
string Customer::getGuests(){
    return guests;
}
string Customer::getAddress(){
    return address;
}
string Customer::getPhone(){
    return phone;
}
string Customer::getNationality(){
    return nationality;
}
string Customer::getPassport(){
    return passport;
}
string Customer::getFull(){
    return room+";"+name+";"+guests+";"+address+";"+phone+";"+nationality+";"+passport;
}
Customer::~Customer(){
}