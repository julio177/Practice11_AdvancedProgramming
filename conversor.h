//
//Autor: Julio César Aguilar Villanueva
//Matrícula: A01152537
//Fecha: 13/09/2016
//
//P8. Pointers and streams
#include <stdio.h>
#include <stdlib.h>
//Library for pow function
#include <math.h>
//Library for strlen function
#include <string.h>

//In order to use as static library
//#inlcude "conversor.h"

//Function to change a binary string to integer
//Receives the starting character pointer to the string
int asciiBinaryToInt(char *ptr)
{
    //Variable to acumulate the final value of the binary number
    int iSum = 0;
    int iLength = strlen(ptr);
    //Cycle to go through the string
    for(ptr; *ptr != '\0'; ptr++)
    {
        //If a value of 1 is found, add to the final value
        if(*ptr == '1')
        {
            //Adds to the acumulated 2 elevated to the position in size
            iSum += pow(2, iLength - 1);
            //Decreases size
            iLength--;
        }
        //If pointer it's just 0, decrease size
        else if(*ptr == '0')
        {
            iLength--;
        }

        //If it receives an invalid number, different to 0 or 1
        else
        {
            printf("Invalid number.\n");
            return -1;
        }
    }
    return iSum;
}

//Function to change a hexadecimal string to decimal
//Receives the starting character pointer to the string
int asciiHexToInt(char *ptr)
{
    //Variable to acumulate the final value of the binary number
    int iSum = 0;
    int iLength = strlen(ptr);
    //Cycle to go through the string
    for(ptr; *ptr != '\0'; ptr++)
    {
        //Validates if the char has value of a cap letter from A to F
        if(*ptr >= 65 && *ptr <= 70)
        {
            //Adds to the total the value of the char times 16 elevated to power position
            iSum += (*ptr - 55) * pow(16, iLength - 1);

            //Decrease size
            iLength--;
        }

        //Validates if the char has value of a letter from a to f
        else if(*ptr >= 97 && *ptr <= 102)
        {
            //Adds to the total the value of the char times 16 elevated to power position
            iSum += (*ptr - 87) * pow(16, iLength - 1);

            //Decrease size
            iLength--;
        }

        //Validates if the char has a value from 0 - 9
        else if(*ptr >= 48 && *ptr <= 57)
        {
            //Adds to the total the value of the char times 16 elevated to power position
            iSum += (*ptr - 48) * pow(16, iLength - 1);

            //Decrease size
            iLength--;
        }
        else
        {
            //If an invalid character is read prints an error
            printf("Invalid number.\n");
            return -1;
        }
    }
    return iSum;
}

//Function to return a double precision number instead of a float
//Receives the starting character pointer to the string
double asciiToDouble(char *ptr)
{
    //Array that will store the new string value with double presicion
    int iLength = strlen(ptr);

    char *sArr1 = (char *)malloc(iLength);

    //Counter to insert in the right positions of the array
    int iCont = 0;

    //Declares value to be returned
    float f;

    //Cycle to go through the string
    for(ptr; *ptr != '\0'; ptr++, iCont++)
    {
        //Validates value of character being a number or a sign, and not being / or ,
        if(*ptr>= 43 && *ptr<=57 && *ptr!=44 && *ptr !=47)
        {
            //Pasa valor de apuntador al arreglo
            sArr1[iCont] = *ptr;

        }
        else
        {
            //If an invalid character is read prints an error
            printf("Invalid number.\n");
            return -1;
        }
    }

    //Construye el double
    sscanf(sArr1, "%f", &f);

    free(sArr1);
    //Retorna el numero como float
    return f;
}