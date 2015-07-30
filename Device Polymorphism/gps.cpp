//Gokul Caushik

//This is the implementation file for the gps class.


#include "device.h"
#include "gps.h"


/*The constructor initializes the head gpsnode to NULL and 
the battery life of the GPS in seconds.*/
gps::gps()
{	
	head = NULL;		
	gps_life = 900;		//Battery life of GPS is 15 min
}



/*The menu function gives the user choices for using the GPS
and returns the number of the choice that the user selected.*/
int gps::menu()
{
	int num;		//Holds number of choice
	do
	{
		cout << "1. Turn GPS off and end session\n";
		cout << "2. Check battery life\n";
		cout << "3. Use the GPS while going out on a drive\n";
		cout << "4. Display map\n";
		cout << "5. See search history\n";
		cout << "6. Look up a location\n";
		cout << "7. Clear search history\n";
		cin >> num;
		cin.ignore();
		switch(num)
		{
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:	
			return 4;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 6;
			break;
		case 7:
			return 7;
			break;
		}
	}while(num < 1 || num > 7);
	return 0;
}



/*This function just prints to user that GPS is turned on.
Returns success.*/
int gps::turnon()
{
	cout << "GPS is turned on.\n";
	return 1;
}



/*This function just prints to user that GPS is turning off
and ending the session. Returns success.*/
int gps::turnoff()
{
	cout << "GPS is turning off.\n";
	return 1;
}



/*This function calculates the percentage of battery life remaining
and prints it to user. It returns 1 for success.*/
int gps::battery()
{
	double elapsed;			//Represents the time in seconds elapsed from start of session
	time_t check;			//A time_t object
	
	check = time(NULL);			//Get current time
	elapsed = difftime(check, start);	//Time Elapsed = Difference in seconds between start time and current time
	batlife = 100 * ((gps_life - elapsed)/(gps_life));	//Get percentage	

	cout << "Battery life is at " << batlife << "%";
	cout << endl;
	return 1;
}



/*The play function just prints or "says" to user that the user reached
their destination. Returns success.*/
int gps::play()
{
	cout << "You have reached your destination!\n";
	return 1;
}



/*This function just prints that the map has been displayed. For time
reasons, an acutal map could not be displayed.*/
void gps::displayscreen()
{
	cout << "Displayed map\n";
}



/*This function gets all the previous searches by user and displays them.
Returns 1 for success.*/
int gps::getinfo()
{
	gpsnode *current = head;		//Temp pointer used to traverse
	cout << "Saved locations: " << endl;
	while(current)
	{		
		cout << current->city << ", " << current->state << "-- ";	//Display city, state
		cout << current->location << endl;			//Display location
		current = current->next;
	}
	return 1;
}	


/*This function allows the user to search for a location, and it saves the search
by storing the info in a new gpsnode. Returns 1 for success.*/
int gps::add_data()
{
	char loc[100];				//Holds location
	char tempcity[100];			//Holds city of location
	char tempstate[100];			//Holds state of location
	cout << "Enter a location.\n";
	cin.get(loc, 99, '\n');			//Get location
	cin.ignore();
	cout << "Enter the city\n";
	cin.get(tempcity, 99, '\n');		//Get city
	cin.ignore();
	cout << "Enter the state\n";
	cin.get(tempstate, 99, '\n');		//Get state
	cin.ignore();
	gpsnode *temp = head;			//Used to create a new gpsnode
	head = new gpsnode;
	head->location = new char[strlen(loc)+1];	//Store data
	strcpy(head->location, loc);
	head->city = new char[strlen(tempcity)+1];
	strcpy(head->city, tempcity);
	head->state = new char[strlen(tempstate)+1];
	strcpy(head->state, tempstate);
	head->next = temp;
	return 1;
}
		



/*This function clears all searches. Effectively, this is the destructor.
Returns 1.*/		
int gps::remove_data()
{
	gpsnode *temp = head;
	while(temp)
	{
		head = temp->next;
		delete [] temp->location;
		delete [] temp->city;
		delete [] temp->state;
		delete temp;
		temp = head;
	}
	return 1;
}



/*The destructor calls the remove_data function to deallocate memory for all
the gpsnodes.*/
gps::~gps()
{
	remove_data();
}
