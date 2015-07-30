//Gokul Caushik

	
struct node
{
   char *name;
   char *subject;
   node *left;
   node *right;
};

class tree
{
   public:
      tree();				//Constructor
      ~tree();				//Destructor
      void store(char[], char[]);	//Stores data for a picture
      void retrieve(char[], char[]);	//Retrieves names of all pictures of a certain subject
      int remove(char[], char[]);	//Removes data fora  a picture
      void display();			//Displays all names of the pictures in sorted order
      void removeall(node *&root);	//Removes all nodes in tree
   private:
      node *root;				//Node pointer
      int store(node *&, char[], char[]);	//The rest are just wrapper functions with the purposes stated above
      char * retrieve(node *, char[], char[]);
      int remove(node *&, char[], char[]);
      void display(node *root);
};


