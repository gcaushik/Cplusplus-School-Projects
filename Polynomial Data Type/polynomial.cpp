//Gokul Caushik

//This is the implementation file for the polynomial class.



#include "polynomial.h"

/*The constructor initializes head to NULL.*/
polynomial::polynomial()
{
	head = NULL;
	tail = NULL;
	hold = NULL;
}


/*The copy constructor performs a deep copy of a polynomial
object that is taken in by const reference.*/
polynomial::polynomial(const polynomial &src)
{
	copy(head, src.head);	
}	  	



/*Function that makes a copy of a polynomial. This function is called by 
the operator= and the copy constructor.*/
void polynomial::copy(node *&to, node *from)
{
	node *prev = NULL;

	if(from)
	{
		to = new node;
		to->object.coefficient = from->object.coefficient;
		to->object.power = from->object.power;
		to->previous = prev;
		to->next = NULL;
		this->hold = to;
		this->tail = to;
		from = from->next;
	}

	while(from)
	{
		prev = this->tail;
		this->tail->next = new node;
		this->tail = this->tail->next;
		this->tail->object.coefficient = from->object.coefficient;
		this->tail->object.power = from->object.power;
		this->tail->previous = prev;
		if(from->next == NULL)
			this->tail->next = NULL;
		from = from->next;
	}
		
}




/*This function has a very simple task. It returns the number of terms
in a polynomial to the user so that the user can walk through the 
polynomial. It returns an int which represents the number of terms. It
takes no arguments.*/
int polynomial::getnumterms()
{
	int counter = 0;
	node *current = head;
	while(current)
	{
		if(current->object.coefficient != 0)
			++counter;
		current = current->next;
	}
	return counter;
}



/*The create function is what is called by the extraction operator >> 
to allocate and copy over the memory needed for a polynomial. The 
function takes in two ints(which represents the coefficent and the 
power of the term being created) by value and returns 1 for success.*/
int polynomial::create(int term, int tpower)
{
	if(head == NULL)
	{
		head = new node;
		head->object.coefficient = term;
		head->object.power = tpower;
		head->next = NULL;
		head->previous = NULL;
		tail = head;
		hold = head;
		return 1;
	}

	tail->next = new node;
	tail->next->previous = tail;
	tail = tail->next;
	tail->object.coefficient = term;
	tail->object.power = tpower;
	tail->next = NULL;
	return 1;
}


/*This function overloads the assignment operator. It takes a polynomial 
class constant reference. First, it deallocates the memory that the 
current polynomial is using, then allocates and copies the memory from the 
argument class. The function returns a reference to the current 
polynomial as an l-value.*/ 
polynomial & polynomial::operator=(const polynomial &src)
{
//Check for self-assignment
	if(this == &src)		//Check if addresses are same
		return *this;
//Otherwise do the assignment
	node *temp = head;
	while(temp)			//Deallocate memory of current polynomial
	{
		head = head->next;
		delete temp;
		temp = head;
	}
	head = NULL;
	copy(head, src.head);		//Allocate and copy memory from src
	return *this;
}




/*This function overloads the subscript operator. It takes an index by value (an integer), which
represents the term of the current polynomial to access. The function returns the term (containing
the power and coefficient) by reference. 
The return value is an l-value.*/
term & polynomial::operator[](int index)
{
	static term dummy;		//This signifies a "NULL" term, returned if term is invalid
	dummy.coefficient = 0;
	int counter = 0;
	node *current = this->head;
	while(current)
	{
		if(current->object.coefficient != 0)
		{
			++counter;
			if(counter == index)
			{
				this->hold = current;
				return current->object;
			}
		}
		current = current->next;
	}
	return dummy;
}		




/*This function overloads the extraction operator. It takes an istream object and 
a polynomial object by reference. It reads in a polynomial through the 
istream and returns the istream object by reference. Since the first operand is
not a polynomial object, the function is declared as a friend function. */
istream & operator >>(istream &fin, polynomial &op2)
{
	int degree;
	fin >> degree;				//Get degree
	while(degree == 0)
	{
		cout << "Cannot have a degree of 0\n";
		cout << "Enter it again.\n";
		fin >> degree;
	}	
	int temp;
	for(int i=degree; i>=0; i--)
	{ 
		fin >> temp;			//Get coefficents of terms
		fin.ignore();
		op2.create(temp, i);	
	}
	return fin;
}




