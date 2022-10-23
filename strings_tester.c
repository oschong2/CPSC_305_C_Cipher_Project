#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#include "caesar.h"
#include "augustus.h"
#include "default_tests.h"

//This is the main file for all of the code.

/*
TO DO LIST:

	OVERALL:
		1. Figure out how AES encryption/decryption works!
		2. Work on "strings.h" for the default tests!

	CL Processor:
		1. Fix input code for adding Augustus and AES input strings
		2. Move printing code outside of the cipher if-statements.
		3. Add default key for AES cipher
		4. Add AES cipher encryption/decryption code

	DEFAULT TESTS:
		1. Uncomment out Augustus AFTER Augustus is done!
		2. Uncomment out AES AFTER AES is done!

	FILE INPUT:
		1. Figure out why "ciphers.txt" is 151 lines but "numLines" is 154
		2. Parse through important information (IGNORE lines with "#")



*/

int main(int argc, char **argv) {

	//Create char * "userCommand" to hold the main argument passed in by the user.
	char *userCommand = argv[1];
	printf("\nuserCommand is %s\n", userCommand);

	//If the user does NOT enter a main argument,
	if (userCommand == NULL) {

		//Print the default keys.
		printf("Default Keys:\n");
		printf("Caesar: 1\n");
		printf("Augustus: 12 (coming soon!)\n");
		printf("AES: coming soon!\n\n");

	//Store user cipher, string, and key.

		//Create a char arrays "cipherCmdArray", "cipherTextArray", and "cipherKeyArray" to store the user's requested cipher, plain string, and key respectively.
		char cipherCmdArray[4];
		char cipherTextArray[100];
		char cipherKeyArray[100];

		//Create char pointers "cipherCmdString", "cipherTextString", and "cipherKeyArray" to store the user's requested cipher, plain string, and key respectively.
		char *cipherCmdString = malloc(4);
		char *cipherTextString = malloc(100);
		char *cipherKeyString = malloc(100);

		//Create char pointers "encString" and "decString" to hold the values of encrypted and decrypted strings.
		char *encString;
		char *decString;

		//Prompt the user to enter the cipher they want and store it in "cipherCmdString".
		printf("Enter command - q(uit), c(aesar), au(gustus), ae(s): ");
		fgets(cipherCmdArray, 4, stdin);
		cipherCmdArray[strcspn(cipherCmdArray, "\n")] = '\0';
		cipherCmdString = cipherCmdArray;

		while(strcmp(cipherCmdString, "q") != 0) {

			printf("\ncipherCmdString is !!%s!! with length %d\n", cipherCmdString, (int) strlen(cipherCmdString));
			printf("\ncipherTextString is !!%s!! with length %d\n", cipherTextString, (int) strlen(cipherTextString));
			printf("\ncipherKeyString is !!%s!! with length %d\n", cipherKeyString, (int) strlen(cipherKeyString));

			printf("\nTOP OF WHILE LOOP\n");
			//Prompt the user to enter the string they want to encrypt and store it in "cipherTextString".
			printf("\n\nEnter string: "); //THIS DOESNT WORK FOR AUGUSTUS AND AES FOR SOME REASON?!?!?!?!!
			fgets(cipherTextArray, 100, stdin);
			cipherTextArray[strcspn(cipherTextArray, "\n")] = '\0';
			cipherTextString = cipherTextArray;

			//Prompt the user to enter the encryption key they want and store it in "cipherKeyString".
			printf("\n\nEnter key (Enter for default): ");
			fgets(cipherKeyArray, 100, stdin);
			cipherKeyArray[strcspn(cipherKeyArray, "\n")] = '\0';
			cipherKeyString = cipherKeyArray;

			//If the user wanted the Caesar cipher,
			if(strcmp(cipherCmdString, "c") == 0) {

				//and iff the user wanted the default Caesar key,
				if( ((int) strlen(cipherKeyString)) == 0) {

					//set "cipherKeyString" as the default key.
					cipherKeyString = "1";
				}

				//Otherwise, use "cipherKeyString" as it is.

				//Store the encrypted "cipherTextString" in "encString", and the decrypted "encString" in "decString".
				encString = caesar_encrypt(cipherTextString, cipherKeyString);
				decString = caesar_decrypt(encString, cipherKeyString);

				//Output the first 16 characters of the plain string.
				int textLen = strlen(cipherTextString);
				printf("\nPlain text string:\n");
				printf("len: %d\n", textLen);
				for(int i = 0; i < 16; i++) {
					if(i < textLen) {
						printf("%x ", cipherTextString[i]);
					}
					else {
						printf("_0 ");
					}
				}
				printf(" |  %s\n", cipherTextString);

				//Output the first 16 characters of the encrypted string.
				printf("\nCipher text string:\n");
				printf("len: %d\n", textLen);
				for(int i = 0; i < 16; i++) {
					if(i < textLen) {
						printf("%x ", encString[i]);
					}
					else {
						printf("_0 ");
					}
				}
				printf(" |  %s\n", encString);

				//Output the first 16 characters of the decrypted string.
				printf("\nDecrypted input:\n");
				printf("%s\n", decString);
				printf("len: %d\n", textLen);
				for(int i = 0; i < 16; i++) {
					if(i < textLen) {
						printf("%x ", cipherTextString[i]);
					}
					else {
						printf("_0 ");
					}
				}
				printf(" |  %s\n", cipherTextString);

				printf("\nlen: %d\n", textLen);
				for(int i = 0; i < 16; i++) {
					if(i < textLen) {
						printf("%x ", cipherTextString[i]);
					}
					else {
						printf("_0 ");
					}
				}
				printf(" |  %s\n", cipherTextString);
			}

			//Else, if the user wanted the Augustus cipher,
			else if (strcmp(cipherCmdString, "au") == 0) {

				//and if the user wanted the default Augustus key,
				if(((int) strlen(cipherKeyString)) == 0) {

					//set "cipherKeyString" as the default key.
					cipherKeyString = "12";
				}

				//Otherwise, use "cipherKeyString" as it is.
				printf("\nAugustus encryption with text %s and key %s! (COMING SOON)\n", cipherTextString, cipherKeyString);
			}

			//Else, if the user wanted the AES cipher,
			else if(strcmp(cipherCmdString, "ae") == 0) {

				//Encrypt the string using the AES cipher.
				printf("\nAES encryption with text %s and key %s! (COMING SOON)\n", cipherTextString, cipherKeyString);
			}
			else {
				printf("\nNot a valid command!\n\n");
			}

			//Clear all variables.
			cipherCmdString[0] = '\0';
			cipherTextString[0] = '\0';
			cipherKeyString[0] = '\0';

			printf("\nLASTLY:\n");
			printf("\ncipherCmdString is !!%s!! with length %d\n", cipherCmdString, (int) strlen(cipherCmdString));
			printf("\ncipherTextString is !!%s!! with length %d\n", cipherTextString, (int) strlen(cipherTextString));
			printf("\ncipherKeyString is !!%s!! with length %d\n", cipherKeyString, (int) strlen(cipherKeyString));



			//Ask for the user to input a cipher again.
			printf("\nEnter command FOR THE SECOND TIME - q(uit), c(aesar), au(gustus), ae(s): ");
			fgets(cipherCmdArray, 3, stdin);
			cipherCmdArray[strcspn(cipherCmdArray, "\n")] = '\0';
			cipherCmdString = cipherCmdArray;
		}
	}

	//Else, if the user types in "default" as the main argument,
	else if(strcmp(userCommand, "default") == 0) {

		//run the "default_tests()" method.
		default_tests();
	}


	//Else,
	//FIND OUT WHY "ciphers.txt" HAS 151 LINES, BUT "numLines"==154????
	else {

		//assume the user entered a filename and run the input file processor code.
		printf("\n\nRun input file!!\n\n");

		//Create a FILE pointer "inFile" to hold the input file.
		FILE *inFile = fopen(userCommand, "r");

		//Create a char array "fileLine" to hold each line of text in the input file.
		char fileLine[100];

		//If the file doesn't exist,
		if(inFile == NULL) {

			//Print as such.
			printf("\n\nFile doesn't exist.\n\n");
		}

		//Otherwise,
		else {
			int numLines = 0;

			//Iterate through each line of the file.
			while(fgets(fileLine, 100, inFile) != NULL) {
				numLines++;
				printf("%s", fileLine);
			}
			printf("\nThe number of file lines is %d\n", numLines);
			fclose(inFile);

		}


		//Sample input file (pattern of 4 lines):
		//Line 2: "encrypt/decrypt caesar/augustus/aes"
		//Line 3: key --> "[number]/default/[16 hex digits]"
		//Line 4: "[stringToEncrypt/Decrypt OR [16 hdex digits]"
		//IGNORE ANY LINE WITH "#" !!!
	}
	return 0;
}

