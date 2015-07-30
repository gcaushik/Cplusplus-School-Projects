//Gokul Caushik

//This is the client/application program, so it keeps track of the user
//interface. The task of this program is to receive input from the user 
//and communicate with the class functions through return values. The 
//purpose of this program is to be able to manage a database of pictures 
//(be able to add, remove, retrieve, and display picture data)

#include <iostream>
using namespace std;

#include "tree.h"			
	
int main()
{
   char name[50];	//Holds name of a picture
   char subject[50];	//Holds subject of a picture
   char data[10000];	//Passed on to retrieve function
   tree pictures;	//Instance of tree class
   int num;		//Represents choices for user interface
   int value;	


   cout << "Welcome to your digital picture library!\n";
   cout << "Here you can store, retrieve, and remove picture files." << endl;
   cout << "You can also organize your pictures in different subjects.\n";
   do
   {
      cout << "1. Store a picture\n";
      cout << "2. Retrieve pictures\n";
      cout << "3. Remove a picture\n";
      cout << "4. Display all pictures\n";
      cout << "5. Quit\n"; 
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
	    pictures.store(name, subject);
	    cout << "done.\n";
	    break;
	 case 2:
            cout << "Enter the subject of the picture(s): ";
	    cin.get(subject, 50, '\n');
	    cin.ignore();
	    data[0] = '\0';
	    pictures.retrieve(subject, data);
	    if(data[0] == '\0')			//If large array is empty
	       cout << "No pictures of that subject.\n";
	    else
	    {
	       cout << "Here are your pictures\n";
	       cout << data;
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
	    if(value == 1)
	       cout << "Done.\n";
	    break;
	 case 4:
	    cout << "Here are all of your pictures in sorted order.\n";
	    pictures.display();
	    break;
	 case 5: 
	    cout << "Thanks for accessing the digital picture organizer.";
	    cout << endl;
 	    cout << "Quitting the program...\n";
	    break;
	 default:
	    break;
      }
   }while(num != 5);

   return 0;
	
}
