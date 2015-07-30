//Gokul Caushik

//This is the implementation file for the cellphone class.



#include "device.h"
#include "cellphone.h"



/*The constructor initializes the battery life of cell phone in seconds.*/
cellphone::cellphone()
{
	cell_life = 600;		//Battery life of cellphone is 10 min
}



/*The menu function gives the user choices to use the cellphone and returns the
number of the choice the user selects.*/
int cellphone::menu()
{
	int num;			//Holds number of the choice that user selects
	do
	{
		cout << "1. Turn cellphone off and end session\n";
		cout << "2. Check battery life\n";
		cout << "3. Make a call or play ringtone\n";
		cout << "4. Display data to screen\n";
		cout << "5. Look up a contact\n";
		cout << "6. Add a contact or task\n";
		cout << "7. Remove a contact or task\n";
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




/*This function just prints to user that the cellphone is
turned on. Returns success.*/
int cellphone::turnon()
{
	cout << "Cellphone is turned on.\n";
	return 1;
}



/*This function just prints to user that the cellphone is 
turned off and ends the session. Returns success.*/
int cellphone::turnoff()
{
	cout << "Cellphone is turned off.\n";
	return 1;
}



/*This function calculates the percentage of battery life left, and based
on the result prints to the user how many bars out of 4 are remaining. Each 
bar represents 25% of battery life. Returns 1 for success.*/
int cellphone::battery()
{
	time_t check;			//Holds current time
	double elapsed;			//Represents time elapsed since start of session
	
	check = time(NULL);			//Gets current time
	elapsed = difftime(check, start);	//Elapsed time = Difference between start and current time

	batlife = 100 * ((cell_life - elapsed)/(cell_life));	

	if(batlife < 25)			//If less than one quarter of battery life
		cout << "One bar\n";	
	else if(batlife < 50)			//If less than one half of battery life
		cout << "Two bars\n";
	else if(batlife < 75)			//If less than three fourths battery life
		cout << "Three bars\n";
	else
		cout << "Four bars\n";		//If more than three fourths battery life
	return 1;
}



/*The play function displays a menu which allows user to either play a ringtone or make a call.
The ringtone is just a print statement and make call just gets the phone number 
to call from user and prints it. Returns 1 for success.*/
int cellphone::play()
{
	int num;			//Holds number of choice user selects
	do
	{
		cout << "1. Play ringtone\n";
		cout << "2. Make a call\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 2);
	
	if(num == 1)	
		cout << "Played ringtone\n";
	else 	
	{
		char telenumber[11];			//Holds number user is calling
		cout << "Enter number of person who you are calling.\n";	
		cin.get(telenumber, 11, '\n');		//Get number
		cin.ignore();		
		cout << endl;				
		cout << "You called " << telenumber << endl;
	}
	return 1;
}



/*This function displays a menu that allows user to view the tasks for organizer or display
the time.*/
void cellphone::displayscreen()
{
	int num;			//Holds number of choice user selects
	do
	{	
		cout << "1. View organizer\n";
		cout << "2. Display time\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 2);
	if(num == 1)
		co_list.vieworganizer();			//Call vieworganizer() function from the "has a" class
	else
	{
		time_t current;					//Holds the current time
		tm *parameters;					//Structure that holds all the parameters for the current time	
	
		current = time(NULL);					//Get current time as a time_t object
		parameters = localtime(&current);			//Get local time and store paramters into the structure
		cout << "Year: " << parameters->tm_year + 1900 << endl;			//Display year
		cout << parameters->tm_mon + 1 << "/" << parameters->tm_mday << endl;	//Display Month and Day of Month
		if(parameters->tm_min < 10)
			cout << parameters->tm_hour << ":" << "0" << parameters->tm_min << endl;	//Display Hours and Minutes
		else	
			cout << parameters->tm_hour << ":" << parameters->tm_min << endl;		//Display Hours and Minutes
		if(parameters->tm_isdst)							//If DST
			cout << "(DST)\n";							
	}
}
	


/*This function prints out info on a contact to the user. It returns 1 for success.*/
int cellphone::getinfo()
{
	char temp[100];				//Holds name of contact
	cout << "Enter the name of contact: ";
	cin.get(temp, 101, '\n');		//Get name
	cin.ignore();
	co_list.searchcontact(temp);		//Search for contact
	return 1;				
}
	


/*This function displays a menu in which user adds a contact to the contact list 
or adds a task to organizer. The data for the contact or the task is gotten from 
the user and a new node is created and the data is stored. It returns 1 for success.*/
int cellphone::add_data()
{
	int num;			//Holds number of choice that user selects
	do
	{
		cout << "1. Add a contact\n";
		cout << "2. Add a task to organizer\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 2);
	

	if(num == 1)				//Add a contact
	{	
		char temp[100];			//Holds name of contact to add	
		char home[11];			//Holds home # of contact to add
		char work[11];			//Holds work # of contact to add
		char cell[11];			//Holds cell # of contact to add
		cout << "Enter name of contact to add: ";		
		cin.get(temp, 101, '\n');				//Get name
		cin.ignore();
		cout << "Enter contact home phone (if N/A, type 0): ";
		cin.get(home, 11, '\n');				//Get home #
		cin.ignore();
		cout << "Enter contact work phone (if N/A, type 0): ";
		cin.get(work, 11, '\n');				//Get work #
		cin.ignore();
		cout << "Enter contact cell phone number (if N/A, type 0): ";
		cin.get(cell, 11, '\n');				//Get cell #	
		cin.ignore();
		co_list.addcontact(temp, home, work, cell);		//Add the contact
	}

	else								//Add task
	{
		char task[100];						//Holds task
		cout << "Enter a task to your to-do list:\n";		
		cin.get(task, 99, '\n');				//Get task
		cin.ignore();
		co_list.addtask(task);					//Add task
	}

	return 1;
}
	



/*This function displays a menu in which the user can either remove a contact from
the contact list or remove a task from the organizer. The name of the contact or the 
task is gotten from user and a the function looks for a match in the nodes. If there is
a match, the node and the data for the contact/task is deleted. 
If there is no match, it retuns an error message. The function returns 1.*/
int cellphone::remove_data()
{
	int num;				//Holds number of choice that user selects
	do
	{
		cout << "1. Remove a contact\n";
		cout << "2. Remove a task from organizer\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 2);

	if(num == 1)							//Remove a contact
	{
		char temp[100];						//Holds name of contact to remove
		cout << "Enter name of contact to remove: ";
		cin.get(temp, 99, '\n');				//Get name
		cin.ignore();
		if(co_list.removedata(0, temp) == 0)			//If no match
			cout << "Contact could not be found\n";
		else							//If match, remove data
			cout << "Contact removed from list.\n";
	}
	
	else								//Remove a task
	{
		char task[100];						//Holds name of task
		cout << "Enter task to remove:\n";
		cin.get(task, 99, '\n');				//Get task
		cin.ignore();
		if(co_list.removedata(1, task) == 0)			//If no match
			cout << "Task could not be found\n";
		else							//If match, remove data
			cout << "Task removed from to-do list\n";
	}

	return 1;
}





/*The destructor does not have any dynamic memory to deallocate.*/
cellphone::~cellphone()
{
	
}
