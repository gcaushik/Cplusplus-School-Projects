//Gokul Caushik

//This is the header file for all the list class.

#include <iostream>
using namespace std;
#include <string.h>


struct contact
{
	char *name;			//Name of contact
	char *home_number;		//Home Phone #
	char *work_number;		//Work Phone #
	char *cell_number;		//Cell number	
};


struct organizer
{
	char *task;			//Task to be done
};	


struct node
{
	contact *info;			//A contact pointer
	organizer *tasks;		//An organizer pointer
	node *next;
};	


/*The list class manages two lists, the contact list for cellphone contacts, and the
to-do list of tasks for an organizer.*/
class list
{
public:
	list();							//Constructor
	int addcontact(char[], char[], char[], char[]);		//Adds a contact
	int addtask(char[]);					//Adds a task to organizer
	int removedata(int, char[]);				//Removes a task or a contact, depending on index 			
	int searchcontact(char[]);				//Searches for a contact
	void vieworganizer();					//Displays the tasks in organizer
	~list();						//Destructor
private:
	int compare(node *, int, char[]);			//Compares two tasks or two contacts
	node **head;						//An array of lists
};




