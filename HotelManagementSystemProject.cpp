#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
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
check1:
if(room.ac!='A' &&room.ac!= 'a' &room.ac!= 'N'&&room.ac!= 'n')
{
    cout<<"You entered wrong choice,\n reenter type of room"<<endl;
    cin>>room.ac;
    goto check1;
}
cout<<"\n  Type Comfort (S/N) : ";
cin>>room.type;
check2:
if(room.type!='S'&&room.type!= 's'&&room.type!= 'N'&&room.type!= 'n')
{
    cout<<"You entered wrong choice,\n reenter comfort type of room"<<endl;
    cin>>room.type;
    goto check2;
}
cout<<"\n  Type Size Big/small(B/S) : ";
cin>>room.stype;
check3:
if(room.stype!='B' && room.stype!='b' && room.stype!='S' && room.stype!= 's')
{
    cout<<"You entered wrong choice,\n reenter size of room"<<endl;
    cin>>room.stype;
    goto check3;
}
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
    cout<<"Room Details :\n";
    if(rooms[i].status==1)
    {
      cout<<"\n Room is reserved.";
    }
    else
    {
      cout<<"\n Room is available.";
      cout<<"\n-------------------------------------------------";
    }
    displayRoom(rooms[i]);
    getch();
  }
  else
  {
    cout<<"\n Room not found!!";
    getch();
  }
}
void Room::displayRoom(Room tempRoom)
{
cout<<left<<setw(38)<<"\nRoom Number"<<":  "<<tempRoom.roomNumber<<endl;
cout<<left<<setw(38)<<"\nAC/Non-AC (A/N)"<<":  "<<tempRoom.ac<<endl;
cout<<left<<setw(38)<<"\nComfort SUITE/NON-SUITE (S/N)"<<":  "<<tempRoom.type<<endl;
cout<<left<<setw(38)<<"\nSize BIG/SMALL (B/S)"<<":  "<<tempRoom.stype<<endl;
cout<<left<<setw(38)<<"\nRent"<<":  "<<tempRoom.rent<<endl;
cout<<"\n-------------------------------------------------";
}   

class HotelMgnt:protected Room
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();
};

void HotelMgnt::guestSummaryReport()
{
  if(count==0)
  {
    cout<<"\n No guest in Hotel!";
  }
  for(int i=0; i<count; i++)
    {
      if(rooms[i].status==1)
      {
cout<<"\n-------------------------------------------------";
cout<<left<<setw(20)<<"\nCustomer First Name  :"<<rooms[i].cust.name<<endl;
cout<<left<<setw(20)<<"\nRoom Number          :"<<rooms[i].roomNumber<<endl;
cout<<left<<setw(20)<<"\nAddress (only city)  :"<<rooms[i].cust.address<<endl;
cout<<left<<setw(20)<<"\nPhone No.            :"<<rooms[i].cust.phone<<endl;
cout<<left<<setw(20)<<"\nEnter Check-In Date  :"<<rooms[i].cust.from_date<<endl;
cout<<left<<setw(20)<<"\nEnter Check-Out Date :"<<rooms[i].cust.to_date<<endl;
cout<<"\n-------------------------------------------------";	
      }
    }
getch();
} 
void HotelMgnt::checkIn()
{
int i,found=0,rno;

class Room room;
cout<<"\n  Enter Room number : ";
cin>>rno;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
if(rooms[i].status==1)
{
cout<<"\n  Room is already Booked.";
getch();
return;
}
cout<<"\n  Enter booking id: ";
cin>>rooms[i].cust.booking_id;

cout<<"\n  Enter Customer Name : ";
cin.ignore();
cin.getline(rooms[i].cust.name,100);

cout<<"\n  Enter Address (only city): ";
//cin>>rooms[i].cust.address;
cin.ignore();
cin.getline(rooms[i].cust.address,100);
  
cout<<"\n  Enter Phone: ";
cin>>setw(10)>>rooms[i].cust.phone;

cout<<"\n  Enter From Date: ";
cin>>rooms[i].cust.from_date;

cout<<"\n  Enter to  Date: ";
cin>>rooms[i].cust.to_date;


cout<<"\n  Enter Advance Payment: ";
cin>>rooms[i].cust.payment_advance;

rooms[i].status=1;

cout<<"\n Customer Checked-in Successfully..";
getch();
}
}
void HotelMgnt::getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
cout<<"\n\n  Press enter for next room";
found=1;
getch();
 }
}
if(found==0)
{
cout<<"\n  All rooms are reserved.";
getch();
}
}
 
