//Gokul Caushik

#include "graph.h"
#include <iostream>
using namespace std;
#include <cstring>


/*The constructor allocates the memory for the vertices and initializes 
all their head pointers to NULL.*/
graph::graph()
{
   numofvertices = 0;	//Keeps track of the number of vertices in the graph
   degree = new vertex[20];	//Allocate memory for 20 vertices
   for (int i=0; i<20; i++)
   {
      degree[i].head = NULL;	//Initialize head pointers to NULL
   }
}



/*The addreq function takes in a course name, adds a vertex, and copies 
this information to it. If the course has been added already, then it 
returns 0, otherwise it returns 1.*/
int graph::addreq(char req[])
{
   for(int i=0; i<numofvertices; i++)	
   {
      if(strcmp(degree[i].requirements, req) == 0)	// If vertex has already been added
         return 0;
   }
   degree[numofvertices].requirements = new char[strlen(req)+1];
   strcpy(degree[numofvertices].requirements, req);
   ++numofvertices;
   return 1;
}



/*The addcourse function takes in a course and its prerequisite as 
arguments. It adds a vertex and an edge, and copies the name of the course 
to the edge node and the prerequisite name to the vertex. It returns 0 if 
the prerequisite and the course are the same, returns 1-4 if the course 
gets added, and returns 5 if there are any duplicates.*/
int graph::addcourse(char course[], char prereq[]) 
{
   int compare, compare2;	//Compare the prereq and course to the vertices
   int reqflag = 0;		//Activated if there is a match for prereq in vertex
   int courseflag = 0;		//Activated if there is a match for course in vertex
   if(strcmp(course, prereq) == 0)	//If prereq and course are the same
      return 0;
   for(int i=0; i<numofvertices; i++)
   {
      compare = strcmp(degree[i].requirements, prereq);	
      compare2 = strcmp(degree[i].requirements, course);
      if(courseflag == 0 && compare2 == 0)	//If match for course
	 courseflag = 1;			//Activate course flag
      if(reqflag == 0 && compare == 0)		//If match for prereq
      {
         reqflag = 1;				//Activate reqflag
         node *current = degree[i].head;	//Used to traverse the adjacency list to see if there are duplicates for course
	 node *temp = current;
	 while(temp)				
	 {
	    if(strcmp(current->course, course)== 0)	//If duplicate for course
	       return 5;
            temp = temp->next;
	 }
         degree[i].head = new node;			//Add the course to the adjacency list
	 degree[i].head->course = new char[strlen(course)+1];
	 strcpy(degree[i].head->course, course);
	 degree[i].head->next = current;
      }
      if(reqflag && courseflag)		//If course has been added
	 return 1;
   }

   if((reqflag && !courseflag) || (!reqflag && !courseflag))	//If no matches found or no course match
   {
      degree[numofvertices].requirements = new char[strlen(course)+1];	//Add vertex
      strcpy(degree[numofvertices].requirements, course);
      ++numofvertices;
      if(reqflag && !courseflag)	
         return 3;
   }
   degree[numofvertices].requirements = new char[strlen(prereq)+1];	//Add vertex and course
   strcpy(degree[numofvertices].requirements, prereq);
   degree[numofvertices].head = new node;
   degree[numofvertices].head->course = new char[strlen(course)+1];
   strcpy(degree[numofvertices].head->course, course);
   degree[numofvertices].head->next = NULL;
   ++numofvertices;
   return 2;
}



