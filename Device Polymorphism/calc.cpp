//Gokul Caushik

//This is the implementation file for the calc class.


#include "device.h"
#include "calc.h"


/*The constructor initializes the memory for calculator, the 
battery life of calculator, and the head pointer.*/
calc::calc()
{
	memory = 100000;		//Memory is 100 KB
	calc_life = 1200;		//Battery life is 20 minutes
	head = NULL;			
}



/*The menu function displays a menu and returns the number of 
the choice that the user selected.*/
int calc::menu()
{
	int num;				//Holds the number of the choice on menu that user selects
	do
	{
		cout << "1. Turn calculator off and end session\n";
		cout << "2. Check battery life\n";
		cout << "3. Play apps\n";
		cout << "4. Do operations on calculator\n";
		cout << "5. About this calculator\n";
		cout << "6. Download an app or game\n";
		cout << "7. Remove an app or game\n";
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



/*This function just prints to the user that the calculator
has been turned on. Returns success.*/
int calc::turnon()
{
	cout << "Calculator turned on.\n";
	return 1;
}




/*This function just prints to the user that the calculator is
being turned off and signifies the end of session. Returns
success.*/
int calc::turnoff()
{
	cout << "Turning calculator off\n";
	return 1;
}




/*This function calculates the percentage of battery life still
remaining and prints it out to user. Returns 1 for success.*/
int calc::battery()
{
	double elapsed;			//Represents the time in seconds elapsed since user started device
	time_t check;			//Holds current time		
	
	check = time(NULL);			//Get current time as time_t object
	elapsed = difftime(check, start);	//Elapsed time = Difference between start time and current time
	
	batlife = 100 * ((calc_life - elapsed)/(calc_life));	//Calculates percentage remaining	
	cout << "Battery life is at " << batlife << "%";	
	cout << endl;	
	if(batlife < 20)					//If battery life under 20%
		cout << "Reccomend recharge of batteries\n";
	return 1;
}



/*This function asks the user what app he/she wants to play
and prints it out to screen. If the app specified is not 
found in the calculator, an error message is printed. Returns
1 on success and 0 on error.*/
int calc::play()
{
	char temp[100];					//Temporary array holding the app name
	cout << "Enter name of app to play: ";			
	cin.get(temp, 99, '\n');			//Get app name
	cin.ignore();
	appnode *current = head;			//Used to traverse appnodes to find a match
	while(current)
	{
		if(strcmp(head->name, temp) == 0)	//If the app is on the calculator
		{
			cout << "Playing App: " << temp << endl;		
			return 1;
		}
	}
	cout << "App could not be found\n";		
	return 0;
}




/*Simple function that just displays to screen that
calc did operations.*/
void calc::displayscreen()
{	
	cout << "Did operations on calculator\n";
}




/*This function gets info on the calculator, including
how much memory is left and what apps are taking up the memory, 
and how much memory each app is taking.*/
int calc::getinfo()
{
	cout << "Company: Texas Instruments\n";			//Company
	cout << "Model: TI-84 Plus\n";				//Model
	cout << "Memory remaining: " << memory << endl;		//Memory
	cout << "Apps: " << endl;				//Apps
								
//Traverse appnodes and display info on the apps.
	appnode *current = head;				//Used to traverse
	while(current)			
	{
		cout << current->name;				//Print name of app
		cout << endl;
		cout << current->bytes;				//Print memory it takes up
		cout << endl;
		current = current->next;		
	}
	return 1;
}



/*This function adds an app to the calculator, by getting the name of
the app from the user and storing it in a new appnode. Returns 1 for
success.*/
int calc::add_data()
{
	char temp[100];				//Temporary array holding app name
	int size;				//Holds app size
	cout << "Enter name of app to download:\n";	
	cin.get(temp, 99, '\n');			//Get name
	cin.ignore();			
//To prevent the user from entering too small number of bytes, 
//it is done randomly that generates appropriate number of bytes
	size = 30 * ((time(NULL) % 500) + 1);		//Least memory an app can hold is 30 bytes, most is 15030
	if((memory - size) < 0)				//If not enough memory left on calc to add app
	{
		cout << "Installing this app would cause memory overflow\n";
		return 0;
	}

	appnode *current = new appnode;				
	current->name = new char[strlen(temp)+1];
	strcpy(current->name, temp);
	memory -= size;					//Calculator's free memory gets reduced
	current->bytes = size;			
	current->next = head;				
	head = current;
	return 1;
}	 	




/*This function removes an app from the calculator, by getting the name of the app
from the user and deleting the appnode that has a matching name. Returns 1 on success,
but if match is not found it returns 0.*/
int calc::remove_data()
{
	char temp[100];			//Holds name of app
	cout << "Enter name of app to remove:\n";
	cin.get(temp, 99, '\n');		//Get name
	cin.ignore();			
	appnode *current = head;		//Used to traverse
	appnode *previous = NULL;		//Trailing pointer used to connect
	while(current)
	{	
		if(strcmp(current->name, temp) == 0)		//If match
		{
			appnode *hold = current->next;		
			memory += current->bytes;		//Increase the calculator's free memory
			delete current->name;			//Delete node
			delete current;
			if(previous)
				previous->next = hold;			
			else 
				head = hold;			
			cout << "App removed\n";
			return 1;
		}
		previous = current;				//Traverse
		current = current->next;			//Traverse
	}
	cout << "App not found\n";				//If no match
	return 0;
}		
	


/*The destructor deletes all the appnodes that were allocated
by the user when downloading apps. Effectively this function clears
all memory on the calculator.*/
calc::~calc()
{
	appnode *temp = head;			//Temp pointer 
	while(temp)
	{
		head = head->next;
		delete temp->name;
		delete temp;
		temp = head;
	}
}
