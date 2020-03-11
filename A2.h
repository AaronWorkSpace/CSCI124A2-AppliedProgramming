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

