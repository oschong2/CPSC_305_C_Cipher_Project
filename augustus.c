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
		//(✿ ◕ᗜ◕)━♫.*･｡ﾟ 1a. Save this encryption in a char pointer like "caesarStr"
//(✿ ◕ᗜ◕)━♫.*･｡ﾟ2.1 Find the length of the key (see lines 203-206 in "caesar.c")

//2.2 Save each digit of the key in a char like "keyDigit" using "key[i]", where 'i' is a number
//2.3.1 For-loop through the length of the key, running "caesar_encrypt_char(encChar, keyDigit)"
    //2.3.2 If you reach "keyLen", make "keyDigit" the first digit of the key
    //2.3.3 Something like "keyDigit = key[0];"

char *Augustus_encrypt(char *plain, char *key) {
    int trueKey = convert_key(key) % 26;

    //Find & store the length of the key
    int keyLen = 0;
    while(key[keyLen] != 0) {
        keyLen++;
    }

    //Find the length of plain
    int plainLen = 0;
    while(plain[plainLen] != 0) {
        plainLen++;
    }

    //Create a char pointer "encStr" to hold the encrypted string
    char *encStrA = malloc(plainLen + 1);

    encStrA = caesar_encrypt(plain, key);
    char *encStrB = malloc(encStrA + 1);
    
    char keyDigit;
    char *keyPointer;
    int keyDigit;
    
    int k  = 0;
    for(int i = 0; i < plainLen; i++) {
        
        while(k < keyLen){
            keyDigit = key[k];
            keyPointer = &keyDigit;
            keyDigit = convert_key(keyPointer);
            encStrB[i] = caesar_encrypt_char(encStrA[i], keyDigit);
            i++;
            k++;
        }
        k = 0;
    }
    
    return encStrB;
}



//Augustus decryption is the opposite of Augustus encryption.

	//Thus, see above, but START at "Step 3", and END at "Step 1"
	//And, instead of using "caesar_encrypt(char *plain, char *key)",
		 //and "caesar_encrypt_char(char plain, int key)",
	
	//Use "caesar_decrypt(char *cipher, char *key)",
		//and "caesar_decrypt_char(char cipher, int key)" respectively.
//SEE GITHUB FOR DECRYPTION METHODS!!!


char augustus_decrypt(char cipher, int key) {
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
    }else if ((cipher >= 'A') && (cipher <= 'Z')) {
    //Otherwise, if the character ranges from 'A' to 'Z',
        lowerBound = 'A';
        upperBound = 'Z';
    }
    

    //Otherwise, if the character ranges from '!' to ';',
    else if ((cipher >= '!') && (cipher <= ';')) {
        lowerBound = '!';
        upperBound = ';';
    }else {
    //Otherwise, the character cannot be decrypted. Return "cipher". This is the fail safe boii
        return cipher;
    }

    //Now, if decrypting the character goes below "lowerBound",
    if((cipher - key) < lowerBound) {

        //Wrap the character around to the end of the range.
        decChar = cipher - key + 26;
//        printf("\nDecrypting %c goes below %c, so it's wrapped around to %c\n", cipher, lowerBound, decChar);
    }else {
    //Otherwise, decrypt "cipher" normally.
        decChar = cipher - key;
    }

//    printf("The decrypted char is %c\n", decChar);
    return decChar;

}


//delete this after char augustus_decrypt is done
/*
char *augustus_decrypt(char *cipher, char *key) {

	//Placeholder code so the functions don't break.
	char *placeholder = "Placeholder String";
	return placeholder;
}
 */

