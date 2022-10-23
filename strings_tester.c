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

		//Create a char array "cipherCmdArray" to store the user's requested cipher.
		char cipherCmdArray[3];

		//LOOK AT PROJECT FILE (PAGE 24) FOR TURNING TERMINAL INPUT INTO STRINGS
		//Prompt the user to enter the cipher they want
		printf("Enter command - q(uit), c(aesar), au(gustus), ae(s): ");
		fgets(cipherCmdArray, 3, stdin);
		cipherCmdArray[strcspn(cipherCmdArray, "\n")] = '\0';
		
		//Create a char pointer "cipherCmdString" to point to "cipherCmdArray".
		char *cipherCmdString = cipherCmdArray;

		while(strcmp(cipherCmdString, "q") != 0) {

			//Check if "cipherCmdString" actually stored "cipherCmdArray".
			if(strcmp(cipherCmdString, "c") == 0) {
				printf("\nCaesar cipher!\n");
			}
			else if (strcmp(cipherCmdString, "au") == 0) {
				printf("\nAugustus cipher!\n");
			}
			else if(strcmp(cipherCmdString, "ae") == 0) {
				printf("\nAES cipher!\n");
			}
			else {
				printf("\nNot a valid command!\n\n");
			}

			printf("Enter command - q(uit), c(aesar), au(gustus), ae(s): ");
			fgets(cipherCmdArray, 3, stdin);
			cipherCmdArray[strcspn(cipherCmdArray, "\n")] = '\0';
		
			//Create a char pointer "cipherCmdString" to point to "cipherCmdArray".
			cipherCmdString = cipherCmdArray;
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

