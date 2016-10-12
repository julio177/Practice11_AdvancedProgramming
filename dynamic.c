//
//Autor: Julio César Aguilar Villanueva
//Matrícula: A01152537
//Fecha: 22/09/2016
//
//P9. Malloc
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DllExport __declspec(dllexport)

//Function to ask for more memory when the string grows
//Frees the space of the last memory being used
DllExport void resize(char *cp, int *iMax)
{
	//New char pointer of the string
	char *cpString;

	//Increments max size
	*iMax += 5;

	//Allocates more memory size
	cpString = (char *)malloc(*iMax);

	//Copies value
	strcpy(cpString, cp);

	//Reassigns
	cp = cpString;

	//Free
	free(cp);
}

//Main function of the program
DllExport int extremelyLargeString()
{
	//Character pointer for the array, initial pos and a auxiliar
	char *cpArr, *cpInitial, *cpTemporal;

	//Maximum initial size
	int iMax = 10;

	//Counter to compare to max
	int iCont = 0;

	//Allocates initial memory
	cpArr = (char *)malloc(iMax);

	//Saves the initial position
	cpInitial = cpArr;

	//Instruction to be able to print
    setvbuf (stdout, NULL, _IONBF, 0);

    //Cycle to read
    do
	{
		//if the values read are less than max
		if(iCont < iMax)
		{
			//Gets input char
			*cpArr = getchar();

			//Temporal for comparison
			cpTemporal = cpArr;

			//Increments to keep reading
			cpArr++;

			//Increments conters
			iCont++;
		}
		else
			//If the counter passes the current maximum
			//Execute procedure which asks for more
			//The cpInitial is sent so everything from the start is backed
			resize(cpInitial, &iMax);
		//Keep reading until an EOL is received
	} while(*cpTemporal != '\n');

	//Prints the string read with tab spaces
	while(iCont > 1) {
		//Uses the cpInitial
		printf("%c", *cpInitial);
		//Goes through the chars
		cpInitial++;
		//Decrements counter to know how to read
		iCont--;
	}
	//The last character, EOL (enter) is not printed
	return 0;
}