void HotelMgnt::searchCustomer(char *pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0)
{
cout<<left<<setw(20)<<"\nCustomer Name        :"<<rooms[i].cust.name<<endl;
cout<<left<<setw(20)<<"\nRoom Number          :"<<rooms[i].roomNumber<<endl;
cout<<left<<setw(20)<<"\nAddress (only city)  :"<<rooms[i].cust.address<<endl;
cout<<left<<setw(20)<<"\nPhone No.            :"<<rooms[i].cust.phone<<endl;
cout<<left<<setw(20)<<"\nEnter Check-In Date  :"<<rooms[i].cust.from_date<<endl;
  
cout<<"\n\n  Press enter for next record";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\n  Person not found.";
getch();
}
}

//CHECKOUT FROM HOTELS
void HotelMgnt::checkOut(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
found=1;
break;
}
}
if(found==1)
{
cout<<"\nEnter Number of Days:\t";
cin>>days;
billAmount=days * rooms[i].rent;

cout<<"\n\t  --------- CheckOut Details ---------\n";
cout<<"\n  Customer Name : "<<rooms[i].cust.name;
cout<<"\n  Room Number : "<<rooms[i].roomNumber;
cout<<"\n  Address : "<<rooms[i].cust.address;
cout<<"\n  Phone : "<<rooms[i].cust.phone;
cout<<"\n  Total Amount Due : "<<billAmount<<" /";
cout<<"\n  Advance Paid: "<<rooms[i].cust.payment_advance<<" /";
cout<<"\n  *** Total Payable: "<<billAmount-rooms[i].cust.payment_advance<<"/ only";

rooms[i].status=0;
}
getch();
}
//managing rooms (adding and searching available rooms)
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
cout<<"\n  ------- Manage Rooms --------";
cout<<"\n  1. Add Room";
cout<<"\n  2. Search Room";
cout<<"\n  3. Back to Main Menu";
cout<<"\n\n  Enter Option: ";
cin>>opt;


//switch statement
switch(opt)
{
case 1:
cout<<"\n  Enter Room Number: ";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
     cout << "\nRoom Number is Present!!!!\nPlease Enter Unique Number..";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
cout<<"\n  Enter room number: ";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
//nothing to do
break;
default:
cout<<"\n  Please Enter correct option";
break;
}
}while(opt!=3);
}
using namespace std;

// MAIN FUNCTION
int main()
{
  class HotelMgnt hm;
  int i,j,opt,rno;
  char ch;
  char pname[100];
  //system("cls");
 do
 {
 system("cls");
 cout<<"  ----------- Hotel Management -------------\n";
 cout<<"\n  1. Manage Rooms";
 cout<<"\n  2. Check-In Room";
 cout<<"\n  3. Available Rooms";
 cout<<"\n  4. Search Customer";
 cout<<"\n  5. Check-Out Room";
 cout<<"\n  6. Guest Summary Report";
 cout<<"\n  7. Exit";
 cout<<"\n\n  Enter Option: ";
 cin>>opt;
 switch(opt)
 {
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout<<"\n  Rooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.checkIn();
break;
case 3:
if(count==0)
{
cout<<"\n  Rooms data is not available.\nPlease add the rooms first.";
getch();
}
else
hm.getAvailRoom();
break;
case 4:
if(count==0)
{
cout<<"\n  Rooms are not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"  Enter Customer Name: ";
cin>>pname;
hm.searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
cout<<"\n  Rooms are not available.\nPlease add the rooms first.";
getch();
}
else
{
cout<<"  Enter Room Number : ";
cin>>rno;
hm.checkOut(rno);
}
break;
case 6:
hm.guestSummaryReport();	
break;
case 7:
cout<<"\n  THANK YOU! FOR USING SOFTWARE";
break;
default:
cout<<"\n  Please Enter correct option";
break;
}
 }while(opt!=7);

  getch();
}

