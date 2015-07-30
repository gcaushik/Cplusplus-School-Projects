//Gokul Caushik


#include <iostream>
#include <cstring>
#include "queue.h"
#include "stack.h"

/*The constructor initializes the ptr to NULL*/
queue::queue()
{
   ptr = NULL;
}


/*The enqueue function takes two arguments, the name of the of the patient
to be added and the time of arrival. Both are gotten from the user and 
are passed by reference to this function. The function enqueues a patient, 
in other words adds a queuenode to the CLL and saves the data.*/ 
int queue::enqueue(const char name[], int &time)
{
   if(isempty())		//Queue is empty
   {
      ptr = new queuenode;		//Create new node
      ptr->info.name = new char[strlen(name)+1];	//Allocate memory for the name
      strcpy(ptr->info.name, name);	//Save name
      ptr->info.arrival = time;		//Save time
      ptr->next = ptr;
   }
	
   else
   {
      queuenode *temp = ptr->next;
      ptr->next = new queuenode;
      ptr->next->info.name = new char[strlen(name)+1];
      strcpy(ptr->next->info.name, name);
      ptr->next->info.arrival = time;
      ptr = ptr->next;
      ptr->next = temp;
   }
   return 1;
}


/*The dequeue function takes two arguments, the name array and an int 
variable, which is used to peek at the data that is being dequeued. The 
function deletes the queuenode that was created the earliest. (FIFO)
If the queue is empty it returns false, otherwise it returns 1.
*/
int queue::dequeue(char name[], int &time)
{
   queuenode *temp; 		//temporary pointer
   temp = ptr;
   if(!isempty())		//If queue is empty
   {
      int onenode;		//Flag which is activated if there is only one node in queue
      if(ptr->next == ptr)	//If one node
	 onenode = 1;		//Activate flag
      else
	 onenode = 0;
      queuenode *temp = ptr->next;
      strcpy(name, temp->info.name);	//Peek (save data to be dequeued)
      temp->info.arrival = time;
      ptr->next = temp->next;
      delete temp;
      if(onenode == 1) 		//If one node
         ptr = NULL;		//Make ptr NULL, so queue is empty again
      return 1;
   }
	
   else
      return 0;
}	


/*This function just checks to see if ptr is empty, signifying that the 
queue is empty. It returns true if it is empty and false otherwise.*/
int queue::isempty()
{
   if(!ptr)
      return 1;
   else
      return 0;
}


/*The destructor deallocates all the memory allocated by the enqueue
function. All the nodes are deleted.*/
queue::~queue()
{
   int flag;	//Activated when queue is empty
   if(isempty())
      flag = 0;
   else
   {
      queuenode *temp = ptr->next;
      ptr->next = NULL;
      queuenode *current = temp;
      while(current)
      {
         current = temp->next;
         delete temp;
	 temp = current;
      }		
   }
}
