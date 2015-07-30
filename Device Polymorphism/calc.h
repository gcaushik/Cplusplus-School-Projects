//Gokul Caushik

//This is the header file for the calc class, containing
//the class interface.


#include <iostream>
using namespace std;
#include <string.h>
#include <time.h>
#include <iomanip>


struct appnode				//Holds the data for a calculator application
{
	int bytes;			//Size in bytes
	char *name;			//Name of app
	appnode *next;		
};


/*This class is derived from the base class device, and overrides
all the functions in the base class.*/
class calc: public device
{
public:
	calc();				//Constructor
	int menu();			//Menu function showing what to do on calculator
	int turnon();			//Turn on device
	int turnoff();			//Turn off device
	int battery();			//Check battery life
	int play();			//Play an app
	void displayscreen();		//Do some operations on calculator
	int getinfo();			//Get info about calculator
	int add_data();			//Download an app
	int remove_data(); 		//Remove an app
	~calc();			//Destructor
protected:
	int memory;			//Represents amount of memory in calculator	
	appnode *head;
	int calc_life;			//Represents battery life of calculator in seconds

};	
