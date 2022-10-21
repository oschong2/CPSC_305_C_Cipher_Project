#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "caesar.h"

//NOTE: "encChar" is a char that represents an encrypted character
//NOTE: "keyLen" is an integer that represents the number of digits in the key
//NOTE: "caesarStr" is a char pointer that represents the encrypted plain string after the first Caesar Cipher run
//NOTE: "augStr" is a char pointer that represents the encrypted Caesar string after the second Caesar Cipher run

//Augustus encryption is something like the following (not the only way to do it, but a general concept):
	//1. Use "caesar_encrypt(char *plain, char *key)" to encrypt "plain" via the Caesar Cipher and "key"
		//1a. Save this encryption in a char pointer like "caesarStr"
	
	//2. Then, use "caesar_encrypt_char(char plain, int key)" to encrypt each character using the digits of the key
		//2a. Find the length of the key (see lines 203-206 in "caesar.c")
		//2b. Save each digit of the key in a char like "keyDigit" using "key[i]", where 'i' is a number
		//2c. For-loop through the length of the key, running "caesar_encrypt_char(encChar, keyDigit)"
			//2c.1. If you reach "keyLen", make "keyDigit" the first digit of the key
				//2c.1.1. Something like "keyDigit = key[0];"
	
	//3. After "Step 2", save the Augustus string in a char pointer "like augStr"
			

char *augustus_encrypt(char *plain, char *key) {

	//Placeholder code so the functions don't break.
	char *placeholder = "Placeholer String";
	return placeholder;
}


//Augustus decryption is the opposite of Augustus encryption.

	//Thus, see above, but START at "Step 3", and END at "Step 1"
	//And, instead of using "caesar_encrypt(char *plain, char *key)",
		 //and "caesar_encrypt_char(char plain, int key)",
	
	//Use "caesar_decrypt(char *cipher, char *key)",
		//and "caesar_decrypt_char(char cipher, int key)" respectively.
	
char *augustus_decrypt(char *cipher, char *key) {

	//Placeholder code so the functions don't break.
	char *placeholder = "Placeholder String";
	return placeholder;
}

