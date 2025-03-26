#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Room.h"
#include "Customer.h"
using namespace std;
///////////////////////////////////////////////// 
//                DISPLAY RECORDS
void DisplayCustomer(){
    string stayOrNo;
    vector <Customer> customerVec;
    do{
        system("clear");
        string number;
        cout<<"Enter room number : "; cin>>number;
        bool check=false;
        int selected=0;
        string word;
        ifstream ifs("customer.txt");
        while(getline(ifs,word)){
            string pirveli,meore,mesame,meotxe,mexute,meeqvse,meshvide;
            pirveli=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meore=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            mesame=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meotxe=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            mexute=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meeqvse=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meshvide=word.substr(0,word.find_first_of(';'));
            
            Customer *c=new Customer(pirveli,meore,mesame,meotxe,mexute,meeqvse,meshvide);
            customerVec.push_back(*c);
        }
        for(int i=0; i<customerVec.size(); i++){
            if(customerVec[i].getRoom()==number){
                check=true;
                selected=i;    
            }
        }
        if(check){
            string part;
            system ("cls");
            cout<<" ______________________________"<<endl;
            cout<<"|        Details               |"<<endl;
            cout<<"|  __________________________  | "<<endl;
            cout<<"| |                          | |"<<endl;
            cout<<"| | Room no.       : "<<customerVec[selected].getRoom()<<endl;
            cout<<"| | Name           : "<<customerVec[selected].getName()<<endl;
            cout<<"| | No. of guests  : "<<customerVec[selected].getGuests()<<endl;
            cout<<"| | Address        : "<<customerVec[selected].getAddress()<<endl;
            cout<<"| | Phone          : "<<customerVec[selected].getPhone()<<endl;
            cout<<"| | Nationality    : "<<customerVec[selected].getNationality()<<endl;
            cout<<"| | Passport no.   : "<<customerVec[selected].getPassport()<<endl;
            cout<<"| |__________________________| |"<<endl;
            cout<<"|______________________________|"<<endl;
        }
        else cout<<"This room doesn't exists!"<<endl;
        cout<<"Do u wish to change more records ( yes- y, no- n) : "; cin>>stayOrNo;
    }
    while(stayOrNo!="n");
}
void DisplayRoom(){
    string stayOrNo;
    vector <Room> roomVec;
    do{
        system("clear");
        string number;
        cout<<"Enter room to be displayed : "; cin>>number;
        bool check=false;
        int selected=0;
        string word;
        ifstream ifs("room.txt");
        while(getline(ifs,word)){
            string pirveli,meore,mesame,meotxe;
            pirveli=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meore=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            mesame=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meotxe=word.substr(0,word.find_first_of(';'));
            Room *r=new Room(pirveli,meore,mesame,meotxe);
            roomVec.push_back(*r);
        }
        for(int i=0; i<roomVec.size(); i++){
            if(roomVec[i].getNumber()==number){
                check=true;
                selected=i;    
            }
        }
        if(check){
            string part;
            system ("clear");
            cout<<" ________________________"<<endl;
            cout<<"|        Details         |"<<endl;
            cout<<"|  _____________________ | "<<endl;
            cout<<"| |                      |"<<endl;
            cout<<"| | Code     :  "<<roomVec[selected].getCode()<<endl;         
            cout<<"| | Room no. :  "<<roomVec[selected].getNumber()<<endl;
            cout<<"| | Status   :  "<<roomVec[selected].getStatus()<<endl;
            cout<<"| | Tariff   :  "<<roomVec[selected].getTariff()<<endl;
            cout<<"| |_____________________ |"<<endl;
            cout<<"|________________________|"<<endl;
            
        }
        else cout<<"This room doesn't exists!"<<endl;
        cout<<"Do u wish to see more records ( yes- y, no- n) : "; cin>>stayOrNo; 
    }
    while(stayOrNo!="n");
}
///////////////////////////////////////////////// 
//                DELETE FILES
void DeleteRoom(){
ofstream ofs;
ofs.open("room.txt");
ofs.clear();
ofs.close();
}
void DeleteCustomer(){
ofstream ofs;
ofs.open("customer.txt");
ofs.clear();
ofs.close();
}
///////////////////////////////////////////////// 
//                REPLACE FILES
void replaceCustomer(string selectedLine, string changedLine){
     ifstream ifs("customer.txt");
    ofstream ofs;
    ofstream deleteOfs;
    deleteOfs.open("fordelete.txt",fstream::app);
    string word;
    while(getline(ifs,word)){
        if(word==selectedLine){
            word=changedLine;
        }
        deleteOfs<<word<<endl;
    }
    deleteOfs.close();
    ofs.open("customer.txt");
    ofs.clear();
    ofs.close();
    ofs.open("customer.txt",fstream::app);
    ifstream deleteIfs("fordelete.txt");
    while (getline(deleteIfs,word)){
        ofs<<word<<endl;  
    }
    ofs.close();
    deleteOfs.open("fordelete.txt");
    deleteOfs.clear();
    deleteOfs.close();
}
void replaceRoom(string selectedLine, string changedLine){
    ifstream ifs("room.txt");
    ofstream ofs;
    ofstream deleteOfs;
    deleteOfs.open("fordelete.txt",fstream::app);
    string word;
    while(getline(ifs,word)){
        if(word==selectedLine){
            word=changedLine;
        }
        deleteOfs<<word<<endl;
    }
    deleteOfs.close();
    ofs.open("room.txt");
    ofs.clear();
    ofs.close();
    ofs.open("room.txt",fstream::app);
    ifstream deleteIfs("fordelete.txt");
    while (getline(deleteIfs,word)){
        ofs<<word<<endl;  
    }
    ofs.close();
    deleteOfs.open("fordelete.txt");
    deleteOfs.clear();
    deleteOfs.close();
}
///////////////////////////////////////////////// 
//                ADDING TO THEIR CHOICE
void AddCustomer(){
    system ("clear"); 
    string room,name,guests,address,phone,nationality,passport;
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       :         | |"<<endl;
    cout<<"| | Name           :         | |"<<endl;
    cout<<"| | No. of guests  :         | |"<<endl;
    cout<<"| | Address        :         | |"<<endl;
    cout<<"| | Phone          :         | |"<<endl;
    cout<<"| | Nationality    :         | |"<<endl;
    cout<<"| | Passport no.   :         | |"<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    bool bl=false;
    do{
      cout<<"Enter the room number : "; cin>>room;
    if(stoi(room)>200){
        cout<<"This room doesn't exists!"<<endl;
    }
    else bl=true;  
    }
    while(bl!=true);
    system ("clear");
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       : "<<room<<endl;
    cout<<"| | Name           :         "<<endl;
    cout<<"| | No. of guests  :         "<<endl;
    cout<<"| | Address        :         "<<endl;
    cout<<"| | Phone          :         "<<endl;
    cout<<"| | Nationality    :         "<<endl;
    cout<<"| | Passport no.   :         "<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    cout<<"Enter the name : "; cin>>name;
    system ("clear");
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       : "<<room<<endl;
    cout<<"| | Name           : "<<name<<endl;
    cout<<"| | No. of guests  :         "<<endl;
    cout<<"| | Address        :         "<<endl;
    cout<<"| | Phone          :         "<<endl;
    cout<<"| | Nationality    :         "<<endl;
    cout<<"| | Passport no.   :         "<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    cout<<"Enter the number of guests : "; cin>>guests;
    system ("clear");
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       : "<<room<<endl;
    cout<<"| | Name           : "<<name<<endl;
    cout<<"| | No. of guests  : "<<guests<<endl;
    cout<<"| | Address        :         "<<endl;
    cout<<"| | Phone          :         "<<endl;
    cout<<"| | Nationality    :         "<<endl;
    cout<<"| | Passport no.   :         "<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    cout<<"Enter the address : "; cin>>address;
    system ("clear");
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       : "<<room<<endl;
    cout<<"| | Name           : "<<name<<endl;
    cout<<"| | No. of guests  : "<<guests<<endl;
    cout<<"| | Address        : "<<address<<endl;
    cout<<"| | Phone          :         "<<endl;
    cout<<"| | Nationality    :         "<<endl;
    cout<<"| | Passport no.   :         "<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    bool check1=false;
    do{
        cout<<"Enter the phone : "; cin>>phone;
        if(phone.size()>8){
            cout<<"Wrong phone number!"<<endl;
        }
        else check1=true;
    }
    while(check1!=true);
    system ("clear");
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       : "<<room<<endl;
    cout<<"| | Name           : "<<name<<endl;
    cout<<"| | No. of guests  : "<<guests<<endl;
    cout<<"| | Address        : "<<address<<endl;
    cout<<"| | Phone          : "<<phone<<endl;
    cout<<"| | Nationality    :         "<<endl;
    cout<<"| | Passport no.   :         "<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    cout<<"Enter the nationality : "; cin>>nationality;
    system ("clear");
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       : "<<room<<endl;
    cout<<"| | Name           : "<<name<<endl;
    cout<<"| | No. of guests  : "<<guests<<endl;
    cout<<"| | Address        : "<<address<<endl;
    cout<<"| | Phone          : "<<phone<<endl;
    cout<<"| | Nationality    : "<<nationality<<endl;
    cout<<"| | Passport no.   :         "<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    cout<<"Enter the passport number : "; cin>>passport;
    system ("clear");
    cout<<" ______________________________"<<endl;
    cout<<"|        Details               |"<<endl;
    cout<<"|  __________________________  | "<<endl;
    cout<<"| |                          | |"<<endl;
    cout<<"| | Room no.       : "<<room<<endl;
    cout<<"| | Name           : "<<name<<endl;
    cout<<"| | No. of guests  : "<<guests<<endl;
    cout<<"| | Address        : "<<address<<endl;
    cout<<"| | Phone          : "<<phone<<endl;
    cout<<"| | Nationality    : "<<nationality<<endl;
    cout<<"| | Passport no.   : "<<passport<<endl;
    cout<<"| |__________________________| |"<<endl;
    cout<<"|______________________________|"<<endl;
    Customer c(room,name,guests,address,phone,nationality,passport);
    ofstream ofs;
    ofs.open("customer.txt",fstream::app);
    ofs<<c.getFull()<<endl;
}
void AddRoom(){
    string addOrNo;
do{

    system ("clear");
    int newchoice1;
    string code,status,tariff;
    string number;
    cout<<" ________________________"<<endl;
    cout<<"|        Details         |"<<endl;
    cout<<"|  ____________________  | "<<endl;
    cout<<"| |                    | |"<<endl;
    cout<<"| | Code     :         | |"<<endl;
    cout<<"| | Room no. :         | |"<<endl;
    cout<<"| | Status   :         | |"<<endl;
    cout<<"| | Tariff   :         | |"<<endl;
    cout<<"| |____________________| |"<<endl;
    cout<<"|________________________|"<<endl;
    cout<<"SS : SINGLE SUITE"<<endl;
    cout<<"DSS : DELUXE SUITE (Single Bed)"<<endl;
    cout<<"DSD : DELUXE SUITE (Double Bed)"<<endl;
    cout<<"PS : PRESIDENTAL SUITE"<<endl;
    cout<<"Enter the room code (SS/DSS/DSD/PS) : "; cin>>code;
    system ("clear");
    cout<<" ________________________"<<endl;
    cout<<"|        Details         |"<<endl;
    cout<<"|  _____________________ | "<<endl;
    cout<<"| |                    "<<endl;
    cout<<"| | Code     :  "<<code<<endl;         
    cout<<"| | Room no. :         "<<endl;
    cout<<"| | Status   :         "<<endl;
    cout<<"| | Tariff   :         "<<endl;
    cout<<"| |_____________________ |"<<endl;
    cout<<"|________________________|"<<endl;
    bool bl=false;
    do{
      cout<<"Enter the room number : "; cin>>number;
    if(stoi(number)>200){
        cout<<"This room doesn't exists!"<<endl;
    }
    else bl=true;  
    }
    while(bl!=true);
    system ("clear");
    cout<<" ________________________"<<endl;
    cout<<"|        Details         |"<<endl;
    cout<<"|  _____________________ | "<<endl;
    cout<<"| |                     "<<endl;
    cout<<"| | Code     :  "<<code<<endl;         
    cout<<"| | Room no. :  "<<number<<endl;
    cout<<"| | Status   :         "<<endl;
    cout<<"| | Tariff   :         "<<endl;
    cout<<"| |_____________________ |"<<endl;
    cout<<"|________________________|"<<endl;
    cout<<"Enter the room status : "; cin>>status;
    system ("clear");
    cout<<" ________________________"<<endl;
    cout<<"|        Details         |"<<endl;
    cout<<"|  _____________________ | "<<endl;
    cout<<"| |                    "<<endl;
    cout<<"| | Code     :  "<<code<<endl;         
    cout<<"| | Room no. :  "<<number<<endl;
    cout<<"| | Status   :  "<<status<<endl;
    cout<<"| | Tariff   :         "<<endl;
    cout<<"| |_____________________ |"<<endl;
    cout<<"|________________________|"<<endl;
    cout<<"Enter the room tariff : "; cin>>tariff;
    system ("clear");
    cout<<" ________________________"<<endl;
    cout<<"|        Details         |"<<endl;
    cout<<"|  _____________________ | "<<endl;
    cout<<"| |                      |"<<endl;
    cout<<"| | Code     :  "<<code<<endl;         
    cout<<"| | Room no. :  "<<number<<endl;
    cout<<"| | Status   :  "<<status<<endl;
    cout<<"| | Tariff   :  "<<tariff<<endl;
    cout<<"| |_____________________ |"<<endl;
    cout<<"|________________________|"<<endl;
    string saveOrNo;
    cout<<"Do you want to save the record (y/n) : "; cin>>saveOrNo;
    if(saveOrNo=="y"){
        Room r(code,number,status,tariff);
        ofstream ofs;
        ofs.open("room.txt",fstream::app);
        ofs<<r.getFull()<<endl;
    }
    cout<<"Do you want to add more record (y/n) : "; cin>>addOrNo;

}
while (addOrNo!="n");

}
///////////////////////////////////////////////// 
//                MODIFYING
void ModifyRoom(){
    string stayOrNo;
    vector <Room> roomVec;
    do{
        system("clear");
        string number;
        cout<<"Enter room number : "; cin>>number;
        bool check=false;
        int selected=0;
        string word;
        ifstream ifs("room.txt");
        while(getline(ifs,word)){
            string pirveli,meore,mesame,meotxe;
            pirveli=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meore=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            mesame=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meotxe=word.substr(0,word.find_first_of(';'));
            Room *r=new Room(pirveli,meore,mesame,meotxe);
            roomVec.push_back(*r);
        }
        for(int i=0; i<roomVec.size(); i++){
            if(roomVec[i].getNumber()==number){
                check=true;
                selected=i;    
            }
        }
        if(check){
            string part;
            system ("clear");
            cout<<" ________________________"<<endl;
            cout<<"|        Details         |"<<endl;
            cout<<"|  _____________________ | "<<endl;
            cout<<"| |                      |"<<endl;
            cout<<"| | Code     :  "<<roomVec[selected].getCode()<<endl;         
            cout<<"| | Room no. :  "<<roomVec[selected].getNumber()<<endl;
            cout<<"| | Status   :  "<<roomVec[selected].getStatus()<<endl;
            cout<<"| | Tariff   :  "<<roomVec[selected].getTariff()<<endl;
            cout<<"| |_____________________ |"<<endl;
            cout<<"|________________________|"<<endl;

            cout<<"Which part do you want to change code/number/status/tariff : "; cin>>part;
            if(part=="code"){
                string newcode;
                cout<<"Enter new code : "; cin>>newcode;
                string changedline = newcode+";"+roomVec[selected].getNumber()+";"+roomVec[selected].getStatus()+";"+roomVec[selected].getTariff();
                string selectedline = roomVec[selected].getFull();
                replaceRoom(selectedline,changedline);
            }
            else if(part=="number"){
                string newnumber;
                cout<<"Enter new number : "; cin>>newnumber;   
                string changedline = roomVec[selected].getCode()+";"+newnumber+";"+roomVec[selected].getStatus()+";"+roomVec[selected].getTariff();
                string selectedline = roomVec[selected].getFull();
                replaceRoom(selectedline,changedline);
            }
            else if(part=="status"){
                string newstatus;
                cout<<"Enter new status : "; cin>>newstatus;
                string changedline = roomVec[selected].getCode()+";"+roomVec[selected].getNumber()+";"+newstatus+";"+roomVec[selected].getTariff();
                string selectedline = roomVec[selected].getFull();
                replaceRoom(selectedline,changedline);
            }
            else if(part=="tariff"){
                string newtariff;
                cout<<"Enter new tariff : "; cin>>newtariff;
                string changedline = roomVec[selected].getCode()+";"+roomVec[selected].getNumber()+";"+roomVec[selected].getStatus()+";"+newtariff;
                string selectedline = roomVec[selected].getFull();
                replaceRoom(selectedline,changedline);
            }
        }
        else cout<<"This room doesn't exists!"<<endl;
        cout<<"Do u wish to change more records ( yes- y, no- n) : "; cin>>stayOrNo; 
    }
    while(stayOrNo!="n");
}
void ModifyCustomer(){
    string stayOrNo;
    vector <Customer> customerVec;
    do{
        system("clear");
        string number;
        cout<<"Enter room number : "; cin>>number;
        bool check=false;
        int selected=0;
        string word;
        ifstream ifs("customer.txt");
        while(getline(ifs,word)){
            string pirveli,meore,mesame,meotxe,mexute,meeqvse,meshvide;
            pirveli=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meore=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            mesame=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meotxe=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            mexute=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meeqvse=word.substr(0,word.find_first_of(';'));
            word=word.substr(word.find_first_of(';')+1);
            meshvide=word.substr(0,word.find_first_of(';'));
            
            Customer *c=new Customer(pirveli,meore,mesame,meotxe,mexute,meeqvse,meshvide);
            customerVec.push_back(*c);
        }
        for(int i=0; i<customerVec.size(); i++){
            if(customerVec[i].getRoom()==number){
                check=true;
                selected=i;    
            }
        }
        if(check){
            string part;
            system ("clear");
            cout<<" ______________________________"<<endl;
            cout<<"|        Details               |"<<endl;
            cout<<"|  __________________________  | "<<endl;
            cout<<"| |                          | |"<<endl;
            cout<<"| | Room no.       : "<<customerVec[selected].getRoom()<<endl;
            cout<<"| | Name           : "<<customerVec[selected].getName()<<endl;
            cout<<"| | No. of guests  : "<<customerVec[selected].getGuests()<<endl;
            cout<<"| | Address        : "<<customerVec[selected].getAddress()<<endl;
            cout<<"| | Phone          : "<<customerVec[selected].getPhone()<<endl;
            cout<<"| | Nationality    : "<<customerVec[selected].getNationality()<<endl;
            cout<<"| | Passport no.   : "<<customerVec[selected].getPassport()<<endl;
            cout<<"| |__________________________| |"<<endl;
            cout<<"|______________________________|"<<endl;
            cout<<"Which part do you want to change"<<endl; 
            cout<<"room/name/guests/address/phone/nationality/passport : "; cin>>part;
            if(part=="room"){
                string newroom;
                cout<<"Enter new room : "; cin>>newroom;
                string changedline = newroom+";"+customerVec[selected].getName()+";"+customerVec[selected].getGuests()+";"+customerVec[selected].getAddress()+";"+customerVec[selected].getPhone()+";"+customerVec[selected].getNationality()
                +";"+customerVec[selected].getPassport();
                string selectedline = customerVec[selected].getFull();
                replaceCustomer(selectedline,changedline);
            }
            else if(part=="name"){
                string newname;
                cout<<"Enter new name : "; cin>>newname;
                string changedline = newname+";"+customerVec[selected].getName()+";"+customerVec[selected].getGuests()+";"+customerVec[selected].getAddress()+";"+customerVec[selected].getPhone()+";"+customerVec[selected].getNationality()
                +";"+customerVec[selected].getPassport();
                string selectedline = customerVec[selected].getFull();
                replaceCustomer(selectedline,changedline);
            }
            else if(part=="guests"){
                string newguests;
                cout<<"Enter new guests : "; cin>>newguests;
                string changedline = newguests+";"+customerVec[selected].getName()+";"+customerVec[selected].getGuests()+";"+customerVec[selected].getAddress()+";"+customerVec[selected].getPhone()+";"+customerVec[selected].getNationality()
                +";"+customerVec[selected].getPassport();
                string selectedline = customerVec[selected].getFull();
                replaceCustomer(selectedline,changedline);
            }
            else if(part=="address"){
                string newaddress;
                cout<<"Enter new address : "; cin>>newaddress;
                string changedline = newaddress+";"+customerVec[selected].getName()+";"+customerVec[selected].getGuests()+";"+customerVec[selected].getAddress()+";"+customerVec[selected].getPhone()+";"+customerVec[selected].getNationality()
                +";"+customerVec[selected].getPassport();
                string selectedline = customerVec[selected].getFull();
                replaceCustomer(selectedline,changedline);
            }
            else if(part=="phone"){
                string newphone;
                cout<<"Enter new phone : "; cin>>newphone;
                string changedline = newphone+";"+customerVec[selected].getName()+";"+customerVec[selected].getGuests()+";"+customerVec[selected].getAddress()+";"+customerVec[selected].getPhone()+";"+customerVec[selected].getNationality()
                +";"+customerVec[selected].getPassport();
                string selectedline = customerVec[selected].getFull();
                replaceCustomer(selectedline,changedline);
            }
            else if(part=="nationality"){
                string newnationality;
                cout<<"Enter new nationality : "; cin>>newnationality;
                string changedline = newnationality+";"+customerVec[selected].getName()+";"+customerVec[selected].getGuests()+";"+customerVec[selected].getAddress()+";"+customerVec[selected].getPhone()+";"+customerVec[selected].getNationality()
                +";"+customerVec[selected].getPassport();
                string selectedline = customerVec[selected].getFull();
                replaceCustomer(selectedline,changedline);
            }
            else if(part=="passport"){
                string newpassport;
                cout<<"Enter new passport : "; cin>>newpassport;
                string changedline = newpassport+";"+customerVec[selected].getName()+";"+customerVec[selected].getGuests()+";"+customerVec[selected].getAddress()+";"+customerVec[selected].getPhone()+";"+customerVec[selected].getNationality()
                +";"+customerVec[selected].getPassport();
                string selectedline = customerVec[selected].getFull();
                replaceCustomer(selectedline,changedline);
            }
        }
        else cout<<"This room doesn't exists!"<<endl;
        cout<<"Do u wish to change more records ( yes- y, no- n) : "; cin>>stayOrNo; 
    }
    while(stayOrNo!="n");
}
///////////////////////////////////////////////// 
//                EDITS
void EditRoom(){
int newchoice;
do{
system ("clear");   
cout<<" __________________________________"<<endl;
cout<<"|             EDIT ROOM            |"<<endl;
cout<<"|  ______________________________  |"<<endl;
cout<<"| |                              | |"<<endl;
cout<<"| | 1: ADD ROOM RECORDS          | |"<<endl;
cout<<"| | 2: MODIFY ROOM RECORDS       | |"<<endl;
cout<<"| | 3: DELETE ROOM RECORDS       | |"<<endl;
cout<<"| | 4: BACK                      | |"<<endl;
cout<<"| |______________________________| |"<<endl;
cout<<"|__________________________________|"<<endl;
cout<<"Enter Your choice: ";    
cin>>newchoice;
if(newchoice==1){
    AddRoom();
    newchoice=-1; 
}
else if(newchoice==2){
    ModifyRoom();
    newchoice=-1;
}
else if(newchoice==3){
    DeleteRoom();
    newchoice=-1;
}

}
while (newchoice!=4);    
}
void EditCustomer(){
int newchoice;
do{
system ("clear");   
cout<<" __________________________________"<<endl;
cout<<"|         EDIT CUSTOMER            |"<<endl;
cout<<"|  ______________________________  |"<<endl;
cout<<"| |                              | |"<<endl;
cout<<"| | 1: ADD CUSTOMER RECORDS      | |"<<endl;
cout<<"| | 2: MODIFY CUSTOMER RECORDS   | |"<<endl;
cout<<"| | 3: DELETE CUSTOMER RECORDS   | |"<<endl;
cout<<"| | 4: BACK                      | |"<<endl;
cout<<"| |______________________________| |"<<endl;
cout<<"|__________________________________|"<<endl;
cout<<"Enter Your choice: ";    
cin>>newchoice;
if(newchoice==1){
    AddCustomer();
    newchoice=-1;
}
else if(newchoice==2){
    ModifyCustomer();
    newchoice=-1;
}
else if(newchoice==3){
    DeleteCustomer();
    newchoice=-1;
}
}
while (newchoice!=4);    
}
///////////////////////////////////////////////// 
//                MAIN MENU
void Edit(int& choice){
int newchoice;
do{
system ("clear");    
cout<<" ___________________________"<<endl;
cout<<"|            EDIT           |"<<endl;
cout<<"|  _______________________  |"<<endl;
cout<<"| |                       | |"<<endl;
cout<<"| | 1: ROOM RECORDS       | |"<<endl;
cout<<"| | 2: CUSTOMER RECORDS   | |"<<endl;
cout<<"| | 3: BACK               | |"<<endl;
cout<<"| |_______________________| |"<<endl;
cout<<"|___________________________|"<<endl;
cout<<"Enter Your choice: "; 
cin>>choice;
system ("clear");
if(choice==1){
EditRoom();

}
if(choice==2){
EditCustomer();
}
}
while (choice!=3);

}
void menu(){
cout<<" __________________________________"<<endl;
cout<<"|  ______________________________  |"<<endl;
cout<<"| |                              | |"<<endl;
cout<<"| | 1: EDIT RECORDS              | |"<<endl;
cout<<"| | 2: DISPLAY ROOM RECORDS      | |"<<endl;
cout<<"| | 3: DISPLAY CUSTOMER RECORDS  | |"<<endl;
cout<<"| | 4: EXIT TO DS                | |"<<endl;
cout<<"| |______________________________| |"<<endl;
cout<<"|__________________________________|"<<endl;
cout<<"Enter Your choice: ";
}
///////////////////////////////////////////////// 
//              MAIN
int main(){
int UserChoice=0;
do{
    system("clear");
    menu();
    cin>>UserChoice;
    if(UserChoice==1){
        int choice1;
        Edit(choice1);
        if(choice1==3){
            UserChoice=-1;
        }
        
    }
    else if(UserChoice==2){
        DisplayRoom();
        UserChoice=-1;
    }
    else if(UserChoice==3){
        DisplayCustomer();
        UserChoice=-1;
    }
}
while(UserChoice!=4);
return 0;
}