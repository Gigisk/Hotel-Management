#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Customer{
protected:
    string room,name,guests,address,phone,nationality,passport;
public:
    Customer();
    Customer(string,string,string,string,string,string,string);
    string getRoom();
    string getName();
    string getGuests();
    string getAddress();
    string getPhone();
    string getNationality();
    string getPassport();
    string getFull();
    ~Customer();
};