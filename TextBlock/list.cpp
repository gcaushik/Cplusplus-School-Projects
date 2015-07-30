//Gokul Caushik

//This is the  .cpp file that holds all the implementation of the list
//class functions.

#include "list.h"
#include <iostream>
using namespace std;
#include <cstring>


/* The constructor of the list class initializes both head and tail pointers
to NULL, symbolizing that it is an empty list. It also dynamically 
allocates a char array with a size of 1000. This is used for searching
in nodes and inbetween nodes for phrases that the user enters to remove.
 */
list::list()
{
   head = NULL;								
   tail = NULL;
   fullstring = new char[1000];
}



/* The append_text function  is in charge of adding the text that the user
specifies to the list, creating nodes to hold the text. Each node has a text
array that holds a maximum of 9 characters and the null character. The 
function takes one argument, which is the character array holding the phrase
to be added. The function returns 1 when finished, signifying a success.
*/
int list::append_text(char phrase[])
{
   int nodelength;     //Represents the string length of the text array in the node
   if(!tail)			// If tail == NULL, if the list is empty
   {
      tail = new node;			//Create new node
      tail->text = new char[10];	//Create the text array
      strncpy(tail->text, phrase, 9); //Copy the phrase from the user to the array
      tail->text[9] = '\0';		
      nodelength = strlen(tail->text);	
      tail->text[nodelength + 1] = '\0';
      head = tail;			//Head points to first node
      tail->next = NULL;
   }
   else
   {
      tail->next = new node;
      tail = tail->next;
      tail->text = new char[10];
      strncpy(tail->text, phrase, 9);
      tail->text[9] = '\0';
      nodelength = strlen(tail->text);
      tail->text[nodelength + 1] = '\0';
      tail->next = NULL;
   }
   return 1;
}



/* The remove_text function removes the text from the list that the user
specifies. However, it does not delete any nodes. The node count still 
remains the same, but the content in the arrays that the nodes hold will be
altered. If there are no nodes (or an empty list) the function returns 1. 
The function returns 2 if it finds a match in any one of the nodes, and it
returns 3 if it finds a match that spans multiple nodes. If the function
cannot find a matching phrase, it returns 4.
*/
int list::remove_text(char phrase[])
{
   node *current = head; 	//Pointer that traverses through the nodes as the function looks for matches
   node *temp = current;  	//Temporary pointer used in the actual removal of text
   if(!head)
      return 1;			// If the list is empty, return 1
   else
   {
      strcpy(fullstring, current->text);	//Fullstring is a large array that combines all the arrays of the nodes, one by one.
         int flag = 1;				//It is a flag variable that is set to 1 now, but will be set to 0 later on
      while(current)
      {
         int newlength;				//Represents the amount of characters that would remain after phrase is deleted
         char *match = strstr(current->text, phrase);	// Pointer to a match of the phrase in the node
         if(match)
         {
	    newlength = strlen(current->text) - strlen(phrase);	
            for(int i=0; i < newlength; ++i)		//Shifts the contents of the array over, and then array is shortened
	    {
	       char check = *(match + strlen(phrase) + i);		
	       if(check >= 32 && check < 127)
	          match[i] = match[strlen(phrase) + i];
            }
	    current->text[newlength] = '\0';	//Shortens the array, the task is done

	    return 2;										
	    break;
         }
         else
         {
            if(flag != 1)		//Used so it won't combine the array twice 	
	    strcat(fullstring, current->text);		
	    flag = 0;				//Resets flag
            char *overlap = strstr(fullstring, phrase);		//Pointer to a match of the combined string
            if(overlap)
	    {
	       char *ch = fullstring;		//Pointer that points to fullstring[0].		
	       int counter = 0;			//Counts the number of characters up until the match.
	       while(ch != overlap)					
	       {	
	          ++ch;
		  if(counter == strlen(temp->text))	//Traverse nodes once the character pointer has reached the end of the current node
		  {
	             counter = 0;
		     temp = temp->next;
		  }
		  counter++;
	       }
				
	       int charsdeleted = strlen(temp->text) - counter;		//Keeps track of the number of characters to be deleted
	       temp->text[counter] = '\0';			
	       temp=temp->next;	
               //Keeps removing characters from the text array until there are no characters to be deleted
	       while(charsdeleted < strlen(phrase))						 				
	       {
                  //Removes all characters from a node if the phrase spans more than a whole node
	          if((charsdeleted + strlen(temp->text)) < strlen(phrase))	
		  {
		     charsdeleted += strlen(temp->text);					
		     temp->text[0] = '\0';
		     temp = temp->next;
	   	  }

		  else													
		  {
		     int remaining = strlen(phrase) - charsdeleted;	//Represents chars remaining to be deleted in the last node
		     int difference = strlen(temp->text)- remaining;			
		     for (int i=0; i<difference; ++i)
		     {
		        char check = *(temp->text + remaining + i);	//Shifts the contents of the array, then shortens the array
		        if(check >= 32 && check < 127)
		        {
			   temp->text[i] = temp->text[remaining + i];
			}
		     }
		     temp->text[difference] = '\0';
		     return 3;
		     break;
	          }
               }
				
            }
      		           
 
         }
         current = current->next;
      }
      return 4;                          
   }   
}



/*The display_all function ouputs the text in the nodes. No arguments are 
needed for this, is all the function does is display to the screen the 
contents of the text array in each node. If the list is empty, it returns 1 
and if not it returns 2, meaning the operation was successful.
*/
int list::display_all()
{
   if (!head)
      return 1;
   else
   {
      node *current = head;
      while(current)
      {
         cout << current->text;
         current = current->next;
      }
      return 2;
   }
}



/* The destructor deallocates all the memory that was allocated by the 
add_text function.  First, it releases the memory for 
fullstring, and then deletes all the nodes, and the text array for each node.
*/
list::~list()
{
   delete [] fullstring;		//Deallocate memory
   node *temporary = head;		//Temporary pointer
   while(head)
   {
      temporary = temporary->next;
      delete [] head->text;
      delete head;
      head = temporary;
   }
}
