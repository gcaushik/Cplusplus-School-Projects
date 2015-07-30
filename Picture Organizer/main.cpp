//Gokul Caushik


#include <iostream>
using namespace std;
#include <cstring>
#include "table.h"


int main()
{
   int num;	//Keeps track of user's input in the user interface
   int value;	//Used to store return values of the class functions
   table pictures;	
   char data[1000];	//Large character array used in retreive function
   char name[50];	//Holds filename of picture
   char subject[50];	//Holds subject of picture
   cout << "Welcome to your digital picture library!\n";
   cout << "Here you can store, retrieve, and remove picture files." << endl;
   cout << "You can also organize your pictures in different subjects.\n";
   do
   {
      cout << "1. Store a picture\n";
      cout << "2. Retrieve pictures\n";
      cout << "3. Remove a picture\n";
      cout << "4. Quit\n";
      cin >> num;
      cin.ignore();
      switch(num)
      {
      case 1:
         cout << "Enter the name of the picture: ";
	 cin >> name;
	 cin.ignore();
	 cout << "Enter the subject of the picture: ";
	 cin.get(subject, 50, '\n');
	 cin.ignore();
	 cout << endl;
	 cout << "storing picture...";
	 pictures.store(subject, name);
	 cout << "done.\n";
	 break;
      case 2:
	 cout << "Enter the subject of the picture(s): ";
	 cin.get(subject, 50, '\n');
	 cin.ignore();
	 pictures.retrieve(subject, data);
	 if(data[0] == '\0')			//If the large array has nothing in it
	    cout << "No pictures of that subject.\n";
	 else
	 {
	    cout << "Here are your pictures\n";
	    cout << data;			//Display the array
         }	
	 break;
      case 3: 
         cout << "Enter the name of the picture to remove: ";
	 cin >> name;
	 cin.ignore();
	 cout << "Enter the subject of the picture: ";
	 cin.get(subject, 50, '\n');
	 cin.ignore();
	 value = pictures.remove(name, subject);
	 if(value == 0)
 	    cout << "There are no pictures of that subject.\n";
	 else if(value == 1 || value == 2)
	    cout << "Successfully removed file.\n";
	 else
	    cout << "Could not find the file\n";
	 break;
      case 4: 
	 cout << "Thanks for accessing the digital picture organizer.";
	 cout << endl;
	 cout << "Quitting the program...\n";
	 break;
      default:
         break;
      }
   }while(num != 4);
   return 0;
}