/*This function overloads the insertion operator. It takes an ostream object and 
a const polynomial object by reference. It displays the polynomial through the 
ostream and returns the ostream object by reference. Since the first operand is
not a polynomial object, the function is declared as a friend function. */		
ostream & operator <<(ostream &fout, const polynomial &op2)
{	
	node *current = op2.head;
	node *temp;
	int lasttermflag = 0;			//Flag that is set when inserting last term
	while(current)
	{
		if(current->object.coefficient != 0)
		{
			if(current->object.coefficient != 1)
				fout << current->object.coefficient;
			if(current->next == NULL)
			{
				if(current->object.coefficient == 1)
					fout << current->object.coefficient;
			}
			else
			{
				temp = op2.tail;
				while(temp != current)
				{
					if(temp->object.coefficient != 0)
					{
						lasttermflag = 0;
						break;
					}
					else
						lasttermflag = 1;
					temp = temp->previous;
				}	

				if(lasttermflag == 1 && current->object.power == 1)
				{
					fout << "x";
					return fout;
				}
				else if(lasttermflag == 1 && current->object.power != 1)
				{
				 	fout << "x^" << current->object.power;
					return fout;
				}
				else if(lasttermflag == 0 && current->object.power == 1)
					fout << "x" << " + ";
				else
					fout << "x^" << current->object.power << " + ";
			}
		}

		current = current->next;
	}
	return fout;
}





