//Done by: Aaron Lim

//I did not pass my assignment to anyone in 
//class or copy anyone's work.

//I am willing to accept whatever penalty
//given to me and also to all the related
//parties involved.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//enum the 12 animal
enum Animal {Rat, Ox, Tiger, Rabbit, Dragon, Snake, Horse, Sheep, 
			Monkey, Rooster, Dog, Pig, Invalid};

//12 animals
const int MAX = 12;

//max character
const int MAXC = 50;

//either void* or voidPtr
typedef void* voidPtr;

//----------------------main menu----------------------
//print main menu
int mainMenu(int);

//check which option did user input
void checkMainOption(int);

//-----------------------option 0-----------------------
//print option 0
void option0();

//construct and return a set
void constructSet (voidPtr*, int);

//check if false or true (duplication)
bool checkValue (int*, voidPtr*, int);

//print animal from MAX
void getAnimal (voidPtr*, int&);

//get int from voidPtr
Animal getint (voidPtr);

//check option0 option
void checkOption0 (voidPtr*, int);

//check true or false
void checkTrueOrFalse (bool, char []);

//find in animal array
Animal checkAnimal (const char []);

//compare animal if it exist
void cAnimal (int, voidPtr*, int&);

//check if it is inside
bool isInside (int, voidPtr*, int);

//-----------------------option 1-----------------------
//creation of option1
void option1();

//unify both union
void unify (voidPtr*, voidPtr*, voidPtr*, int&, int, int);

//check the size of two sizes
//int checkSize (int, int);

//-----------------------option 2-----------------------
//print option 2
void option2 ();

//check intersection
void intersection (voidPtr*, voidPtr*, voidPtr*, int&, int, int);

//-----------------------option 3-----------------------
//print option 3
void option3();

//complement of option 3
void complement (voidPtr*, voidPtr*, int, int&);

//-----------------------option 4-----------------------
//print option 4
void option4();

//check if subset
bool checkS1subS2(voidPtr*, voidPtr*, int, int);

//print out if is or not subset
void printFalse (bool);

//-----------------------option 5-----------------------
//print option 5
void option5();

//check if both are equal
bool checkEqual (voidPtr*, voidPtr*, int, int);

//-----------------------option 6-----------------------
//print option 6
void option6();

//minus function
void minusOperation (voidPtr*, voidPtr*, voidPtr*, int, int, int&);

//-----------------------option 7-----------------------
//print option 7
void option7();

//------------------Garbage collection------------------
//Garbage collection
void garbageCollection (voidPtr*, int);

int main()
{
	srand(time(NULL));
	int option1;
	
	checkMainOption(option1);	 
}

//check which option did user input
void checkMainOption(int option)
{
	do
	{
		cout << "Welcome to Aaron Learning Center"
			 << "\n\n\t0. An example of set"
			 << "\n\t1. Union"
			 << "\n\t2. Intersection"
			 << "\n\t3. Complement"
			 << "\n\t4. Subset of"
			 << "\n\t5. Equality"
			 << "\n\t6. Difference"
			 << "\n\t7. Distributive law"
			 << "\n\t9. Quit"
			 << "\n\n\tYour option: ";
		cin >> option;
		switch(option)
		{
			case 0: cout << "-----------------------------------------------------"
			 			 << endl;
					option0();
					break;
			case 1: cout << "-----------------------------------------------------"
			 			 << endl;
					option1();
					break;
			case 2: cout << "-----------------------------------------------------"
			 			 << endl;
					option2();
					break;
			case 3: cout << "-----------------------------------------------------"
			 			 << endl;
					option3();
					break;
			case 4: cout << "-----------------------------------------------------"
			 			 << endl;
					option4();
					break;
			case 5: cout << "-----------------------------------------------------"
			 			 << endl;
					option5();
					break;
			case 6: cout << "-----------------------------------------------------"
			 			 << endl;
					option6();
					break;
			case 7: cout << "-----------------------------------------------------"
			 			 << endl;
					option7();
					break;
			default: break;
		}
	}while(option != 9);
}

