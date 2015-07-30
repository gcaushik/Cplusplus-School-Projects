//Gokul Caushik

//This is the implementation file for the list class.


#include "list.h"


/*The constructor initializes the array of lists.*/
list::list()
{
	head = new node *[2];			//Creates a LLL for contact info and LLL for organizer
	for(int i=0; i<2; i++)
		head[i] = NULL;			//Initialize to NULL
}



/*This function adds a contact to the contact list. It takes in the name of 
the contact to be added, the home number, work number, and cell number. A new
node is created which holds the data for the contact. Returns 1 for success.*/
int list::addcontact(char name[], char home[], char work[], char cell[])
{
	node *temp = head[0];					//Holds on to the first node of contact list
	head[0] = new node;			
	head[0]->info = new contact;				//Creates a contact	
	head[0]->tasks = NULL;					//The organizer pointer is NULL, since this is only dealing with contacts
	head[0]->info->name = new char[strlen(name)+1];		//Allocate memory and copy data	
	strcpy(head[0]->info->name, name);
	head[0]->info->home_number = new char[strlen(home)+1];
	strcpy(head[0]->info->home_number, home);
	head[0]->info->work_number = new char[strlen(work)+1];
	strcpy(head[0]->info->work_number, work);
	head[0]->info->cell_number = new char[strlen(cell)+1];
	strcpy(head[0]->info->cell_number, cell);
	head[0]->next = temp;
	return 1;
}



/*This function adds a task to the organizer (the to-do list). It takes a character
array as an argument, and copies it into a new node for the organizer. Returns 1
for success.*/
int list::addtask(char task[])
{
	node *temp = head[1];					//Holds on to first node of organizer
	head[1] = new node;					
	head[1]->info = NULL;					//The contact pointer is NULL, since this is only dealing with tasks
	head[1]->tasks = new organizer;				//Creates an organizer task
	head[1]->tasks->task = new char[strlen(task)+1];	//Allocate memory and copy data
	strcpy(head[1]->tasks->task, task);
	head[1]->next = temp;
	return 1;
}



/*This function takes in two arguments, an int and a character array. The int is the index
of the array of lists from which to remove from, and the char array is the search criteria
(name of contact or task). It searches through the list for a match, and if a match is found,
it deletes the node, and returns 1. If no match is found, it returns 0.*/
int list::removedata(int index, char search[])
{
	node *current = head[index];					//Points to correct list				
	node *previous = NULL;						//Used to trail the current pointer
	
	while(current)
	{
		if(compare(current, index, search) == 1)		//Contact list match
		{
			node *temp = current->next;			
			delete current->info->name;			//Deallocate memory for node
			delete current->info->home_number;			
			delete current->info->work_number;
			delete current->info->cell_number;
			delete current->info;
			delete current;
			current = previous;
			if(previous)
				current->next = temp;
			else
				head[index] = temp;
			return 1;
		}		


		else if(compare(current, index, search) == 2)		//Task match
		{
			node *temp = current->next;				
			delete current->tasks->task;			//Deallocate memory for node
			delete current->tasks;
			delete current;
			current = previous;
			if(previous)
				current->next = temp;
			else
				head[index] = temp;
			return 2;
		}

		else
		{
			previous = current;
			current = current->next;
		}
						
	}		
	
	return 0;							//No match
}	




/*This function allows the user to search for a contact on the contact list. The
function takes in the name of contact specified and traverses the list to 
find a match. If there is a match, the info for the contact is printed to user, and 
then it returns 1. If there is no match, 0 is returned and an error message is 
printed.*/
int list::searchcontact(char name[])
{
	node *current = head[0];
	while(current)	
	{
		if(compare(current, 0, name) == 1)			//If match 
		{
			cout << "Name: " << name << endl;
			if(strlen(current->info->home_number) == 1)		//Check if phone number is N/A
				cout << "Home Phone: N/A\n";
			else
				cout << "Home Phone: " << current->info->home_number << endl;
			if(strlen(current->info->work_number) == 1)		//Check if phone number is N/A
				cout << "Work Phone: N/A\n";
			else
				cout << "Work Phone: " << current->info->work_number << endl;
			if(strlen(current->info->cell_number) == 1)		//Check if phone number is N/A
				cout << "Cell Number: N/A\n";
			else
				cout << "Cell Number: " << current->info->cell_number << endl;
			return 1;
		}

		else
			current = current->next;
	}
	cout << "Could not find contact in list.\n";
	return 0;
	

}



/*This function displays to the user all the tasks in the organizer. It
traverses all the nodes in the to-do list and prints the tasks to user.*/
void list::vieworganizer()
{
	node *current = head[1];			//Points to first node in organizer list
	cout << "Your To-Do List:" << endl;
	while(current)					//Traverse and print					
	{	
		cout << current->tasks->task << endl;		
		current = current->next;
	}
}



/*This is a private function that compares two criteria for a match. It takes in the node
of the source criteria by value, the integer of the index of the list array, and the search
criteria array. Depending on the index specified, it compares the strings. It returns a 1 or 2
if the source and criteria match, and 0 if they don't match. */
int list::compare(node *head, int index, char search[])
{
	int comp;			//Holds the strcmp of the two strings
	if(index == 0)			//If we are comparing two contacts
	{
		comp = strcmp(head->info->name, search);	
		if(comp == 0)					//If the contacts match
			return 1;
		else 
			return 0;
	}

	else				//If we are comparing two tasks
	{
		comp = strcmp(head->tasks->task, search);	
		if(comp == 0)					//If the tasks match
			return 2;			
		else
			return 0;
	}
	
}



/*The destructor deallocates all the dynamic memory for the array of lists.*/
list::~list()
{
	node *temp;				//Temporary pointer

	for(int i=0; i<2; i++)			//For each list
	{
		temp = head[i];				//Point to first node
		while(temp)				//Traverse nodes
		{
			head[i] = head[i]->next;		
			if(i == 0)					//If this is the contact list
			{
				delete temp->info->name;		//Deallocate memory and delete nodes
				delete temp->info->home_number;
				delete temp->info->work_number;
				delete temp->info->cell_number;
				delete temp->info;
				delete temp;
				temp = head[i];
			}

			else						//If this is the organizer list
			{
				delete temp->tasks->task;		//Deallocate memory and delete nodes
				delete temp->tasks;
				delete temp;
				temp = head[i];
			}
		}
	}
}
			
		


						
