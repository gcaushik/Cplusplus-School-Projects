//Gokul Caushik

//This is the header file for the gps class, containing
//the class interface.


#include <iostream>
using namespace std;
#include <string.h>
#include <time.h>



struct gpsnode
{
	char *location;			//Represents the location
	char *city;			//Represents city of location
	char *state;			//Represents state of location
	gpsnode *next;
};		


/*This class is derived from the device class, and overrides all the 
functions from that class.*/
class gps: public device
{
public:
	gps();				//Constructor
	int menu();			//Menu function
	int turnon();			//Turn GPS on
	int turnoff();			//Turn GPS off
	int battery();			//Check battery life
	int play();			//Use GPS
	void displayscreen();		//Display map
	int getinfo();			//Get info on saved searches for locations
	int add_data();			//Add a search
	int remove_data();		//Clear all searches
	~gps();				//Destructor
protected:
	gpsnode *head;			//Represents user searches for locations
	int gps_life;			//Represents battery life in seconds of GPS
};