//print option 0
void option0()
{
	cout << "\nHere is an example on set of animals";
	cout << "\n" << endl;
	
	int size = rand() % MAX;
	
	voidPtr* animalArray = new voidPtr [MAX];

	constructSet (animalArray, size);
	cout << "Set S = {";
	getAnimal(animalArray, size);
	cout << "}" << endl;	
	
	int i;
	char animal [MAXC];
	Animal num;
	bool check;
	do
	{
		cout << "\nNote that element in S are distinct and are not in order"
			 << "\n\nWish to try the following operations?"
			 << "\n1. Add an element to the set"
			 << "\n2. Check an element in the set"
			 << "\n3. Check the cardinality"
			 << "\n9. Quit"
			 <<  "\n\nYour choice: ";
		cin >> i;	
		
		switch (i)
		{
			case 1: cout << "-----------------------------------------------------" << endl;
					cout << "Current Set S = {";		
					getAnimal (animalArray, size);
					cout << "}" << endl;
			
					cout << "Enter an element: ";
					cin >> animal;
			
					cout << "Set S = {";
					num = checkAnimal (animal);
					cAnimal (num, animalArray, size);
					getAnimal (animalArray, size);
					cout << "}" << endl;
					break;
					
			case 2: cout << "-----------------------------------------------------" << endl;
					cout << "Current Set S = {";
					getAnimal (animalArray, size);
					cout << "}" << endl;
					
					cout << "Which element?: ";
					cin >> animal;
					
					num = checkAnimal (animal);
					check = isInside (num, animalArray, size);
					checkTrueOrFalse (check, animal);
					break;
					
			case 3: cout << "-----------------------------------------------------" << endl;
					cout << "Current Set S = {";
					getAnimal (animalArray, size);
					cout << "}" << endl;
					cout << "S has " << size << " elements"
						 << "\n-----------------------------------------------------"
						 << endl;
					break;
		}   
	}while (i != 9);
	
	garbageCollection(animalArray, size);
	cout << "-----------------------------------------------------"
		 << "\nGarbage collection"
		 << "\n\tSet S deleted"
		 << "\n-----------------------------------------------------"
		 << endl;
}

//check true or false
void checkTrueOrFalse (bool check, char animal [])
{
	if (check == true)
	{
		cout << animal
			 << " is in S"
			 << "\n-----------------------------------------------------"
			 << endl;
	}
	else
	{
		cout << animal
			 << " is not in S"
			 << "\n-----------------------------------------------------"
			 << endl;
	}
}

//construct and return a set
void constructSet(voidPtr* animalArray, int size)
{
	Animal *temp;
	voidPtr vp;
	
	int i = 0;
	bool check = false;	
	
	while(i < size)
	{
		temp = new Animal;
		*temp = static_cast <Animal>(rand() % MAX);
		vp = temp;
		
		for (int j = 0; j < i; j++)
		{	
			if (getint (animalArray[j]) == *temp)
				check = true;
		}
	
		if (check == false)
		{
			animalArray [i] = vp;
			i++;
		}
		check = false;
	}
}

//check if it is inside
bool isInside (int num, voidPtr* animalArray, int size)
{
	int i = 0;
	bool check;

	
	while(i < size)
	{
		if (getint (animalArray[i]) == num)
		{
			i++;
			return true;
		}
		else 
		{
			i++;
		}
	}
	return false;	   
}

//print animal from MAX
void getAnimal (voidPtr* animalArray, int& size)
{	 
	for(int i = 0; i < size;i++)
	{
		switch(getint (animalArray[i]))
		{
			case 0: cout << "Rat";
					break;
			case 1: cout << "Ox";
					break;
			case 2: cout << "Tiger";
					break;
			case 3: cout << "Rabbit";
					break;
			case 4: cout << "Dragon";
					break;
			case 5: cout << "Snake";
					break;
			case 6: cout << "Horse";
					break;
			case 7: cout << "Sheep";
					break;
			case 8: cout << "Monkey";
					break;
			case 9: cout << "Rooster";
					break;
			case 10: cout << "Dog";
					 break;
			case 11: cout << "Pig";
					 break;
			default: break;
		}
		
		if (i + 1 != size && getint(animalArray[i + 1]) != 12)
		{
			cout << ", ";
		}
		
		if (getint(animalArray[i]) == 12)
		{
			size--;
		}
	}
}

