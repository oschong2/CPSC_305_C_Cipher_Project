#include <stdio.h>
#include "caesar.h"
#include <strings.h>
#include <ctype.h>


//THIS WILL CONTAIN;
//File interpreter, default tests, CL interface

//This file us where we write our code
//This file tests:
//1. "caesar_encrypt_char(char plain, int key)
//2. "caesar_encrypt(char *plain, char *key)"

int main()
{
	//Create a char "orig" to be encrypted
	char orig = 'A';

	//Create an int "key" to encrypt "orig"
	int key = 2;

	//Call "caesar_encrypt_char(char plain, char key)", passing in "orig" and "key" respectively
		//Return the value into a char "enc", the encrypted version of "orig"
	char enc = caesar_encrypt_char(orig, key);

	//Double check the result of "enc"
	printf("\nThe value of enc is %c\n\n\n", enc);



     	//Create a char array "sampleStr" to hold a string we want to encrypt
	char sampleStr[] = "ABCD";

	//Create a char pointer "*strPtr" to point to "sampleStr". Now we can access each "sampleStr" chararcter using indexes, like strPtr[0] = 'O', etc
	char *strPtr = sampleStr;
    	printf("\n%c\n", strPtr[0]);
	    
    	//Create an char "k" as an integer key
	char k = 1;

    	//Create a char pointer "cKey" to point to the address of the integer key
	//This is what is passed into "caesar_encrypt(char *plain, char *key)
	char *cKey = &k;
    	char *encryption = caesar_encrypt(strPtr, cKey);
      	printf("\n\n%s became %s\n\n", sampleStr, encryption);

}
