#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#include "caesar.h"
#include "augustus.h"
#include "default_tests.h"

//This is the main file for all of the code.

int main(int argc, char **argv) {

	//Create char * "userCommand" to hold the main argument passed in by the user.
	char *userCommand = argv[1];
	printf("\nuserCommand is %s\n", userCommand);

	//If the user does NOT enter a main argument,
	if (userCommand == NULL) {

		//run the command processor.
		printf("\nRUN COMMAND PROCESSOR!!\n");


		//Print the default keys
		printf("Default Keys:\n");
		printf("Caesar: 1\n");
		printf("Augustus: 12 (coming soon!)\n");
		printf("AES: coming soon!\n\n");

	//Store user cipher, string, and key.

		//Create a char arrays "cipherCmdArray", "cipherTextArray", and "cipherKeyArray" to store the user's requested cipher, plain string, and key respectively.
		char cipherCmdArray[3];
		char cipherTextArray[100];
		char cipherKeyArray[100];

		//Create char pointers "cipherCmdString", "cipherTextString", and "cipherKeyArray" to store the user's requested cipher, plain string, and key respectively.
		char *cipherCmdString;
		char *cipherTextString;
		char *cipherKeyString;

		//Prompt the user to enter the cipher they want and store it in "cipherCmdString".
		printf("Enter command - q(uit), c(aesar), au(gustus), ae(s): ");
		fgets(cipherCmdArray, 3, stdin);
		cipherCmdArray[strcspn(cipherCmdArray, "\n")] = '\0';
		cipherCmdString = cipherCmdArray;

		while(strcmp(cipherCmdString, "q") != 0) {

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

				//If the user wanted the default Caesar key,
				if(cipherKeyString == NULL) {

					//set "cipherKeyString" as the default key.
					cipherKeyString = "1";
				}

				//Encrypt the string using the Caesar cipher.
				printf("\nCaesar encryption with text %s and key %s!\n", cipherTextString, cipherKeyString);
				char *encString = caesar_encrypt(cipherTextString, cipherKeyString);

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

				//Output the first 16 characters of the cipher string.

			}
			else if (strcmp(cipherCmdString, "au") == 0) {

				//Encrypt the string using the Augustus cipher.
				printf("\nAugustus encryption with text %s and key %s! (COMING SOON)\n", cipherTextString, cipherKeyString);
			}
			else if(strcmp(cipherCmdString, "ae") == 0) {

				//Encrypt the string using the AES cipher.
				printf("\nAES encryption with text %s and key %s! (COMING SOON)\n", cipherTextString, cipherKeyString);
			}
			else {
				printf("\nNot a valid command!\n\n");
			}

			//Ask for the user to input a cipher again.
			printf("\nEnter command - q(uit), c(aesar), au(gustus), ae(s): ");
			fgets(cipherCmdArray, 3, stdin);
			cipherCmdArray[strcspn(cipherCmdArray, "\n")] = '\0';
			cipherCmdString = cipherCmdArray;

			//Reset "cipherTextString" and "cipherKeyString".
			cipherTextString = "WHY";
			cipherKeyString = "WHY";
		}
	}

	//Else, if the user types in "default" as the main argument,
	else if(strcmp(userCommand, "default") == 0) {

		//run the "default_tests()" method.
		printf("\n\nRUN DEFAULT TESTS!!\n\n");
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

