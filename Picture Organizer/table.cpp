//Gokul Caushik


#include "table.h"
#include <cstring>

/*The constructor for the table class allocates memory for the hashtable 
and initializes all the pointers in the hashtable to NULL*/
table::table()
{
   hashtable = new node *[47];	//hashtable size = 47
   for(int i=0; i<47; i++)
   hashtable[i] = NULL;
}


/*The hashfunction takes a subject(char array) as an argument and converts 
that into an index using the ASCII values of the string. It returns the 
index.*/
int table::hashfunction(char subject[])
{
   int num;	//Represents the strlen of subject
   int index=0;	//Initalizes index
   int ascii;	//Holds ascii values for characters in string
   num = strlen(subject);
   for(int i=0; i<num; i++)	
   {
      ascii = subject[i];		
      index += ((2*i+1)*ascii);
   }
   index %= 47;	//Modulus 47 so that index is within the range of the hashtable
   return index;
}



/*The store function takes a subject and filename of picture as arguments 
(both are char arrays), and calls the hashfunction to get an index, then 
uses that index to direct access it and add a node. It copies the filename 
into the node. The function returns 1 when sucessful.*/
int table::store(char subject[], char name[])
{
   int index;		//Holds return value for hashfunction
   index = hashfunction(subject);
   node *temp = hashtable[index];	//Temporary node pointer
   hashtable[index] = new node;		//Allocate memory
   hashtable[index]->name = new char[strlen(name)+1];	//Dynamically allocate array
   strcpy(hashtable[index]->name, name);	
   hashtable[index]->next = temp;	
   return 1;
}


/*The retrieve function gets all the filenames for a particular subject of 
pictures. The arguments are the subject and a large char array. It calls 
the hashfunction, gets the index, goes there, and traverses the nodes, 
adding the filenames for each into the large array. The function returns 
the large character array.*/
char *table::retrieve(char subject[], char data[])
{
   int index;		//Holds return value for hashfunction
   index = hashfunction(subject);	
   node *head = hashtable[index];	//Temp node pointer used for traversal
   strcpy(data, "\0");		
   if(!head)			//if head == NULL
      return data;		
   while(head)
   {
      strcat(data, head->name);		//Add name to large array
      strcat(data, "\n");		//Newline added in for formatting
      head = head->next;		
   }
   return data;
}


/*The remove function takes the filename of the picture and the subject, 
and removes the node with the fileanme. First it calls the hashfunction to 
get the index, then it goes there and traverses the nodes to find a match 
for the filename. If there is a match, it removes the node with that 
filename and returns 1 or 2. If there are no nodes in that index, it 
returns 0. If there are nodes but no matches are found, it returns 3.
*/
int table::remove(char file[], char subject[])
{
   int index;	//Holds return value for hashfunction	
   index = hashfunction(subject);
   node *head = hashtable[index];	//Temp pointer used to traverse
   node *previous = NULL;		//Comes in handy for removal of node
   if(!head)				//head == NULL
      return 0;			
   while(head)				
   {
      if(strcmp(head->name, file) == 0)		//if match
      {
         node *current = head;		//Temp pointer used for deletion of node
	 current = current->next;	
	 delete head;
	 if(previous)			//More than 1 node is in index
	 {
	    previous->next = current;
	    return 1;
	 }
	 hashtable[index] = NULL;	//Only one node is index, set pointer to NULL
	 return 2;
      }
      else				//if no match, traverse
      {
	 previous = head;		
	 head = head->next;
      }
   }
   return 3;
}



/*The destructor deallocates all memory for the hashtable pointers, as 
well as the dynamically allocated arrays for the filenames. The memory for 
the hashtable is also deallcoated.*/
table::~table()
{
   node *temp;
   node *current;
   for(int i=0; i<47; i++)
   {
      temp = hashtable[i];
      while(temp)
      {
         current = temp;
	 temp = temp->next;
	 delete [] current->name;
	 delete current;
      } 
   }
   delete [] hashtable;
}