//get int from voidPtr
Animal getint (voidPtr animalArray)
{
	Animal *temp = static_cast<Animal*> (animalArray);
	Animal n = *temp;
	return n;
}

Animal checkAnimal (const char animal [])
{
	if (strcmp (animal, "Rat") == 0)
		return Rat;
	else if (strcmp (animal, "Ox") == 0)
		return Ox;
	else if (strcmp (animal, "Tiger") == 0)
		return Tiger;       	 
	else if (strcmp (animal, "Rabbit") == 0)
		return Rabbit;
	else if (strcmp (animal, "Dragon") == 0)
		return Dragon;
	else if (strcmp (animal, "Snake") == 0)
		return Snake;
	else if (strcmp (animal, "Horse") == 0)
		return Horse;
	else if (strcmp (animal, "Sheep") == 0)
		return Sheep;
	else if (strcmp (animal, "Monkey") == 0)
		return Monkey;
	else if (strcmp (animal, "Rooster") == 0)
		return Rooster;
	else if (strcmp (animal, "Dog") == 0)
		return Dog;
	else if (strcmp (animal, "Pig") == 0)
		return Pig;  
	else
		return Invalid;            
}

//compare animal if it exist
void cAnimal (int num, voidPtr* animalArray, int& size)
{
	int i = 0;
	bool check = true;
	Animal *temp;
	voidPtr vp;
	
	while(i < size)
	{
		if (getint (animalArray[i]) != num)
		{
			i++;
		}
		else 
		{
			i++;
			check = false;
		}
	}
	
	if (check == true)
	{

		temp = new Animal;
		*temp = static_cast<Animal>(num);
		vp = temp;
		animalArray[size] = vp;
		size++;	   	   
	}
}

//creation of option1
void option1()
{
	cout << "Given the following two sets" << endl;
	
	int size1 = rand () % 5;
	int size2 = rand () % 5;
	int size = 0;	 
	voidPtr* animalArray = new voidPtr [MAX];
	voidPtr* unionAnimal = new voidPtr [MAX];
	voidPtr* unioned = new voidPtr [MAX];

	constructSet (animalArray, size1);
	cout << "\tSet S1 = {";
	getAnimal(animalArray, size1);
	cout << "}" << endl;	

	constructSet (unionAnimal, size2);
	cout << "\tSet S2 = {";
	getAnimal(unionAnimal, size2);
	cout << "}" << endl;
	
	cout << "The union is\n\t{";
	unify (animalArray, unionAnimal, unioned, size, size1, size2);
	getAnimal(unioned, size);
	cout << "}\n" << endl;
	
	cout << "Garbage collection" << endl;
	
	garbageCollection (animalArray, size1);
	cout << "\tSet 1 deleted" << endl;

	garbageCollection (unionAnimal, size2);
	cout << "\tSet 2 deleted" << endl;
	
	garbageCollection (unioned, size);
	cout << "\tSet 3 (union set) deleted" 
		 << "\n-----------------------------------------------------"
		 << endl;
}

void unify (voidPtr* animalArray, voidPtr* unionAnimal, voidPtr* unioned, 
			int& size, int size1, int size2)
{
	int i = 0;
	bool check;
	
	while(i < size1)
	{
		for (int j = 0; j < size2; j++)
		{
			if (getint(animalArray[i]) == getint(unionAnimal[j]))
			{
				unioned [i] = animalArray[i];
				size--;
				check = true;
			}
		}
		if (check != true)
		{
			unioned[i] = animalArray[i];
		}
		i++;
		check = false;
	}
	
	int k = 0;
	while (k < size2)
	{
		for (int j = 0; j < size1; j++)
		{
			if (getint(unionAnimal[k]) == getint(animalArray[j]))
			{
				check = true;
			}
		}
		if (check != true)
		{
			unioned[i] = unionAnimal[k];
			i++;
		}
		
		k++;
		check = false;
	}
	
	size += size1 + size2;
}

