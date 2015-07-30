//Gokul Caushik

//This is the header file for the polynomial class.



#include <iostream>
using namespace std;
#include <string.h>
#include <math.h>


struct term
{
	int coefficient;			//Represents coefficient of term
	int power;				//Represents power of term
};


struct node
{
	term object;				//Contains a term
	node *next;				
	node *previous;
};



class polynomial 
{
public:
	polynomial();								//Constructor
	polynomial(const polynomial &);						//Copy Constructor		
	int getnumterms();							//Returns the number of terms
	int create(int, int);							//Allocates memory for polynomial
	polynomial & operator=(const polynomial &);				//Overload Assignment Operator
	term & operator[](int index);						//Overload Subscript Operator
	friend istream & operator>>(istream &, polynomial &);			//Overload Insertion Operator
	friend ostream & operator<<(ostream &, const polynomial &);		//Overload Extraction Operator
	polynomial & operator+=(const polynomial &);				//Overload Compound Addition Operator
	polynomial & operator-=(const polynomial &);				//Overload Compound Subtraction Operator
	friend polynomial operator+(const int op1, const polynomial &op2);	 
	polynomial operator+(const int op2) const;				//Polynomial + int
	polynomial operator+(const polynomial &) const;				//Overload Addition Operator
	friend polynomial operator-(const int op1, const polynomial &op2);	
	polynomial operator-(const int op2) const;				//Polynomial - int
	polynomial operator-(const polynomial &) const;				//Overload Subtraction Operator
	bool operator==(const polynomial &) const;				//Overload Equality Operator
	bool operator!=(const polynomial &) const;				//Overload != Operator
	bool operator<=(const polynomial &) const;				//Overload <= Operator
	bool operator>=(const polynomial &) const;				//Overload >= Operator
	bool operator<(const polynomial &) const;				//Overloading < operator
	bool operator>(const polynomial &) const;				//Overloading > operator
	term & operator++();							//Overload Prefix Increment
	term operator++(int);							//Overload Postfix Increment
	term & operator--();							//Overload Prefix Decrement
	term operator--(int);							//Overload Postfix Decrement	
	double operator()(float);						//Overload () Operator
	~polynomial();			
private:
	void copy(node *&, node *);						//Makes a copy of a polynomial
	node *head;
	node *tail;
	node *hold;								//Used to walk through terms of polynomial
};





