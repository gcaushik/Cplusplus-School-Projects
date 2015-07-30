//Gokul Caushik


struct patient
{
   char *name;		//Holds name of patient
   int arrival;		//Holds time of arrival
};

struct queuenode
{
   patient info;	//Holds a patient 
   queuenode *next;	
};



class queue
{
   public:
      queue();		//Default constructor
      ~queue();		//Destructor
      int enqueue(const char[], int &);	//Enqueues a patient
      int dequeue(char[],int &);	//Dequeues a patient
      int isempty();	//Checks if queue is empty
   private:
      queuenode *ptr;	//queue pointer
};

