//Gokul Caushik

struct node
{
   char *name;		//Pointer to array holding filename
   node *next;	
};


class table
{
   public:
      table();		//Default constructor
      ~table();		//Destructor
      int hashfunction(char[]);		//Returns an index for hashtable according to a "key"
      int store(char[], char[]);	//Stores a picture into the hashtable
      char *retrieve(char[], char[]);	//Retrives pictures for a subject
      int remove(char[], char[]);	//Removes a picture
   private:
      node ** hashtable;		//Pointer to an array of node pointers
};
