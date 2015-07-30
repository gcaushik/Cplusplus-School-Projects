//Gokul Caushik


struct node
{
   char *course;	//Pointer to the course name
   node *next;
};

struct vertex
{
   char *requirements;		//Pointer to a course name
   node *head;			//Head pointer
};


class graph
{
public:
   graph();		//Constructor
   ~graph();		//Destructor
   int addreq(char[]);		//Adds a vertex
   int addcourse(char[], char[]);	//Adds a vertex and an edge
   int removecourse(char[]);		//Removes an edge and a vertex
   int removepreq(char[], char[]);	//Removes an edge
   int copy(node *&newhead, node *oldhead);	//Copy function
   void displayall();	//Displays graph
private:
   vertex *degree;		//Pointer to the first of an array of vertices
   int numofvertices;	//Keeps track of number of vertices in graph
};


