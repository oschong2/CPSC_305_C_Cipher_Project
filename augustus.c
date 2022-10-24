#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "caesar.h"
#include <string.h>

//NOTE: "encChar" is a char that represents an encrypted character
//NOTE: "keyLen" is an integer that represents the number of digits in the key
//NOTE: "caesarStr" is a char pointer that represents the encrypted plain string after the first Caesar Cipher run
//NOTE: "augStr" is a char pointer that represents the encrypted Caesar string after the second Caesar Cipher run


char *augustus_encrypt(char *plain, char *key) {
    int trueKey = convert_key(key) % 26;

    printf("\n plain is %s\n", plain);

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
    printf("\n%s was Caesar encrypted to %s\n", plain, encStrA);

    char *encStrB = malloc(plainLen + 1);
    
    char keyChar[1];
    char *keyPointer;
    int keyDigit;
    
    int k  = 0;
    int i = 0;
    printf("\nFirst, the key is %d\n\n", trueKey);

    while(i < plainLen) {

        printf("\ni starts the loop at %d\n", i);
        
        while(k < keyLen){
            keyChar[0] = key[k];
            printf("\nkeyChar is %c\n", keyChar[0]);

            keyPointer = keyChar;
            printf("keyPointer is %c\n", keyPointer[0]);
            printf("The length of keyPointer is %d\n", (int) strlen(keyPointer));

            keyDigit = convert_key(keyPointer);
            printf("keyDigit is %d\n", keyDigit);

            encStrB[i] = caesar_encrypt_char(encStrA[i], keyDigit);
            printf("%c was Caesar encrypted by %d to get the Augustus encrypted %c\n\n", encStrA[i], keyDigit, encStrB[i]);
            i++;
            printf("i is %d\n", i);

            k++;
            printf("k is %d\n\n", k);
        }
        k = 0;
        printf("i ends the loop at %d\n", i);
    }
    
    return encStrB;
}


char *augustus_decrypt(char *cipher, char *key) {
    int trueKey = convert_key(key) % 26;

    printf("\n Augustus string is %s\n", cipher);

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

    //Create a char pointer "encStr" to hold the encrypted string
    char *decStrA = malloc(cipherLen + 1);

    char keyChar[1];
    char *keyPointer;
    int keyDigit;
    
    int k  = 0;
    int i = 0;
    printf("\nFirst, the key is %d\n\n", trueKey);

    while(i < cipherLen) {

        printf("\ni starts the loop at %d\n", i);
        
        while(k < keyLen){
            keyChar[0] = key[k];
            printf("\nkeyChar is %c\n", keyChar[0]);

            keyPointer = keyChar;
            printf("keyPointer is %c\n", keyPointer[0]);
            printf("The length of keyPointer is %d\n", (int) strlen(keyPointer));

            keyDigit = convert_key(keyPointer);
            printf("keyDigit is %d\n", keyDigit);

            decStrA[i] = caesar_decrypt_char(cipher[i], keyDigit);
            printf("%c was Caesar decrypted by %d to get the Augustus decrypted %c\n\n", cipher[i], keyDigit, decStrA[i]);
            i++;
            printf("i is %d\n", i);

            k++;
            printf("k is %d\n\n", k);
        }
        k = 0;
        printf("i ends the loop at %d\n", i);

    }

    char *decStrB = malloc(cipherLen + 1);
    decStrB = caesar_decrypt(decStrA, key);
    printf("\n%s was Caesar decrypted to %s\n", decStrA, decStrB);
    
    return decStrB;


}
