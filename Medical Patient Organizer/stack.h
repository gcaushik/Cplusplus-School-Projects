//Gokul Caushik


struct stacknode
{
   queue er_patients;		//Holds a queue object
   stacknode *next;	
};	


class stack
{
   public:
      stack();		//Default Constructor
      ~stack();		//Destructor
      int push(queue &);	//Pushes a queue onto a stack
      queue & pop();		//Pops a queue from the stack
      int isempty();		//Checks if stack is empty
   private:
      stacknode *head;		//Head pointer
      stacknode *tail;		//Tail pointer
};
