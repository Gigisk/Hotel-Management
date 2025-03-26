#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room{
protected:
    string code;
    string number;
    string status;
    string tariff;
public:
    Room();
    Room(string,string,string,string);
    string getCode();
    string getNumber();
    string getStatus();
    string getTariff(); 
    string getFull();
    ~Room();

};