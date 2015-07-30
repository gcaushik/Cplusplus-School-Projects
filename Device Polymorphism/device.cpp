//Gokul Caushik

//This is the file that holds all the implementations of the functions
//in the device class.


#include "device.h"

/*The constructor initializes the battery life and the time of
the start of session.*/
device::device()
{
	batlife = 100.0;		//Battery life is at 100%
	start = time(NULL);		//Gets the time when user started the device
}


/*This function does not have any specific purpose, it is only
here to be overrided in the derived classes.*/
int device::menu()
{
	return 1;		
}



/*This function does not have any specific purpose, it is only 
here to be overrided in the derived classes.*/
int device::turnon()
{
	return 1;
}



/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
int device::turnoff()
{
	return 1;
}



/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
int device::battery()
{
	return 1;
}


/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
int device::play()
{
	return 1;
}


/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
void device::displayscreen()
{

}



/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
int device::getinfo()
{
	return 1;
}



/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
int device::add_data()
{
	return 1;
}


/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
int device::remove_data()
{
	return 1;
}


/*This function does not have any specific purpose, it is only here to be 
overrided in the derived classes.*/
device::~device()
{

}
