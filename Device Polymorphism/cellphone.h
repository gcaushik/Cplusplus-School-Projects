//Gokul Caushik

//This is the header file for the cellphone class.


#include <iostream>
using namespace std;
#include <string.h>
#include <time.h>



#include "list.h"

/*The cellphone class is derived from the device class, and overrides
all the functions of the device class. It also has a "has a" relationship
with the list class, which handles the contact list and the organizer list.*/
class cellphone: public device
{
public:
	cellphone();		//Constructor
	int menu();		//Menu function that user can choose operations
	int turnon();		//Turns on cellphone
	int turnoff();		//Turns off cellphone
	int battery();		//Checks battery life of cellphone
	int play();		//Play a ringtone or make a call
	void displayscreen();	//Display the time or the to-do list
	int getinfo();		//Get info on a contact
	int add_data();		//Adds a contact, adds a task to organizer, etc.
	int remove_data();	//Removes a contact, task, etc.
	~cellphone();
protected:
	list co_list;		//Class that handles the contact list and tasks for organizer
	int cell_life;		//Represents battery life in seconds of cellphone
};
