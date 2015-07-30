//Gokul Caushik


#include <iostream>
using namespace std;
#include <cstring>
#include "queue.h"
#include "stack.h"


int main()
{
   int num;	//Represents the user's choice in the user interface
   int time;	//Holds the time of arrival for a patient
   char name[100];	//Holds the name of the patient
   stack list;		//An instance of a stack
   queue regular, emergency;	//Two queues: emergency + regular


   list.push(regular);		
   list.push(emergency);	//emergency is last in first out

   cout << "This is the medical patient organizer. Here you can" << endl;
   cout << " keep track of all your patients waiting to be and being treated.\n";
   do
   {
      cout << "1. Add a regular patient to waiting list\n";
      cout << "2. Add an emergency patient to list\n";
      cout << "3. Treat a patient(emergency patients priority)\n";
      cout << "4. Quit\n";
      cin >> num;
      cin.ignore();
      switch (num)
      {
         case 1:
	   cout << "Enter name of patient to add: ";
	   cin.get(name, 100, '\n');			//Get name
	   cin.ignore();
	   cout << "Enter time of appointment: ";
	   cin >> time;					//Get time
	   cin.ignore();
	   emergency=list.pop();	//Pop emergency queue
	   regular=list.pop();		//Pop regular queue
	   regular.enqueue(name, time);	//Operate on regular queue
	   list.push(regular);		//Push regular queue back
	   list.push(emergency);	//Push emergency on regular, emergency is always top priority so it is last in first out
	   cout << "Patient has been added to list\n";
	   break;
	 case 2:
	   cout << "Enter name of patient to add: ";
	   cin.get(name, 100, '\n');		
	   cin.ignore();
	   cout << "Enter time of appointment: ";
	   cin >> time;
	   cin.ignore();
	   emergency=list.pop();	//Pop emergency queue
	   emergency.enqueue(name, time);	//Operate on emergency queue
	   list.push(emergency);	//Push emergency back
	   cout << "Emergency patient has been added and is the" << endl;
	   cout << "highest priority.\n";
	   break;
	 case 3:
	   emergency=list.pop();	//Pop emergency queue
	   if(emergency.isempty()) // No one in emergency queue. Go for regular patients.
	   {
	      regular=list.pop();	//Pop regular queue
	      if(!regular.isempty())	//Regular queue is not empty
	      {
	         regular.dequeue(name, time);	//Operate on regular queue
		 cout << "You treated " << name << " from regular queue who came in at " << time;
		 cout << endl;
	      }
		//Both emergency and regular queues are empty
	      else
		 cout << "There is no one to be treated at this time.\n";
	      list.push(regular);	//Push regular first
	      list.push(emergency);	//Push emergency on top
	   }
	   else
	   {
		//Emergency queue is not empty
	      emergency.dequeue(name, time);	//Operate on emergency queue
	      cout << "You treated " << name << " from emergency queue who came in at " << time;
	      cout << endl;
	      list.push(emergency);	//Push emergency back
	   }
	   break;
	 default:	break;
      }
   }while(num != 4);
   return 0;
}
