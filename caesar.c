#include "caesar.h"
#include "strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//File that contains the functions for the Caesar cipher and function definitions for caesar.h

//Encrypts the string "*plain" using the key "*key"
//*key is a either a string itself or just an integer

//YOU'RE SUPPOSED TO CALL "encrypt_caesar_char(char plain, int key)" over and over to encrypt each individual char!!!
char *caesar_encrypt(char *plain, char *key) {

	//For now, "plain" (no pointer) holds the string, and "*key" (with the pointer) holds the key
	
	int trueKey = convert_key(key) % 26;
//	printf("\nThe encryption key is %d\n", trueKey);

	//Find the length of plain
	int plainLen = 0;
	while(plain[plainLen] != 0) {
		plainLen++;
	}
//	printf("\n\nThe size of plain is %d\n", plainLen);

	//Create a char pointer "encStr" to hold the encrypted string
	char *encStr = malloc(plainLen + 1);


	//Call "encrypt_caesar_char(char plain, int key)" to encrypt each character of "plain"
	for(int i = 0; i < plainLen; i++) {
		encStr[i] = caesar_encrypt_char(plain[i], trueKey);
//		printf("\n%c became %c\n\n", plain[i], encStr[i]);
	}

	return encStr;

}

char *caesar_decrypt(char *cipher, char *key) {
 
	//For now, "plain" (no pointer) holds the string, and "*key" (with the pointer) holds the key
	
	int trueKey = convert_key(key) % 26;
//	printf("\nThe encryption key is %d\n", trueKey);

	//Find the length of plain
	int cipherLen = 0;
	while(cipher[cipherLen] != 0) {
		cipherLen++;
	}
//	printf("\n\nThe size of plain is %d\n", plainLen);

	//Create a char pointer "encStr" to hold the encrypted string
	char *decStr = malloc(cipherLen + 1);


	//Call "encrypt_caesar_char(char plain, int key)" to encrypt each character of "plain"
	for(int i = 0; i < cipherLen; i++) {
		decStr[i] = caesar_decrypt_char(cipher[i], trueKey);
//		printf("\n%c became %c\n\n", plain[i], encStr[i]);
	}

	return decStr;
   


}


//ADD BRANCHES FOR THE 3 SUBSETS OF ENCRYPTABLE CHARACTERS!
//SEE CAMERA ROLL FOR OFFICE HOURS ALGORITHM!!
char caesar_encrypt_char(char plain, int key) {
//	printf("\nThe original char is %c\n", plain);

	//Only three sets of characters can be encrypted: 'a' to 'z', 'A' to 'Z', and '!' to ';'
		//For example, spaces aren't encrypted
		//For example, if you're encrypting y with a key of 7, y must wrap around to f

	//Create a char "encChar" to hold the encrypted version of "plain".
	char encChar;

	//Create a char "lowerBound" to hold the bottom of one of these ranges.
	char lowerBound;

	//Create a char "upperBound" to hold the top of one of these ranges.
	char upperBound;	

	//If the character ranges from 'a' to 'z',
	if((plain >= 'a') && (plain <= 'z')) {
		lowerBound = 'a';
		upperBound = 'z';
	}

	//Otherwise, if the character ranges from 'A' to 'Z',
	else if ((plain >= 'A') && (plain <= 'Z')) {
		lowerBound = 'A';
		upperBound = 'Z';
	}

	//Otherwise, if the character ranges from '!' to ';',
	else if ((plain >= '!') && (plain <= ';')) {
		lowerBound = '!';
		upperBound = ';';
	}

	//Otherwise, the character cannot be encrypted. Return "plain".
	else {
		return plain;
	}

	//Now, if encrypting the character exceeds "upperBound",
	if((plain + key) > upperBound) {

		//Wrap the character around to the beginning of the range.
		encChar = plain + key - 26;
//		printf("\nEncrypting %c exceeds %c, so it's wrapped around to %c\n", plain, upperBound, encChar);
	}
	
	//Otherwise, encrypt "plain" normally.
	else {
		encChar = plain + key;
	}

//	printf("The encrypted char is %c\n", encChar);
	return encChar;
}

//SEE GITHUB FOR DECRYPTION METHODS!!!
char caesar_decrypt_char(char cipher, int key) {
//	printf("\nThe original char is %c\n", cipher);

	//Only three sets of characters can be decrypted: 'a' to 'z', 'A' to 'Z', and '!' to ';'
		//For example, spaces aren't decrypted
		//For example, if you're decrypting b with a key of 7, y must wrap around to u

	//Create a char "decChar" to hold the decrypted version of "cipher".
	char decChar;

	//Create a char "lowerBound" to hold the bottom of one of these ranges.
	char lowerBound;

	//Create a char "upperBound" to hold the top of one of these ranges.
	char upperBound;	

	//If the character ranges from 'a' to 'z',
	if((cipher >= 'a') && (cipher <= 'z')) {
		lowerBound = 'a';
		upperBound = 'z';
	}

	//Otherwise, if the character ranges from 'A' to 'Z',
	else if ((cipher >= 'A') && (cipher <= 'Z')) {
		lowerBound = 'A';
		upperBound = 'Z';
	}

	//Otherwise, if the character ranges from '!' to ';',
	else if ((cipher >= '!') && (cipher <= ';')) {
		lowerBound = '!';
		upperBound = ';';
	}

	//Otherwise, the character cannot be decrypted. Return "cipher".
	else {
		return cipher;
	}

	//Now, if decrypting the character goes below "lowerBound",
	if((cipher - key) < lowerBound) {

		//Wrap the character around to the end of the range.
		decChar = cipher - key + 26;
//		printf("\nDecrypting %c goes below %c, so it's wrapped around to %c\n", cipher, lowerBound, decChar);
	}
	
	//Otherwise, decrypt "cipher" normally.
	else {
		decChar = cipher - key;
	}

//	printf("The decrypted char is %c\n", decChar);
	return decChar;

}

int convert_key(char *key) {

//	printf("\nThe initial key is %s", key);

	//Create an int "isNumber" to store whether the key is a number
		//1 means "yes, the key is a number"
		//0 means "no, the key contains characters, it must be XOR'd"
	int isNumber = 1;

	//Establish an int "keyLen" to hold the length of the key.
	int keyLen = 0;

	//Lastly, establish an int "newKey" to store the key to return.
	int newKey = 0;

	//Find the length of "key".
	while(key[keyLen] != 0) {
		keyLen++;
	}

	//Iterate through the characters of "key" to check for non-digits.
	for(int i = 0; i < keyLen; i++) {

//		printf("\nThe current character is %c\n", key[i]);

		//If the key character is NOT a digit, set "isNumber" to 0, and exit the loop.
		if(isdigit(key[i]) == 0) {
//			printf("\n%c is NOT a digit!", key[i]);
			isNumber = 0;
			break;
		}

	}

	//If "isNumber" is 1, meaning the key is a number,
	if(isNumber == 1) {

		//Convert "key", a char *, to an integer via "atoi(char *)".
		newKey = atoi(key);

	}
	//Else, iterate through "*key" and XOR each bit.
	else {
		for(int i = 0; i < keyLen; i++) {

			//XOR each key character with "newKey"
//			printf("\n%c (%d) ^ %c (%d) is %d", newKey, newKey, key[i], key[i], newKey ^ key[i]);
			newKey = newKey ^ key[i];
		}
	}
	
	
//	printf("\n\nThe converted key is %d\n", newKey);

	//Return the converted key as "newKey", an integer.
	return newKey;
}
