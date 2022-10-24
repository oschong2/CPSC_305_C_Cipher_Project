#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "caesar.h"

//NOTE: "encChar" is a char that represents an encrypted character
//NOTE: "keyLen" is an integer that represents the number of digits in the key
//NOTE: "caesarStr" is a char pointer that represents the encrypted plain string after the first Caesar Cipher run
//NOTE: "augStr" is a char pointer that represents the encrypted Caesar string after the second Caesar Cipher run


char *augustus_encrypt(char *plain, char *key) {
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


char augustus_decrypt(char cipher, char *key) {
    //Create a char pointer "encStr" to hold the encrypted string
    int trueKey = convert_key(key) % 26;

    //Find & store the length of the key
    int keyLen = 0;
    while(key[keyLen] != 0) {
        keyLen++;
    }

    //Find the length of plain
    int cipherLen = 0;
    while(cipher[cipherLen] != 0) {
        cipherLen++;
    }
    
    char *decStrA = malloc(cipherLen + 1);

    char keyDigit;
    char *keyPointer;
    int keyDigit;
    
    int k  = 0;
    for(int i = 0; i < cipherLen; i++) {
        
        while(k < keyLen){
            keyDigit = key[k];
            keyPointer = &keyDigit;
            keyDigit = convert_key(keyPointer);
            decStrA[i] = caesar_decrypt_char(cipher, keyDigit);
            i++;
            k++;
        }
        k = 0;
    }

    char *decStrB = malloc(cipherLen + 1);
    decStrB = caesar_decrypt(plain, key);
    
    return decStrB;

}
