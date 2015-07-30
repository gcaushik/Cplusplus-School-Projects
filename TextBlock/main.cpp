//Gokul Caushik

//This is the .cpp file that is the client program. The task of the client
//program is just to receive input from the user and communicate with the 
//class functions through the return values. The purpose of this program 
//is to allow the user to build a block of text and manage it, by either 
//appending to it, deleting parts of the text, and displaying
//the text.

#include <iostream>
using namespace std;
#include <cstring>
#include "list.h"

int main()
{
   list info;			//Instance of the list class
   //num represents the user's input for the user interface, and the condition represents the return values of the functions
   int num, condition;		
   char phrase[1000];		//Holds the phrase that user enters to add text
   char remove[1000];		//Holds the phrase that user enters to remove text
   

   cout << "Welcome to the fun word organizer!\n";
   cout << "You can add and remove text to make fun phrases\n";
   do
   {
      cout << "1. Append Text\n";
      cout << "2. Remove Text\n";
      cout << "3. Display Text\n";
      cout << "4. Quit\n";
      cout << "Press the number of choice and then press enter: ";
      cin >> num;
      cin.ignore();
      switch(num)
      {
         case 1:
	    cout << "Enter phrase to append: ";
	    cin.get(phrase, 1000, '\n');
            cin.ignore();
	    cout << "You entered: " << phrase << endl;
            //Every 9 characters, run the function, so a new node is added every 9 characters
	    for (int i = 0; (9*i) < strlen(phrase); ++i)				
	    {
	       info.append_text(phrase + 9*i);
	    }
            cout << "Phrase has been added.\n";
	    break; 
	 case 2:
	    cout << "Enter phrase to remove: ";
	    cin.get(remove, 1000, '\n');
	    cin.ignore();
	    cout << "You entered: " << remove << endl;
	    condition = info.remove_text(remove);
	    if(condition == 1)
	       cout << "The list is empty: there is nothing to remove.\n";
	    else if (condition == 2 || condition == 3)
	       cout << "Successful: Found and deleted the phrase.\n";
	    else if (condition == 4)
	       cout << "Sorry, no matches were found.\n";
	    break;
	 case 3:
	    cout << "Here is your text:";
	    cout << endl;
	    cout << endl;
	    info.display_all();
            cout << endl;
	    break;
      }		
   }while(num != 4);
   return 0;
}
