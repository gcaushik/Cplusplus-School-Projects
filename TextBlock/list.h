//Gokul Caushik

//This is the header file for the list class, and this just shows the node 
//struct and the prototypes of the functions and the members of the list 
//class.


struct node
{
   char *text;
   node *next;
};
		

class list
{		
   public:
      list();
      ~list();
      int append_text(char phrase[]);
      int remove_text(char phrase[]);
      int display_all();
   private:
      node *head;
      node *tail;
      char *fullstring;
};
