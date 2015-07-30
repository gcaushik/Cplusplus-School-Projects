//Gokul Caushik


#include <iostream>
#include <cstring>
#include "queue.h"
#include "stack.h"


/*The constructor initalizes both head and tail pointers to NULL.*/
stack::stack()
{
   head = NULL;
   tail = NULL;
}



/*The push function takes a queue object as an argument passed by 
reference and adds a node to the head of the linear linked list. The queue 
is saved in the node.*/
int stack::push(queue &data)
{
   if(isempty())
   {
      head = new stacknode;		//Create new node
      head->er_patients = data;		//Save data
      head->next = NULL;
      tail = head;
   }
	
   else
   {
      stacknode *temp;		
      temp = new stacknode;
      temp->er_patients = data;
      temp->next = head;
      head = temp;
   }
		
   return 1;	

}


/*The pop function takes no arguments, but returns the queue on top of the 
stack. It returns either the emergency queue or the regular queue to be
operated on.
*/ 		
queue & stack::pop()
{
   stacknode *temp = head;	//Temporary pointer
   if(!isempty())		//If stack is not empty
   {
      head = head->next;	//Traverse head pointer to next node
      return(temp->er_patients);	//Return queue object of the node which is on top of stack
   }
   else
      return(temp->er_patients);	
}


/*This function just checks to see if head == NULL, signifying that the
stack is empty. It returns true if empty and false otherwise.*/
int stack::isempty()
{
   if(!head)
      return 1;
   else
      return 0;
}


/*The destructor deallocates the nodes from the stack. There are always 
two nodes on the stack when this is invoked.*/
stack::~stack()
{
   stacknode *temp = head;
   while(head)
   {
      head = head->next;
      delete temp;
      temp = head;
   }
	
}

