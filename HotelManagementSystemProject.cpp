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

void Room::searchRoom(int rno)
{
  int i,found=0;
  for(i=0; i<count; i++)
    {
      if(rooms[i].roomNumber==rno)
      {
        found=1;
        break;
      }
    }
  if(found==1)
  {
    cout<<"Room Details\n";
    if(rooms[i].status==1)
    {
      cout<<\n Room is reserved";
    }
    else
    {
      cout<<"\n Room is available";
    }
    displayRoom(rooms[i]);
    getch();
  }
  else
  {
    cout<<"\n Room not found";
    getch();
  }
}

void Room::displayRoom(Room tempRoom)
{
  cout<<"\n Room Number:\t"<<tempRoom.roomNumber;
  cout<<"\n Type AC/Non-AC(A/N)"<<tempRoom.ac;
  cout<<"\n Type Comfort(S/N)"<<tempRoom.type;
  cout<<\"nType size(B/S)"<<tempRoom.stype;
  cout<<"\n Rent:"<<tempRoom.rent;
}
