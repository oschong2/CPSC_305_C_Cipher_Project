#include "caesar.h"
#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

//File that contains the functions for the Caesar cipher and function definitions for caesar.h

//Encrypts the string "*plain" using the key "*key"
//*key is a either a string itself or just an integer

//YOU'RE SUPPOSED TO CALL "encrypt_caesar_char(char plain, int key)" over and over to encrypt each individual char!!!
char *caesar_encrypt(char *plain, char *key) {

	//For now, "plain" (no pointer) holds the string, and "*key" (with the pointer) holds the key

	//Find the length of plain
	int plainLen = 0;
	while(plain[plainLen] != 0)
	{
		plainLen++;
	}
	printf("\n\nThe size of plain is %d\n", plainLen);

	//Create a char pointer "encStr" to hold the encrypted string
	char *encStr = malloc(plainLen + 1);


	//Call "encrypt_caesar_char(char plain, int key)" to encrypt each character of "plain"
	return plain;

}

char *caesar_decrypt(char *cipher, char *key) {
    


}

char caesar_encrypt_char(char plain, int key) {
	printf("\nThe original char is %c\n", plain);
//	printf("\nThe integer key is %d\n", key);

	int caesarKey = key % 26;
//	printf("\nThe Caesar key is %d", caesarKey);

	char encChar = plain + caesarKey;
	printf("The encrypted char is %c\n", encChar);
	return encChar;
}

char caesar_decrypt_char(char cipher, int key) {

}

int convert_key(char *key) {
	//Loops through key, checks if digits are 0-9
	//If key is all digits, just convert to int
	//ELSE, XOR EVERYTHING. The XOR operator is "^"
	
	int keyInt = *key;
	return keyInt;
}