/*The removecourse function takes in a course as an argument and removes 
it from the graph. This means removing a vertex and all edges containing 
the course. It returns 0 if the course to be removed is not found, 
otherwise it returns 1.*/
int graph::removecourse(char course[])
{
   node *current;		//These three node pointers are used to delete a node, whether it be in the beginning, middle, or end
   node *temp;
   node *previous;
   int compare;			//Compares course to the vertex
   int deleteflag = 0;		//Activated when traversing through last vertex
   int counter = 0;		//Counts matches
   for(int i=0; i<numofvertices; i++)	
   {
      if(i == numofvertices-1)		
	 deleteflag = 1;
      compare = strcmp(degree[i].requirements, course);
      if(compare == 0 || (deleteflag == 1 && counter > 0))	//If there is a match or match has already been found but it is not the last vertex
      {
	 counter++;
	 current = degree[i].head;
	 temp = current;
	 while(current)		//Destroy the adjacency list
	 {
	    current = temp->next;
	    delete temp->course;
	    temp->course = NULL;
	    delete temp;
	    temp = current;
	 }
	 degree[i].head = NULL;
	 if(deleteflag == 0)		//If match is not found in the last node
	 {	
	    strcpy(degree[i].requirements, degree[numofvertices-1].requirements);
	    copy(degree[i].head, degree[numofvertices-1].head);
	 }
      }

      else
      {
         current = degree[i].head;	
         previous = NULL;
	 while(current)			//Search adjacency list for node to delete
	 {
	    if(strcmp(current->course, course) == 0)	//If match for node for course
            {
	       counter++;
	       node *temp = current;		
	       current = current->next;
	       delete temp->course;		//Delete course (same as removing an edge)
	       delete temp;
	       if(previous)
	       {
	          previous->next = current;
	       }
	       else
		  degree[i].head = current;
            }
	    else			//Traverse
	    {
	       previous = current;
	       current = current->next;
	    }
         }
      }
   }
   if(counter == 0)		//If no matches were found
      return 0;
   else
   {
      --numofvertices;		//Decrement number of vertices
      return 1;
   }
}



/*The removepreq function takes in a course and a prerequisite and 
searches the vertices for a match for prereq, and then searches its 
adjacency list for a match for the course. If there is a match, it deletes 
the course (deletes an edge). It returns 0 if no matches are found and 
returns 1 or 2 if the edge is removed. */
int graph::removepreq(char course[], char prereq[])
{
   int compare;		//Compares prereq to the vertex
   for(int i=0; i<numofvertices; i++)
   {
      compare = strcmp(degree[i].requirements, prereq);
      if(compare == 0)		//If there is a match
      {
         node *current = degree[i].head;	//Used to remove the edge
	 node *previous = NULL;
	 while(current)
	 {
	    if(strcmp(current->course, course) == 0)	//If match for course
	    {
	       node *temp = current;		
	       current = current->next;		
	       delete temp;			//Remove the edge
	       if(previous)
	       {
	          previous->next = current;
		  return 1;
	       }
	       degree[i].head = current;
	       return 2;
            }
	    else			//Keep traversing
	    {
	       previous = current;
	       current = current->next;
	    }
         }
      }
   }
   return 0;
}



/*The copy function takes the head pointer for a vertex by reference and 
the head pointer from the last vertex. It recursively copies the LLL from 
the last vertex to the vertex that has been deleted. It returns 1 for 
success and 0 if there is an empty LLL. */
int graph::copy(node *&newhead, node *oldhead)
{
   if(!oldhead)		//If adjacency list is empty
   {
      newhead = NULL;
      return 0;
   }
   newhead = new node;		
   if(!newhead)
      return 0;		
   strcpy(newhead->course,oldhead->course);	//Copy data
   copy(newhead->next, oldhead->next);		//Recursive call 
   return 1;
}



/*The displayall function does not take any arguments and display all the 
vertices and their respective adjacency lists. There is no return type for 
this function.*/
void graph::displayall()
{
   node *current;		//Used to traverse and display
   for(int i=0; i<numofvertices; i++)
   {
      cout << "You need ";	
      cout << degree[i].requirements;	//List the vertices
      cout << " so you can take:";
      cout << endl;
      current = degree[i].head;
      if(!current)		//If adjacency list is empty
	 cout << "No classes listed\n";
      while(current)			//List the edges
      {
         cout << current->course;
         cout << endl;
         current = current->next;
      }
   }
}
	


/*The destructor deallocates all the memory for the graph. It deletes all 
the vertices and destroys all the adjacency lists.*/
graph::~graph()
{
   node *current;
   for(int i=0; i<numofvertices; i++)	
   {
      delete degree[i].requirements;		//Deallocate memory for vertex
      current = degree[i].head;			
      while(current)				//Destroy the adjacency list
      {
         degree[i].head = degree[i].head->next;
	 delete current->course;
	 delete current;
	 current = degree[i].head;
      }
   }
}
