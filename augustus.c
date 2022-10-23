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


    //Call "Augustus_encrypt_char(char plain, int key)" to encrypt each character of "plain"
    for(int i = 0; i < plainLen; i++) {
        encStrA[i] = Augustus_encrypt_char(plain[i], trueKey);
    }

    char *caesarStr =encStrA;
    
    //return afterrrr going throught the second part

}



char Augustus_encrypt_char(char plain, int key) {
    //Only three sets of characters can be encrypted: 'a' to 'z', 'A' to 'Z', and '!' to ';'
        //For example, spaces aren't encrypted
        //For example, if you're encrypting y with a key of 7, y must wrap around to f

    //encChar to hold the encrypted version
    char encChar;

    //lowerBound to hold the bottom
    char lowerBound;

    //upperBound to hold the top
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
//        printf("\nEncrypting %c exceeds %c, so it's wrapped around to %c\n", plain, upperBound, encChar);
    }
    
    //Otherwise, encrypt "plain" normally.
    else {
        encChar = plain + key;
    }
    
    //make the key into an array
    
    //end of ceaser,  now add Augustus
    f((encChar + key) > upperBound) {
        encChar = encChar + key - 26;
    }
    

//    printf("The encrypted char is %c\n", encChar);

    return encChar;
}

			

/*char *augustus_encrypt(char *plain, char *key) {

	//Placeholder code so the functions don't break.
	char *placeholder = "Placeholer String";
	return placeholder;
}*/


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

