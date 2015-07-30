//Gokul Caushik

#include <iostream>
using namespace std;
#include "graph.h"

int main()
{
   int value, num;	//Value represents the return values for the graph functions, and num represents the user input for the interface
   char course[100];	//Holds course name
   char prereq[100];	//Holds prereq name
   graph major;		//Instance of graph class

   cout << "Welcome to your personal college course organizer!\n";
   cout << "Here you will be able to create a map of the courses\n";
   cout << "needed to get your degree.\n";
   do
   {
      cout << "1. Add a course or change a prerequisite\n";
      cout << "2. Remove course\n";
      cout << "3. Remove prerequisite for a course\n";
      cout << "4. Display degree requirements\n";
      cout << "5. Quit\n";
      cin >> num;
      cin.ignore();
      switch(num)
      {
      case 1:
         cout << "Enter course name: ";
         cin.get(course, 100, '\n');
	 cin.ignore();
	 cout << "Enter prerequisite for course (press @ if no prereq)\n";
	 cin.get(prereq, 100, '\n');	
	 cin.ignore();
	 if(prereq[0] == '@')		//If no prerequisite
         {
            value = major.addreq(course);	//Just add a vertex
	    if(value == 0)
	       cout << "You have added this course already.\n";
	    else
	       cout << "Adding...done.\n";
	 }
	 else				//If there is a prereq
	 {
	    value = major.addcourse(course, prereq);	//Add a vertex and an edge
	    if(!value)
	       cout << "You can't have a prerequsite of a class be itself.\n";
	    if(value == 1 || value == 3)
	       cout << "Operation in progress...done.\n";
	    else if(value == 2 || value == 4)
	       cout << "No prereq found, so adding both prereq and course...done\n";
	    else
	       cout << "Cannot have a duplicates of the same course and prerequisite\n";
         }
         break;
      case 2:
         cout << "Enter course to remove: ";
	 cin.get(course, 100, '\n');
	 cin.ignore();
	 value = major.removecourse(course);
	 if(value == 0)
	    cout << "Sorry, course was not found.\n";
	 else if(value == 1)
	    cout << "Removing course...done\n";
	 break;
      case 3:
         cout << "Enter name of prerequisite: ";
	 cin.get(prereq, 100, '\n');
	 cin.ignore();
	 cout << "Enter name of the course that has this prerequisite\n";
	 cin.get(course, 100, '\n');
	 cin.ignore();
         value = major.removepreq(course, prereq);
	 if(value == 0)
	    cout << "The prerequisite for the course you entered could not be found\n";
	 else
	 {
	    cout << prereq << "is no longer a prerequisite for " << course;
	    cout << endl;
	 }
	 break;
      case 4: 
	 cout << "Here is the map of the course sequence for your degree.\n";
	 major.displayall();
	 break;
      default:
         break;
      }
   }while(num != 5);

   return 0;
}
