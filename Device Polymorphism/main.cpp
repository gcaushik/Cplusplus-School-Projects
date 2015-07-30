//Gokul Caushik

#include "device.h"
#include "calc.h"
#include "gps.h"
#include "cellphone.h"


int main()
{
	int choice;				//Represents user input for menu
	int num = 0;				//Represents user input for menu
	device *ptr;				//Pointer to base class 
	do
	{
		if(num == 4)					//If user wants to quit
			break;
		cout << "1. Cellphone\n";	
		cout << "2. Calculator\n";
		cout << "3. GPS\n";
		cout << "4. Quit\n";
		cout << "What device do you want to use?\n";
		cin >> num;
		cin.ignore();
		switch(num)
		{
		case 1:
			ptr = new cellphone;			//Dynamically bind ptr to a cellphone object
			break;
		case 2: 
			ptr = new calc;				//Dynamically bind ptr to a calc object
			break;	
		case 3: 
			ptr = new gps;				//Dynamically bind ptr to a gps object
			break;
		default:
			break;
		}
	}while(num < 1 || num > 3);
	
	if(num != 4)
	{
		ptr->turnon();					//Turn on the device
		do
		{
			choice = ptr->menu();			//Call menu function in the object that ptr is pointing to
			switch(choice)
			{
			case 1:
				ptr->turnoff();			//Turn off the device
				break;
			case 2: 
				ptr->battery();			//Check the battery life of device
				break;
			case 3:
				ptr->play();			//Conduct operations on device
				break;
			case 4:
				ptr->displayscreen();		//Display things to screen (depending on device)
				break;
			case 5:
				ptr->getinfo();			//Retrieve/search for data
				break;
			case 6:
				ptr->add_data();		//Add data to device
				break;
			case 7: 
				ptr->remove_data();		//Remove data from device
				break;
			}		
		}while(choice != 1);				//If user wants to turn off device, then quit
		delete ptr;					//Free the memory that was dynamically allocated
	}
	
	return 0;

}
	
	