//print option2
void option2()
{
	int size1 = rand() % 5;
	int size2 = rand() % 5;
	int size = 0;
	voidPtr* arrayAnimal = new voidPtr [MAX];
	voidPtr* interArray = new voidPtr [MAX];
	voidPtr* intersect = new voidPtr [MAX];
	
	cout << "Given the following two sets" << endl;
	
	cout << "\tSet S1 = {";
	constructSet (arrayAnimal, size1);
	getAnimal(arrayAnimal, size1);
	cout << "}" << endl;
	
	cout << "\tSet S2 = {";
	constructSet (interArray, size2);
	getAnimal (interArray, size2);
	cout << "}" << endl;
	
	cout << "The intersection is\n\t{";
	intersection (arrayAnimal, interArray, intersect, size, size1, size2);
	getAnimal (intersect, size);
	cout << "}" << endl;
	
	cout << "\nGarbage collection" << endl;
	
	garbageCollection (arrayAnimal, size1);
	cout << "\tSet 1 deleted" << endl;
	
	garbageCollection (interArray, size2);
	cout << "\tSet 2 deleted" << endl;
	
	garbageCollection (intersect, size);
	cout << "\tSet 3 (intersection set) deleted" 
		 << "\n-----------------------------------------------------"
		 << endl;	   
}

//check intersection
void intersection (voidPtr* arrayAnimal, voidPtr* interArray, voidPtr* intersect
					,int& size, int size1, int size2)
{
	int k = 0;	  
	for (int i = 0; i < size1;i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if(getint(arrayAnimal[i]) == getint(interArray[j]))
			{
				intersect[k] = arrayAnimal[i];
				k++;
			}
		}
	}
	
	size = k;	 
}

//print option 3
void option3()
{
	int size = rand() % MAX;
	int sizec = 0;
	voidPtr* arrayAnimal = new voidPtr [MAX];
	voidPtr* comple = new voidPtr [MAX];
	
	cout << "Given the following set" << endl;
	
	cout << "\tSet S = {";
	constructSet (arrayAnimal, size);
	getAnimal (arrayAnimal, size);
	cout << "}\n" << endl;
	
	cout << "The completement set\n\tSet S' = {";
	complement (arrayAnimal, comple, size, sizec);
	getAnimal(comple, sizec);
	cout << "}\n" << endl;
	
	cout << "Garbage collection" << endl;
	
	garbageCollection (arrayAnimal, size);
	cout << "\tSet S deleted" << endl;
	
	garbageCollection (comple, sizec);
	cout << "\tSet S' deleted" 
		 << "\n-----------------------------------------------------"
		 << endl;	  
	
}

//complement of option 3
void complement (voidPtr* arrayAnimal, voidPtr* comple, int size, int& sizec)
{
	bool check = true;
	Animal *temp;
	voidPtr vp;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == getint(arrayAnimal[j]))
			{
				check = false;
			}
		}
		if (check == true)
		{
			temp = new Animal;
			*temp = static_cast<Animal>(i);
			vp = temp;
			comple[sizec] = vp;
			sizec++;
		}
		check = true;
	}
}

//print option 4
void option4()
{
	bool check1, check2;
	voidPtr* arrayAnimal = new voidPtr [MAX];
	voidPtr* array = new voidPtr [MAX];
	int size1 = rand() % MAX;
	int size2 = rand() % MAX;
	
	cout << "Given the following two sets\n\tSet S1 = {";
	constructSet(arrayAnimal, size1);
	getAnimal (arrayAnimal, size1);
	cout << "}" << endl;
	
	cout << "\tSet S2 = {";
	constructSet (array, size2);
	getAnimal (array, size2);
	cout << "}\n" << endl;
	
	cout << "Conclusion:" << endl;
	check1 = checkS1subS2 (arrayAnimal, array, size1, size2);
	check2 = checkS1subS2 (array, arrayAnimal, size2, size1);
	
	cout << "\tS1 is";
	printFalse (check1);
	cout << " the subset of S2" << endl;
	
	cout << "\tS2 is";
	printFalse (check2);
	cout << " the subset of S1" << endl;
	
	cout << "\nGarbage collection" << endl;
	
	garbageCollection (arrayAnimal, size1);
	cout << "\tSet 1 deleted" << endl;	
	
	garbageCollection (array, size2);
	cout << "\tSet 2 deleted" 
		 << "\n-----------------------------------------------------"
		 << endl;	     
}

//check if subset
bool checkS1subS2(voidPtr* arrayAnimal, voidPtr* array, int size1, int size2)
{
	bool check = false;
	
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (getint(arrayAnimal[i]) == getint(array[j]))
			{
				check = true;
			}
		}
		if (check != true)
		{
			return false;
		}
		check = false;
	}
	return true;
}

