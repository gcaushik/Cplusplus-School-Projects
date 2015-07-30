//Gokul Caushik

//This is the header file for the device class, containing
//the class interface.


#include <iostream>
using namespace std;
#include <iomanip>
#include <string.h>
#include <time.h>

/*This is the common base class device, which contains all virtual functions,
which will be overrided by the functions in the derived classes.*/

class device
{
public:
	device();				//Constructor
	virtual int menu();			//Menu function
	virtual int turnon();			//Function for turning on a device
	virtual int turnoff();			//Function for turning off a device
	virtual int battery();			//Function to check battery life
	virtual int play();			//Operates the device
	virtual void displayscreen();		//Displays to screen
	virtual int getinfo();			//Gets info on product
	virtual int add_data();			//Adds data, such as contacts to list, or locations, or operations for calc to do
	virtual int remove_data();		//Removes data, such as contacts from list, etc.		
	virtual ~device();			//Destructor
protected:
	double batlife;				//Represents the percentage of battery life left for a device
	time_t start;				//Signifies start of session  
};


	
