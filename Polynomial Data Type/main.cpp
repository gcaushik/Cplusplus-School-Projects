//Gokul Caushik


#include "polynomial.h"
#include "main.h"


int main()
{
	polynomial one, two, three;		//Three polynomials
	int num, choice;			//Holds value for menu choices
	term data;				//Holds data for a term that is returned 

	cout << "Welcome to the world of polynomials! Here you will explore\n";
	cout << "polynomials and how they work, and how they operate.\n";
	cout << "To know how to use this program, please access the Help page\n";
	cout << "from the main menu.\n";
	cout << "Have fun!\n";	
	cout << endl;
	cout << "First you will create three polynomials which you will explore\n";
	cout << "To enter a polynomial first enter the degree of the polynomial and press enter\n";
	cout << "Then enter the coefficients in reducing exponential order pressing enter after\n";
	cout << "each coefficient. For example, the polynomial 2x + 3 would be entered as\n";
	cout << "1" << endl << "2" << endl << "3" << endl;
	cout << "Polynomial 1: \n";					//User eners polynomials
	cin >> one;
	cout << "Polynomial 2: \n";
	cin >> two;
	cout << "Polynomial 3: \n";
	cin >> three;
	cout << "Here are your 3 polynomials: \n";
	cout << one;
	cout << endl;
	cout << two;
	cout << endl;
	cout << three;
	cout << endl;
	cout << "Now you are set. Get ready to explore!\n";		
	do
	{
		cout << "1. Add polynomials\n";
		cout << "2. Subtract polynomials\n";
		cout << "3. Walk through a polynomial\n";
		cout << "4. Compare two polynomials\n";
		cout << "5. Fun expressions, evaluate polynomials.\n";
		cout << "6. Display the three polynomials\n";
		cout << "7. Quit\n";
	  	cin >> num;			
		cout << "P = Polynomial\n";
		switch(num)
		{
		case 1:
			choice = addmenu();						//Pretty self-explanatory: Just add and display result
			switch(choice)
			{
			case 1:						
				one += two;
				cout << "Result: \n";
				cout << "P1 = " << one;
				break;
			case 2:
				one += three;
				cout << "Result: \n";
				cout << "P1 = " << one;
				cout << endl;
				break;
			case 3:
				two += one;
		 		cout << "Result: \n";
				cout << "P2 = " << two;
				break;
			case 4:
				two += three;
				cout << "Result: \n";
				cout << "P2 = " << two;
				cout << endl;
				break;
				
			case 5:
				three += one;
				cout << "Result: \n";
				cout << "P3 = " << three;
				break;
			case 6:
				three += two;
				cout << "Result: \n";
				cout << "P3 = " << three;
				cout << endl;
				break;	
			}
			break;
		case 2:									//Pretty self-explanatory: Just subtract and display result 
			choice = subtractmenu();
			switch(choice)
			{
			case 1:
				one -= two;
				cout << "Result: \n";
				cout << "P1 = " << one;
				cout << endl;
				break;
			case 2:
				one -= three;
				cout << "Result: \n";
				cout << "P1 = " << one;
				cout << endl;
				break;
			case 3:
				two -= one;
				cout << "Result: \n";
				cout << "P2 = " << two;
				cout << endl;
				break;
			case 4:
				two -= three;
				cout << "Result: \n";
				cout << "P2 = " << two;
				cout << endl;
				break;
			case 5:
				three -= one;
				cout << "Result: \n";
				cout << "P3 = " << three;
				cout << endl;
				break;
			case 6:
				three -= two;
				cout << "Result: \n";
				cout << "P3 = " << three;
				cout << endl;
				break;	
			}
			break;
		case 3:
			int access;
			choice = walkthrough();	
			switch(choice)
			{
			case 1:									//Cases 1 and 2 are for Polynomial 1
				cout << "Enter the number of term you want to access\n";
				cin >> access;							//Get number term
				data = one[access];						//Access that term index
				if(data.coefficient == 0)					//If out of bounds
					cout << "That term does not exist.\n";			
				else							
				{
					cout << "The term you accessed is \n";
					if(data.coefficient == 1 && data.power == 1)		//Formatting stuff
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1) 
						cout << "x^" << data.power;
					else
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				break;
			case 2:			
				cout << "Here are the terms\n";
				access = one.getnumterms();			//Get number of terms in polynomial 
				data = one[1];					//Start from first term
				for(int i=0; i<access; i++)			
				{
					data = one++;				//Postfix makes sense here as we need to get the first value before incrementing
					cout << "Term " << i+1 << ": ";
					if(data.coefficient == 1 && data.power == 1)		//Formatting stuff
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1)
						cout << "x^" << data.power;
					else 
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				cout << "---REVERSE ORDER---\n";			//Do same thing, but display in reverse
				data = one[access];					//Start at last term
				for(int i=0; i<access; i++)	
				{
					data = one--;					//Postfix makes sense here as we need to get the first value before decrementing
					cout << "Term " << i+1 << ": ";
					if(data.coefficient == 1 && data.power == 1)		//Formatting
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1)
						cout << "x^" << data.power;
					else 
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				break;
			case 3:									//Cases 3 and 4 are for Polynomial 2
				cout << "Enter the number of term you want to access\n";
				cin >> access;
				data = two[access];
				if(data.coefficient == 0)
					cout << "That term does not exist.\n";
				else
				{
					cout << "The term you accessed is \n";
					if(data.coefficient == 1 && data.power == 1)
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1) 
						cout << "x^" << data.power;
					else
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				break;			
			case 4:
				cout << "Here are the terms\n";
				access = two.getnumterms();			//Get number of terms in polynomial 
				data = two[1];
				for(int i=0; i<access; i++)
				{
					data = two++;				//Postfix here makes sense because you get the first value before incrementing
					cout << "Term " << i+1 << ": ";
					if(data.coefficient == 1 && data.power == 1)
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1)
						cout << "x^" << data.power;
					else 
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				cout << "---REVERSE ORDER---\n";
				data = two[access];
				for(int i=0; i<access; i++)
				{
					data = two--;				//Postfix here makes sense because you get the first value before decrementing
					cout << "Term " << i+1 << ": ";
					if(data.coefficient == 1 && data.power == 1)
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1)
						cout << "x^" << data.power;
					else 
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				break;
			case 5:									//Cases 5 and 6 are for Polynomial 3
				cout << "Enter the number of term you want to access\n";
				cin >> access;
				data = three[access];
				if(data.coefficient == 0)
					cout << "That term does not exist.\n";
				else
				{
					cout << "The term you accessed is \n";
					if(data.coefficient == 1 && data.power == 1)
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1) 
						cout << "x^" << data.power;
					else
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				break;
			case 6:
				cout << "Here are the terms\n";
				access = three.getnumterms();			//Get number of terms in polynomial 
				data = three[1];				//Point to the first term
				for(int i=0; i<access; i++)
				{
					data = three++;				
					cout << "Term " << i+1 << ": ";
					if(data.coefficient == 1 && data.power == 1)
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1)
						cout << "x^" << data.power;
					else 
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				cout << "---REVERSE ORDER---\n";
				data = three[access];
				for(int i=0; i<access; i++)
				{
					data = three--;
					cout << "Term " << i+1 << ": ";
					if(data.coefficient == 1 && data.power == 1)
						cout << "x";
					else if(data.coefficient != 1 && data.power == 1)
						cout << data.coefficient << "x";
					else if(data.coefficient != 0 && data.power == 0)
						cout << data.coefficient;
					else if(data.coefficient == 1 && data.power != 1)
						cout << "x^" << data.power;
					else 
						cout << data.coefficient << "x^" << data.power;
					cout << endl;
				}
				break;
			}		
			break;
		case 4:									
			cout << "P1: " << one << endl;
			cout << "P2: " << two << endl;
			cout << "P3: " << three << endl;
			choice = comparemenu();					
			switch(choice)						//Just prints out some statements according to comparisions
			{
			case 1:
				if(one == two)
					cout << "P1 and P2 are equal\n";		

				if(one != two)
					cout << "P1 and P2 are not equal\n";
				if(one < two)
					cout << "P1 is less than P2\n";
				if(one <= two)
					cout << "P1 is less than or equal to P2\n";
				if(one > two)
					cout << "P1 is greater than P2\n";
				if(one >= two)
					cout << "P1 is greater than or equal to P2\n";
				break;
			case 2:
				if(one == three)
					cout << "P1 and P3 are equal\n";		

				if(one != three)
					cout << "P1 and P3 are not equal\n";
				if(one < three)
					cout << "P1 is less than P3\n";
				if(one <= three)
					cout << "P1 is less than or equal to P3\n";
				if(one > three)
					cout << "P1 is greater than P3\n";
				if(one >= three)
					cout << "P1 is greater than or equal to P3\n";
				break;
			case 3:
				if(two == one)
					cout << "P2 and P1 are equal\n";		

				if(two != one)
					cout << "P2 and P1 are not equal\n";
				if(two < one)
					cout << "P2 is less than P1\n";
				if(two <= one)
					cout << "P2 is less than or equal to P1\n";
				if(two > one)
					cout << "P2 is greater than P1\n";
				if(two >= one)
					cout << "P2 is greater than or equal to P1\n";
				break;			
			case 4:
				if(two == three)
					cout << "P2 and P3 are equal\n";		

				if(two != three)
					cout << "P2 and P3 are not equal\n";
				if(two < three)
					cout << "P2 is less than P3\n";
				if(two <= three)
					cout << "P2 is less than or equal to P3\n";
				if(two > three)
					cout << "P2 is greater than P3\n";
				if(two >= three)
					cout << "P2 is greater than or equal to P3\n";			
				break;
			case 5:
				if(three == one)
					cout << "P3 and P1 are equal\n";
				if(three != one)
					cout << "P3 and P1 are not equal\n";
				if(three < one)
					cout << "P3 is less than P1\n";
				if(three <= one)
					cout << "P3 is less than or equal to P1\n";
				if(three > one)
					cout << "P3 is greater than P1\n";
				if(three >= one)
					cout << "P3 is greater than or equal to P1\n";
				break;
			case 6:	
				if(three == two)
					cout << "P3 and P2 are equal\n";
				if(three != two)
					cout << "P3 and P2 are not equal\n";
				if(three < two)
					cout << "P3 is less than P2\n";
				if(three <= two)
					cout << "P3 is less than or equal to P2\n";
				if(three > two)
					cout << "P3 is greater than P2\n";
				if(three >= two)
					cout << "P3 is greater than or equal to P2\n";
				break;
			}
			break;
		case 5:
			float eval;							//Holds value of x to evaluate
			cout << "Some fun expressions!\n";
			cout << "P1 + P2 + P3 = " << one + two + three << endl;		//Print out some expressions
			cout << "P1 - P2 - P3 = " << one - two - three << endl;
			cout << "(P1 - P2) - P3  = " << (one - two) + three << endl;
			cout << "P1 - (P2 - P3) = " << one - (two - three) << endl;
			cout << "P1 + 5 = " << one + 5 << endl;
			cout << "10 + P2 = " << 10 + two << endl;
			cout << "20 - P3 = " << 20 - three << endl;
			cout << endl;					
			cout << "Evaluate a polynomial\n";			
			choice = evaluatemenu();					
			switch(choice)
			{
			case 1:
				cout << "Enter a value for variable x to evaluate\n";
				cin >> eval;
				cout << "P" << choice << "(x = " << eval << ")";		
				cout << " evaluates to " << one(eval) << endl;			//Function call operator to evaluate
				break;
			case 2:
				cout << "Enter a value for variable x to evaluate\n";
				cin >> eval;
				cout << "P" << choice << "(x = " << eval << ")";
				cout << " evaluates to " << two(eval) << endl;
				break;
			case 3:
				cout << "Enter a value for variable x to evaluate\n";
				cin >> eval;
				cout << "P" << choice << "(x = " << eval << ")";
				cout << " evaluates to " << three(eval) << endl;
				break;
			}
			break;
		case 6:
			cout << "P1 = " << one << endl;
			cout << "P2 = " << two << endl;
			cout << "P3 = " << three << endl;
			break;
		case 7:
			break;
		default:
			break;
							 
		}		
	}while(num != 7);
				
	return 0;
}







