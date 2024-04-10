#include<iostream>
#include<string.h>
#define max 100
using namespace std;

//Class Customer
class Customer
{
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
}; 

class Room
{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;

class Customer cust;
class Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
}; 


//Global Declarations
class Room rooms[max];
int count=0;


Room Room::addRoom(int rno)
{
class Room room;
room.roomNumber=rno;
cout<<"\n  Type AC/Non-AC (A/N) : ";
cin>>room.ac;
cout<<"\n  Type Comfort (S/N) : ";
cin>>room.type;
cout<<"\n  Type Size (B/S) : ";
cin>>room.stype;
cout<<"\n  Daily Rent : ";
cin>>room.rent;
room.status=0;

cout<<"\n  Room Added Successfully!";
getch();
return room;
}