/*This function overloads the compound addition operator. It takes a polynomial by const
reference. First it checks to see if the degree of the polynomial on lhs 
is less than polynomial on rhs. If it is, then it allocates enough memory so that 
the degree of the polynomial is the same. Then it adds the coefficents on rhs polynomial
to corresponding coefficents on lhs polynomial. The function returns a polynomial 
by reference as an l-value.*/
polynomial & polynomial::operator+=(const polynomial &op2)
{
	if(this->head->object.power < op2.head->object.power)
	{
		int diff = op2.head->object.power - this->head->object.power;
		node *current = this->head;
		for(int i=0; i<diff; i++)
		{
			this->head = new node;
			this->head->object.coefficient = 0;
			this->head->object.power = current->object.power + 1;
			this->head->previous = NULL;
			this->head->next = current;
			current->previous = this->head;
			current = this->head;
		}
			
	}			

	node *temp = this->head;
	node *current = op2.head;
	while(temp)
	{
		if(current->object.power == temp->object.power)
		{
			temp->object.coefficient += current->object.coefficient;
			current = current->next;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return *this;
}		
	


/*This function overloads the compound subtraction operator. It takes a polynomial by const
reference. First it checks to see if the degree of the polynomial on lhs 
is less than polynomial on rhs. If it is, then it allocates enough memory so that 
the degree of the polynomial is the same. Then it subtracts the coefficents on rhs polynomial
to corresponding coefficents on lhs polynomial. The function returns a polynomial 
by reference as an l-value.*/
polynomial & polynomial::operator-=(const polynomial &op2)
{
	if(this->head->object.power < op2.head->object.power)
	{
		int diff = op2.head->object.power - this->head->object.power;
		node *current = this->head;
		for(int i=0; i<diff; i++)
		{
			this->head = new node;
			this->head->object.coefficient = 0;
			this->head->object.power = current->object.power + 1;
			this->head->previous = NULL;
			this->head->next = current;
			current->previous = this->head;
			current = this->head;
		}
			
	}			

	node *temp = this->head;
	node *current = op2.head;
	while(temp)
	{
		if(current->object.power == temp->object.power)
		{
			temp->object.coefficient -= current->object.coefficient;
			current = current->next;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return *this;
}



/*This function overloads the plus operator, and takes care of the 
case where the first operand is an integer. Because of this, this function is
declared as a friend function to the polynomial class. The function returns
a polynomial by value as an r-value.*/
polynomial operator+(const int op1, const polynomial &op2)
{
	 
	polynomial temp = op2;			//Invokes copy constructor to create a temp copy of op2
	temp.tail->object.coefficient += op1;
	return temp;				//Return residual value
}



/*This member function is another version of overloading the plus operator, and takes care of 
the case where the second operand is an integer. The function returns a polynomial 
by value as an r-value.*/
polynomial polynomial::operator+(const int op2) const
{	
	polynomial temp = *this;		//Invokes copy constructor to create a copy of op1
	temp.tail->object.coefficient += op2;
	return temp;				//Return residual value
}



/*This member function is a third version of overloading the plus operator, and 
takes care of the case where the second operand is also a polynomial. The function
returns a polynomial by value as an r-value.*/
polynomial polynomial::operator+(const polynomial &op2) const
{
	polynomial temp = *this;		//Invokes copy constructor to create a copy of op1
	temp += op2;				//Invokes the compound addition operator to add the two polynomials
	return temp;				//Return residual value;
}



/*This function overloads the minus operator, and takes care of the 
case where the first operand is an integer. Because of this, this function is
declared as a friend function to the polynomial class. The function returns
a polynomial by value as an r-value.*/
polynomial operator-(const int op1, const polynomial &op2) 
{
	polynomial temp = op2;			//Invokes copy constructor to create a copy of op2
	node *current = temp.head;
	while(current)
	{
		if(current->next == NULL)	
			current->object.coefficient = op1 - current->object.coefficient;
		else
			current->object.coefficient *= -1;
		current = current->next;
	}
	return temp;				//Return residual value
}



/*This member function is another version of overloading the minus operator, and takes care of 
the case where the second operand is an integer. The function returns a polynomial 
by value as an r-value.*/
polynomial polynomial::operator-(const int op2) const
{
	polynomial temp = *this;		//Invokes copy constructor to create a copy of op1
	temp.tail->object.coefficient -= op2;		
	return temp;				//Return residual value	
}




/*This member function is a third version of overloading the minus operator, and 
takes care of the case where the second operand is also a polynomial. The function
returns a polynomial by value as an r-value.*/
polynomial polynomial::operator-(const polynomial &op2) const
{ 
	polynomial temp = *this;		//Invokes copy constructor to create a copy of op1
	temp -= op2;				//Invokes compound subtraction operator to subtract two polynomials
	return temp;				//Return residual value
} 



/*This function overloads the comparision operator ==, comparing two polynomial objects.
It takes a constant polynomial by reference as the second operand. It checks if polynomial 
on lhs is identical to the polynomial on rhs. If it is, then it returns 
true, else it returns false.*/
bool polynomial::operator==(const polynomial &op2) const
{
	if(this->head->object.power == op2.head->object.power)
	{
		node *current = this->head;
		node *temp = op2.head;
		while(current)
		{
			if(current->object.coefficient != temp->object.coefficient)
				return false;
			else
			{
				current = current->next;
				temp = temp->next;
			}
		}
		return true;
	}

	else
		return false;
}



/*This function overloads the comparision operator !=, comparing two polynomial objects.
It takes a constant polynomial object by reference as the second operand.
Since it is directly linked to the == operator, all it does is return the opposite of 
what the == operator would return. If the == operator returns true, then this function 
returns false, and vice versa.*/
bool polynomial::operator!=(const polynomial &op2) const
{
	return !(*this == op2);			
}




/*This function overloads the relational operator <=, comparing two polynomial objects.
It takes a constant polynomial by reference as the second operand. It checks if polynomial 
on lhs is less than or equal to the polynomial on rhs. If it is, then it returns 
true, else it returns false.*/
bool polynomial::operator<=(const polynomial &op2) const
{
	if(this->head->object.power < op2.head->object.power)
		return true;
	if(this->head->object.power == op2.head->object.power)
	{	
		node *current = this->head;
		node *temp = op2.head;
		while(current)
		{
			if(current->object.coefficient < temp->object.coefficient)
				return true;
			else if(current->object.coefficient == temp->object.coefficient)
			{
				if(current->next == NULL)
					return true;
				current = current->next;
				temp = temp->next;
			}
			
			else
				return false;
		}
	}
	
	return false;
}
				


/*This function overloads the relational operator >=, comparing two polynomial objects.
It takes a constant polynomial by reference as the second operand. It checks if polynomial 
on lhs is greater than or equal to the polynomial on rhs. If it is, then it returns 
true, else it returns false.*/
bool polynomial::operator>=(const polynomial &op2) const
{
	if(this->head->object.power > op2.head->object.power)
		return true;
	if(this->head->object.power == op2.head->object.power)
	{
		node *current = this->head;
		node *temp = op2.head;
		while(current)
		{
			if(current->object.coefficient > temp->object.coefficient)
				return true;
			else if(current->object.coefficient == temp->object.coefficient)
			{
				if(current->next == NULL)
					return true;
				current = current->next;
				temp = temp->next;
			}
			else
				return false;
		}			
			
	}
	
	return false;
}




/*This function overloads the relational operator <, comparing two polynomial objects.
It takes a constant polynomial by reference as the second operand. It checks if polynomial 
on lhs is less than the polynomial on rhs. If it is, then it returns 
true, else it returns false.*/
bool polynomial::operator<(const polynomial &op2) const
{
	if(this->head->object.power < op2.head->object.power)
		return true;
	if(this->head->object.power == op2.head->object.power)
	{
		node *current = this->head;
		node *temp = op2.head;
		while(current)
		{
			if(current->object.coefficient < temp->object.coefficient)
				return true;

			else if(current->object.coefficient == temp->object.coefficient)
			{
				if(current->next == NULL)
					return false;
				current = current->next;
				temp = temp->next;
			}
			
			else
				return false;
		}
	}
	
	return false;	
}	



/*This function overloads the relational operator >, comparing two polynomial objects.
It takes a constant polynomial by reference as the second operand. It checks if polynomial 
on lhs is greater than the polynomial on rhs. If it is, then it returns 
true, else it returns false.*/
bool polynomial::operator>(const polynomial &op2) const
{
	if(this->head->object.power > op2.head->object.power)
		return true;
	if(this->head->object.power == op2.head->object.power)
	{
		node *current = this->head;
		node *temp = op2.head;
		while(current)
		{
			if(current->object.coefficient > temp->object.coefficient)
				return true;

			else if(current->object.coefficient == temp->object.coefficient)
			{
				if(current->next == NULL)
					return false;
				current = current->next;
				temp = temp->next;
			}
			
			else
				return false;
		}
	}
	
	return false;
}




/*This function overloads the prefix increment operator. It takes in no arguments, to 
signify that it is a prefix increment. The function traverses to the next term of the
polynomial and returns the power and the coefficient of the term in an int array by
reference. It returns as an l-value.*/
term & polynomial::operator++()
{
	static term dummy;		//Signifies a "NULL" term, returned if term is invalid
	dummy.coefficient = 0;
	hold = hold->next;
	while(hold && hold->object.coefficient == 0)
		hold = hold->next;
	if(hold != NULL)
		return hold->object;
	else
		return dummy;
}		





/*This function overloads the postfix increment operator. It takes in an int as an argument, to 
signify that it is a postfix increment. The function traverses to the next term of the
polynomial and returns the power and the coefficient of the term in an int array by
value. It returns as an r-value.*/
term polynomial::operator++(int index)
{
	term temp;				//Residual value
	if(hold != NULL)
	{
		temp = hold->object;
		hold = hold->next;
		while(hold && hold->object.coefficient == 0)
			hold = hold->next;
	}
	else
		temp.coefficient = 0;
	return temp;
}




/*This function overloads the prefix decrement operator. It takes in no arguments, to 
signify that it is a prefix decrement. The function traverses to the previous term of the
polynomial and returns the power and the coefficient of the term in an int array by
reference. It returns as an l-value.*/
term & polynomial::operator--()
{
	static term dummy;		//Signifies a "NULL" term, returned if term is invalid
	dummy.coefficient = 0;
	hold = hold->previous;
	while(hold && hold->object.coefficient == 0)
		hold = hold->previous;
	if(hold != NULL)
		return hold->object;
	else
		return dummy;
}




/*This function overloads the postfix decrement operator. It takes in an int as an argument, to 
signify that it is a postfix decrement. The function traverses to the previous term of the
polynomial and returns the power and the coefficient of the term in an int array by
value. It returns as an r-value.*/
term polynomial::operator--(int)
{
	term temp;			//Residual value
	if(hold != NULL)
	{
		temp = hold->object;
		hold = hold->previous;
		while(hold && hold->object.coefficient == 0)
			hold = hold->previous;
	}
	else
		temp.coefficient = 0;
	return temp;

}




/*This function overloads the function() operator. The function's job is to evaluate a polynomial
for a certain value of x. It takes in the value as a float argument, evaluates the polynomial, and 
returns the result as a double.*/
double polynomial::operator()(float value)
{
	double evaluation = 0;
	int coeff;
	node *current = this->head;
	while(current)
	{
		coeff = current->object.coefficient;
		if(coeff != 0)
			evaluation += (coeff * (pow(value, current->object.power)));
		current = current->next;
	}
	return evaluation;
}




/*The destructor deallocates all the dynamic memory, namely it deletes
all the nodes of the polynomial.*/
polynomial::~polynomial()
{
	node *temp = head;
	while(head)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}	
