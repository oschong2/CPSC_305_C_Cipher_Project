#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strings.h"
#include "caesar.h"
#include "augustus.h"
#include "aes_cbc.h"
#include "default_tests.h"

//This is the main file for all of the code.

/*
TO DO LIST:

	OVERALL:
		1. Figure out how AES encryption/decryption works!
		2. Work on "strings.h" for the default tests!

	CL Processor:
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

	//If the user does NOT enter a main argument,
	if (userCommand == NULL) {

		int loopCtr = 0;
		int textLen = 0;

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
		char *cipherCmdString = "";
		char *cipherTextString = "";
		char *cipherKeyString = "";

		//Create char pointers "encString" and "decString" to hold the values of encrypted and decrypted strings.
		char *encString;
		char *decString;

		//Prompt the user to enter the cipher they want and store it in "cipherCmdString".
		printf("Enter command - q(uit), c(aesar), au(gustus), ae(s): ");
		fgets(cipherCmdArray, 4, stdin);
		cipherCmdArray[strcspn(cipherCmdArray, "\n")] = '\0';
		cipherCmdString = cipherCmdArray;

		while(strcmp(cipherCmdString, "q") != 0) {

			//loopCtr++;
			//If the user wanted the Caesar cipher,
			if(strcmp(cipherCmdString, "c") == 0) {

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
				textLen = strlen(cipherTextString);
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

				//prompt the user to enter the string they want to encrypt and store it in "cipherTextString".
				if(loopCtr > 0) {
					fgets(cipherTextArray, 100, stdin);
				}
				printf("\n\nEnter string: "); //THIS DOESNT WORK FOR AUGUSTUS AND AES FOR SOME REASON?!?!?!?!!
				fgets(cipherTextArray, 100, stdin);
				cipherTextArray[strcspn(cipherTextArray, "\n")] = '\0';
				cipherTextString = cipherTextArray;

				//Prompt the user to enter the encryption key they want and store it in "cipherKeyString".
				printf("\n\nEnter key (Enter for default): ");
				fgets(cipherKeyArray, 100, stdin);
				cipherKeyArray[strcspn(cipherKeyArray, "\n")] = '\0';
				cipherKeyString = cipherKeyArray;

				//If the user wanted the default Augustus key,
				if(((int) strlen(cipherKeyString)) == 0) {

					//set "cipherKeyString" as the default key.
					cipherKeyString = "12";
				}

				//Store the encrypted "cipherTextString" in "encString", and the decrypted "encString" in "decString".
				encString = augustus_encrypt(cipherTextString, cipherKeyString);
				decString = augustus_decrypt(encString, cipherKeyString);

				//Output the first 16 characters of the plain string.
				textLen = strlen(cipherTextString);
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


				//Otherwise, use "cipherKeyString" as it is.
				//printf("\nAugustus encryption of %s with %s!!\n", cipherTextString, cipherKeyString);
			}

			//Else, if the user wanted the AES cipher,
			else if(strcmp(cipherCmdString, "ae") == 0) {

				//Prompt the user to enter the string they want to encrypt and store it in "cipherTextString".
				if(loopCtr > 0) {
					fgets(cipherTextArray, 100, stdin);
				}
				printf("\n\nEnter string: "); //THIS DOESNT WORK FOR AUGUSTUS AND AES FOR SOME REASON?!?!?!?!!
				fgets(cipherTextArray, 100, stdin);
				cipherTextArray[strcspn(cipherTextArray, "\n")] = '\0';
				cipherTextString = cipherTextArray;

				//Prompt the user to enter the encryption key they want and store it in "cipherKeyString".
				printf("\n\nEnter key (Enter for default): ");
				fgets(cipherKeyArray, 100, stdin);
				cipherKeyArray[strcspn(cipherKeyArray, "\n")] = '\0';
				cipherKeyString = cipherKeyArray;

				//If the user wanted the default Augustus key,
				if(((int) strlen(cipherKeyString)) == 0) {

					//set "cipherKeyString" as the default key.
					uint8_t key[] = { 0x2b, 0x72, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
				}


				uint8_t key[] = { 0x2b, 0x72, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

				textLen = strlen(cipherTextString);
				uint8_t in[textLen + 1];
				uint8_t iv[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

				memcpy(in, cipherTextString, textLen);

				char *inString = in;

				struct AES_ctx ctx;
				AES_init_ctx_iv(&ctx, key, iv);
				AES_CBC_encrypt_buffer(&ctx, in, 16);

				//Output the first 16 characters of the plain string.
				int textLen = strlen(cipherTextString);
				printf("\nPlain text string:\n");
				printf("len: 16\n");
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
				printf("len: 16\n");
				for(int i = 0; i < 16; i++) {
					if(i < textLen && isprint(in[i])) {
						printf("%.2x ", in[i]);
					}
					else {
						printf("_0 ");
					}
				}
				printf(" |  %s\n", inString);



				//Output the first 16 characters of the decrypted string.
				printf("\nDecrypted input:\n");
				printf("%s\n", cipherTextString);
				printf("len: %d\n", (int) strlen(cipherTextString));
				for(int i = 0; i < 16; i++) {
					if(i < textLen) {
						printf("%x ", cipherTextString[i]);
					}
					else {
						printf("_0 ");
					}
				}
				printf(" |  %s\n", cipherTextString);

				printf("\nlen: 16\n");
				for(int i = 0; i < 16; i++) {
					if(i < textLen) {
						printf("%x ", cipherTextString[i]);
					}
					else {
						printf("00 ");
					}
				}
				printf(" |  %s\n", cipherTextString);




				//Encrypt the string using the AES cipher.
			}

			//Otherwise, the user entered a non-valid command.
			else {
				printf("\nNot a valid command!\n\n");
			}

			//Reset variables.
			cipherCmdString = "";
			cipherTextString = "";
			cipherKeyString = "";
			memset(cipherCmdArray, 0, 4);
			memset(cipherTextArray, 0, 100);
			memset(cipherKeyArray, 0, 100);

			loopCtr++;

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
	else {

		//assume the user entered a filename and run the input file processor code.

		//Create a FILE pointer "inFile" to hold the input file.
		FILE *inFile = fopen(userCommand, "r");

		//Create a char array "fileLine" to hold each line of text in the input file.
		char fileLine[100];

		char *fileLineStr;
		char *encLine; //Holds the encryption/decryption status.
		char *cipherLine; //Holds the cipher to use.
		char *keyLine; //Holds the key to use.
		char *textLine; //Holds the text to encrypt/decrypt with "keyLine".

		//If the file doesn't exist,
		if(inFile == NULL) {

			//Print as such.
			printf("\n\nFile doesn't exist.\n\n");
		}

		//Otherwise,
		else {

			//Create a char array "fileLine" to hold each line of text in the input file.
			char fileLine[100];

			char *fileLineStr;
			char *encLine; //Holds the encryption/decryption status.
			char *cipherLine; //Holds the cipher to use.
			char *keyLine; //Holds the key to use.
			char *textLine; //Holds the text to encrypt/decrypt with "keyLine".

			int tripletCtr = 0; //Holds the number of the triplet we're on.
			int tripletLineCtr = 0; //Determines whether the line within the triplet is encryption/decryption and cipher, key, or text.
			int textLineLength = 0; //Stores the length of the string to encrypt/decrypt.

			//Iterate through each line of the file.
			while(fgets(fileLine, 100, inFile) != NULL) {
				fileLine[strcspn(fileLine, "\n")] = '\0';

				//If the line is comment,
				if(fileLine[0] == '#') {

					//and the line is a triplet comment,
					if((fileLine[1] == 'T' || fileLine[2] == 'T')) {

						tripletCtr++;

						//The next line contains the cipher and encryption status.
						printf("\n%s", fileLine);
						fgets(fileLine, 100, inFile);
						printf("\nfileLine is %s\n", fileLine);

						//Split "fileLine" into "encLine" and "cipherLine".
						char *encAndCipher = strtok(fileLine, " ");

						//Loop through "encAndCipher" to extract the enc and cipher.
						for(int i = 0; i < 2; i++) {

							//printf("encAndCipher is !!%s!!\n", encAndCipher);

							//If it's the first iteration of the loop,
							if(i == 0) {

								//Save the enc into "encLine".
								encLine = encAndCipher;
								encLine[strcspn(encLine, "\n")] = '\0';
								encAndCipher = strtok(NULL, " ");
							}

							//Else, save the cipher into "cipherLine".
							else
							{
							
								encAndCipher[strcspn(encAndCipher, "\n")] = '\0';
								cipherLine = encAndCipher;
								cipherLine[strcspn(cipherLine, "\n")] = '\0'; 
								//printf("cipherLine is !!%s!!\n", cipherLine);
							}
						}

						printf("encLine is !!%s!!, which compared to \"encrypt\" is %d\n", encLine, strcmp(encLine, "encrypt"));
						printf("YO WTFFFFF\n");
						printf("cipherLine is AAAAAAAAAAAAAAAAa!!egegheig%s\n", cipherLine);
						tripletLineCtr++;
					}	
					
					//Else, the line is just a random comment to ignore.
					else {

					}
				}

				//Else, if tripleLineCtr == 1, then the next line should be the key.
				else if(tripletLineCtr == 1) {
					keyLine = fileLine;
					keyLine[strcspn(keyLine, "\n")] = '\0';
					printf("keyLine is %s\n", keyLine);
					tripletLineCtr++;
				}

				//Else, if tripletLineCtr == 2, then the next line should be the text.
				else if(tripletLineCtr == 2) {
					textLine = fileLine;
					textLine[strcspn(textLine, "\n")] = '\0';
					textLineLength = strlen(textLine);
					printf("textLine is %s\n", textLine);

					//Reset tripletLineCtr to look for encs and ciphers again.
					tripletLineCtr = 0;
				}

				//Otherwise, just do nothing.
				else {

				}

				//Now, encrypt/decrypt the string using the key based on the Caesar/Augustus/AES cipher.

				//If the file requires Caesar
				if(strcmp(cipherLine, "caesar") == 0) {

					//and encryption,
					if(strcmp(encLine, "encrypt") == 0) {

						//Perform caesar encryption.
						printf("\nCaesar encryption of %s with key %s!!\n", textLine, keyLine);
						char *encCipher = caesar_encrypt(textLine, keyLine);

						//Print the caesar encryption.
						printf("Triplet: %d, Cipher: Caesar, Encrypt len: %d\n", tripletCtr, textLineLength);
						for(int i = 0; i < 16; i++) {
							if(i < textLineLength && isprint(encCipher[i])) {
								printf("%.2x ", encCipher[i]);
							}
							else {
								printf("_0 ");
							}
						}
						printf(" |  %s\n", encCipher);
					}

					//and decryption.
				}
				//printf("%s", fileLine);
			}
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