//print out if is or not subset
void printFalse (bool check)
{
	if (check != 1)
	{
		cout << " not";
	}
}

//print out option 5
void option5()
{
	bool checkEq, check1, check2;
	voidPtr* arrayAnimal = new voidPtr [MAX];
	voidPtr* array = new voidPtr [MAX];
	int size1 = rand() % 2 + 3;
	int size2 = rand() % 2 + 3;
	
	cout << "Given the following two sets\n\tSet S1 = {";
	constructSet (arrayAnimal, size1);
	getAnimal (arrayAnimal, size1);
	cout << "}" << endl;
	
	cout << "\tSet S2 = {";
	constructSet (array, size2);
	getAnimal (array, size2);
	cout << "}" << endl;
	
	cout << "\nConclusion:\n\t";
	
	checkEq = checkEqual (arrayAnimal, array, size1, size2);
	cout << "S1 is";
	printFalse(checkEq);
	cout << " equal to S2\n" << endl;
	
	cout << "Reasons:\n\tS1 is";
	check1 = checkS1subS2 (arrayAnimal, array, size1, size2);
	printFalse(check1);
	cout << " the subset of 2" << endl;
	
	cout << "\tS2 is";
	check2 = checkS1subS2 (array, arrayAnimal, size2, size1);
	printFalse(check1);
	cout << " the subset of 1" << endl;
	
	cout << "Garbage collection" << endl;
	
	garbageCollection (arrayAnimal, size1);
	cout << "\tSet 1 deleted" << endl;
	
	garbageCollection (array, size2);
	cout << "\tSet 2 deleted" 
		 << "\n-----------------------------------------------------"
		 << endl;
	
}

//check if both are equal
bool checkEqual (voidPtr* arrayAnimal, voidPtr* array, int size1, int size2)
{
	if (size1 != size2)
		return false;
	
	else
	{
		bool check = false;
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				if (getint(arrayAnimal[i]) == getint(array[j]))
				{
					check = true;
				}
			}
			if (check == false)
			{
				return false;
			}
			check = false;
		}
		return true;
	}
}

//print out option 6
void option6()
{
	cout << "Given the following two sets" << endl;
	
	voidPtr* animalArray = new voidPtr [MAX];
	voidPtr* array = new voidPtr [MAX];
	voidPtr* S1minusS2 = new voidPtr [MAX];
	voidPtr* S2minusS1 = new voidPtr [MAX];
	int size1 = rand() % MAX;
	int size2 = rand() % MAX;
	int size3 = 0;
	int size4 = 0;
	
	cout << "\tSet S1 = {";
	constructSet (animalArray, size1);
	getAnimal (animalArray, size1);
	cout << "}" << endl;
	
	cout << "\tSet S2 = {";
	constructSet (array, size2);
	getAnimal (array, size2);
	cout << "}" << endl;
	
	cout << "\nConclusion:" << endl;
	
	cout << "\tS1 - S2 = {";
	minusOperation (animalArray, array, S1minusS2, size1, size2, size3);
	getAnimal (S1minusS2, size3);
	cout << "}" << endl;
	
	cout << "\tS2 - S1 = {";
	minusOperation (array, animalArray, S2minusS1, size2, size1, size4);
	getAnimal (S2minusS1, size4);
	cout << "}" << endl;
	
	cout << "\nGarbage collection" << endl;
	
	garbageCollection (animalArray, size1);
	cout << "\tSet 1 deleted" << endl;
	
	garbageCollection (array, size2);
	cout << "\tSet 2 deleted" << endl;
	
	garbageCollection (S1minusS2, size3);
	cout << "\tSet S1 - S2 deleted" << endl;
	
	garbageCollection (S2minusS1, size4);
	cout << "\tSet S2 - S1 deleted" 
		 << "\n-----------------------------------------------------"
		 << endl;
}

//minus function
void minusOperation (voidPtr* animalArray, voidPtr* array, voidPtr* result
					, int size1, int size2, int& size)
{
	bool check = false;
	for(int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (getint(animalArray[i]) == getint(array[j]))
			{
				check = true;
			}
		}
		if (check == false)
		{
			result[size] = animalArray[i];
			size++;
		}
		check = false;
	}
}

