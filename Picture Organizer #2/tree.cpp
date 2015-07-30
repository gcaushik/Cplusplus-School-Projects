//Gokul Caushik

#include <iostream>
using namespace std;
#include <cstring>
#include "tree.h"

/* The constructor of the tree class initializes the root node pointer to 
NULL, symbolizing an empty tree.*/
tree::tree()
{
   root = NULL;
}


/* The store function is a private function that takes in 3 arguments, the 
root node pointer by reference, the name of the picture, and the subject 
of the picture. It is in charge of finding the appropriate place to add 
the node,and copy the name and the picture to its contents. The tree is 
sorted by alphabetical order of name. It returns an int representing 
success. NOTE: This is a recursive function */
int tree::store(node *&root, char name[], char subject[])
{
   if(!root)
   {
      root = new node;					//Create node
      root->name = new char[strlen(name)+1];		//Allocate memory for name
      strcpy(root->name, name);				//Copy data
      root->subject = new char[strlen(subject)+1];	//Allocate memory for subject
      strcpy(root->subject, subject);			//Copy data
      root->left = NULL;
      root->right = NULL;
      return 1;
   }

   else if(strcmp(name, root->name) > 0)	//If name is farther in the alphabet than the root
      return store(root->right, name, subject);	//Recursive traversal to right
   else
      return store(root->left, name, subject);	//Recursive traversal to left

}


/* This is the public function for store, and all it does is take the 
subject and name of the picture and pass those on by calling its wrapper 
function (which is explained above).*/
void tree::store(char name[], char subject[])
{
   store(root, name, subject);
}



/*The retrieve function takes in the root node pointer by value, and the 
subject and a retrieval array by reference. The function searches the BST 
for all matches of the subject, and for every node that matches it 
concatenates the retrieval array with the picture name for that node. The 
retrieval array is formatted for user friendliness(with newlines inbetween 
the names) and returned. This is also a recursive function. */
char * tree::retrieve(node *root, char subject[], char retrieval[])
{
   int num;
   if(root)
   {
      retrieve(root->left, subject, retrieval);	//Go to left subtree
      num = strcmp(root->subject, subject);	//Check for match
      if(num == 0)				//If there is a match
      {	
         strcat(retrieval, root->name);		//Concatenate contents to retrieval array
         strcat(retrieval, "\n");
      }
      retrieve(root->right, subject, retrieval);	//Go to right subtree
   }	
   return retrieval;
}


/* This is just the public function for retrieve, and all it does is just 
take the subject and retrieval arrays as arguments and passes them on by 
calling its wrapper function (explained above). */
void tree::retrieve(char subject[], char retrieval[])
{
   retrieve(root, subject, retrieval);
}


/* The remove function takes in the pointer to the root by reference, the 
name of the picture, and the subject of the picture. The job of this 
function is to search the BST for a matching node for both the name and 
the subject. Once it finds it, then it deletes the node. In one instance, 
it doesn not delete the node but rather deletes the node that is its 
inorder successor. There are several cases of removal, which is why this 
function is so long. The return type is an int. This function includes 
both recursive and non-recursive algorithms. */
int tree::remove(node *& root, char name[], char subject[]) 
{
   if(!root)
      return 0;
   else
   {
      if(strcmp(name, root->name) < 0)		//If name is closer in alphabet than root
         remove(root->left, name, subject);	//Traverse to left
      else if(strcmp(name, root->name) > 0)	//If name is farther in alphabet than root
	 remove(root->right, name, subject);	//Traverse to right
      else					//If there is a match for name
      {			
	 if(strcmp(root->subject, subject) != 0)	//If subject doesn't match	
	    remove(root->left, name, subject);	//Keep traversing left
	 else					//You have found a match for both name and subject, it's time to remove
	 {
	    //Case 1: Node is a leaf
	    if(root->right == NULL && root->left == NULL)	
	    {
	       delete root->name;
	       delete root->subject;
	       delete root;
	       root = NULL;
	       return 1;
	    }

            //Case 2: Node has a left child but not a right child
	    else if(root->left != NULL && root->right == NULL)
       	    {
	       node *current = root->left;
	       delete root->name;
	       delete root->subject;
	       delete root;
	       root = current;
	       return 2;
	    }

	    //Case 3: Node has a right child but not a left child
	    else if(root->left == NULL && root->right != NULL)
	    {
	       node *current = root->right;
	       delete root->name;
	       delete root->subject;
	       delete root;
	       root = current;
	       return 3;
	    }
		
	    //Case 4: Node has two children	
	    else 
	    {
	       node *temp = root;	//Temporary pointer
	       node *current = root->right;	//Current points to right child
	       node *previous = NULL;	//Previous pointer is used with current to iteratively traverse
	       if(current->left == NULL)	//If left child of right child is NULL
	       {
	          strcpy(temp->name, current->name);	//Copy right child contents to temp
		  strcpy(temp->subject, current->subject);
		  temp->right = current->right;	//Temp->next = NULL;
		  delete current->name;		//Delete the right child
		  delete current->subject;
		  delete current;
		  return 4;
	       }

	       while(current->left)		//Otherwise traverse left until you find the inorder successor
	       {
		  previous = current;
		  current = current->left;
	       }
	       strcpy(temp->name, current->name);	//Copy contents of inorder successor to temp
	       strcpy(temp->subject, current->subject);
	       previous->left = current->right;			
	       delete current->name;			//Remove the inorder successor
	       delete current->subject;
	       delete current;
	       return 5;
            }

         }
		
      }
   return 6;
   }		
}


/*This is the public function for remove, and all it does is takes the 
name and subject of the picture to remove and passes it on by calling the 
wrapper function for remove. It returns 1 for success.*/
int tree::remove(char name[], char subject[])
{
   remove(root, name, subject);
   return 1;
}


/*The display function takes the root as an argument and traverses every 
node in the tree and displays the name. This is done recursively in an 
inorder fashion (go left, display, then go right). The purpose of this 
function is to display the names of the pictures in sorted alphabetical 
order. */ 
void tree::display(node *root) 
{
   if(root)
   {
      display(root->left);
      cout << root->name <<endl;
      display(root->right);
   }
}


/*This is the public function for display, and has been stated for all the 
other public functions, it calls its wrapper function. There are no 
arguments for this function.*/
void tree::display()
{
   display(root);
}


/*The removeall function sort of acts like the wrapper function for the 
destructor, because it is a recursive function that deletes all the nodes 
in the tree and deallcoates all the dynamic memory in the nodes. It 
takes the node pointer root as an argument by reference.*/
void tree::removeall(node *&root)
{
   if(root)
   {
      removeall(root->left);
      removeall(root->right);
      delete [] root->name;
      delete [] root->subject;
      delete root;
   }

}


/*The destructor just calls the removeall function to do all the work. 
This needs to be done because removing all nodes is a recursive process, 
so the destructor will not be able to call itself. */
tree::~tree()
{
   removeall(root);
}
		
		