/*This function is just a menu that gives the user the choices of 
pairs of polynomials to add. It returns the number that the user
chooses.*/
int addmenu()
{
	int num;
	do
	{
		cout << "1. Add P2 to P1\n";
		cout << "2. Add P3 to P1\n";
		cout << "3. Add P1 to P2\n";
		cout << "4. Add P3 to P2\n";
		cout << "5. Add P1 to P3\n";
		cout << "6. Add P2 to P3\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 6);

	switch(num)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;	
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	case 6:
		return 6;
		break;
	}
	return 0;
}
	



/*This function is just a menu that gives the user the choices of 
pairs of polynomials to subtract. It returns the number that the user
chooses.*/
int subtractmenu()
{
	int num;
	do
	{
		cout << "1. Subtract P2 from P1\n";
		cout << "2. Subtract P3 from P1\n";
		cout << "3. Subtract P1 from P2\n";
		cout << "4. Subtract P3 from P2\n";
		cout << "5. Subtract P1 from P3\n";
		cout << "6. Subtract P2 from P3\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 6);
	
	switch(num)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	case 6:
		return 6;
		break;
	}	
	return 0;
}




/*This function has two menus, first finding out from the user what 
polynomial to walk through, and then giving the user choices of accessing
a specific term or displaying all terms. Based on the combination of user 
choices, the function returns an int.*/
int walkthrough()
{
	int num, menu;
	do
	{
		cout << "1. Polynomial 1\n";
		cout << "2. Polynomial 2\n";
		cout << "3. Polynomial 3\n";
		cout << "Which polynomial do you want to walk through?\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 3);

	do
	{
		cout << "1. Access a specific term\n";
		cout << "2. Display all terms\n";
		cin >> menu;
		cin.ignore();
	}while(menu < 1 || menu > 2);

	
	if(num == 1 && menu == 1)
		return 1;
	if(num == 1 && menu == 2)
		return 2;
	if(num == 2 && menu == 1)
		return 3;
	if(num == 2 && menu == 2)
		return 4;
	if(num == 3 && menu == 1)
		return 5;
	if(num == 3 && menu == 2)
		return 6;
	else
		return 0;
}





/*This function is just a menu that gives the user choices for what
polynomial pairs to compare. The number of choice is returned.*/
int comparemenu()
{
	int num;
	do
	{
		cout << "1. Compare P1 and P2\n";
		cout << "2. Compare P1 and P3\n";
		cout << "3. Compare P2 and P1\n";
		cout << "4. Compare P2 and P3\n";
		cout << "5. Compare P3 and P1\n";
		cout << "6. Compare P3 and P2\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 6);

	switch(num)
	{
	case 1: 
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	case 6:
		return 6;
		break;
	}

	return 0;
}



/*This function just is a menu that gives the user choices for which polynomial to evaluate.
The function returns the number of the polynomial that user chooses.*/
int evaluatemenu()
{
	int num;
	do
	{
		cout << "1. Evaluate P1\n";
		cout << "2. Evaluate P2\n";
		cout << "3. Evaluate P3\n";
		cin >> num;
		cin.ignore();
	}while(num < 1 || num > 3);
	
	switch(num)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	}
	return 0;
}