//print option 7
void option7 ()
{
	cout << "Given the following three sets" << endl;
	
	voidPtr* a = new voidPtr [MAX];
	voidPtr* b = new voidPtr [MAX];
	voidPtr* c = new voidPtr [MAX];
	int sizeA = rand() % MAX;
	int sizeB = rand() % MAX;
	int sizeC = rand() % MAX;
	
	voidPtr* LHS1 = new voidPtr [MAX];
	voidPtr* LHS2 = new voidPtr [MAX];
	voidPtr* RHS1 = new voidPtr [MAX];
	voidPtr* RHS2 = new voidPtr [MAX];
	voidPtr* RHS3 = new voidPtr [MAX];
	
	int size1 = 0;
	int size2 = 0;
	int size3 = 0;
	int size4 = 0;
	int size5 = 0;
	
	cout << "\tSet A = {";
	constructSet (a, sizeA);
	getAnimal (a, sizeA);
	cout << "}" << endl;
	
	cout << "\tSet B = {";
	constructSet (b, sizeB);
	getAnimal (b, sizeB);
	cout << "}" << endl;
	
	cout << "\tSet C = {";
	constructSet (c, sizeC);
	getAnimal (c, sizeC);
	cout << "}" << endl;
	
	cout << "\nWe wish to prove the following distributive law"
		 << "\n  Note that I stands for intersection and"
		 << "\n            U stands for union"
		 << "\n\n\tA I (B U C) = (A I B) U (A I C)"
		 << endl;
	
	cout << "\nAnalysis of L.H.S."
		 << "\n-----------------------------------------------------\n"
		 << endl;
	
	cout << "\tThe union of B and C is\n\t{";
	unify (b, c, LHS1, size1, sizeB, sizeC);
	getAnimal (LHS1, size1);
	cout << "}" << endl;
	
	cout << "\n\tTherefore the set of the L.H.S.\n\t{";
	intersection (a, LHS1, LHS2, size2, sizeA, size1);
	getAnimal (LHS2, size2);
	cout << "}" << endl;
	
	cout << "\nAnalysis of R.H.S."
		 << "\n==================\n"
		 << endl;
	
	cout << "\tThe intersection of A and B\n\t{";
	intersection (a, b, RHS1, size3, sizeA, sizeB);
	getAnimal (RHS1, size3);
	cout << "}" << endl;
	
	cout << "\n\tThe intersection of A and C\n\t{";
	intersection (a, c, RHS2, size4, sizeA, sizeC);
	getAnimal (RHS2, size4);
	cout << "}" << endl;
	
	cout << "\n\tTherefore the set of R.H.S.\n\t{";
	unify (RHS1, RHS2, RHS3, size5, size3, size4);
	getAnimal (RHS3, size5);
	cout << "}" << endl;
	
	cout << "\nConclusion: L.H.S. = R.H.S. ==> Q.E.D."
		 << endl;
	
	cout << "\nGarbage collection" << endl;
	
	garbageCollection (a, sizeA);
	cout << "\tSet A deleted" << endl;
	
	garbageCollection (b, sizeB);
	cout << "\tSet B deleted" << endl;
	
	garbageCollection (c, sizeC);
	cout << "\tSet C deleted" << endl;
	
	cout << "\nNote that I used some dummy arrays to store the info" << endl;
	
	garbageCollection (LHS1, size1);
	cout << "\tDummy set 1 deleted" << endl;
	
	garbageCollection (LHS2, size2);
	cout << "\tDummy set 2 deleted" << endl;
	
	garbageCollection (RHS1, size3);
	cout << "\tDummy set 3 deleted" << endl;
	
	garbageCollection (RHS2, size4);
	cout << "\tDummy set 4 deleted" << endl;
	
	garbageCollection (RHS3, size5);
	cout << "\tDummy set 5 deleted" 
		 << "\n-----------------------------------------------------"
		 << endl;
}

//Garbage collection
void garbageCollection (voidPtr* animalArray, int size)
{
	int i = 0;
	voidPtr* vp = &*animalArray;
	
	while (i < size)
	{
		delete []vp;
		vp = NULL;
		i++;
	}
}

