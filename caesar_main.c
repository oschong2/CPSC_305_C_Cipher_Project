#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#include "caesar.h"
#include "default_tests.h"


//This is the main file that test all of the "caesar.c" code

//Main currently tests:
//1. "caesar_encrypt_char(char plain, int key)"
//2. "caesar_encrypt(char *plain, char *key)"
//3. "caesar_decrypt_char(char cipher, int key)"
//4. "caesar_decrypt(char *cipher, char *key)"
//5. "convert_key(char *key)"

int main() {

	//Create a char pointer "*sampleStr" as a string to encrypt.
	char *sampleStr = "Owen";

	//Create a char pointer "*sampleKey" as an encryption key.
	char *sampleKey = "10";

	//Call "caesar_encrypt(char *plain, char *key)" to encrypt "sampleStr" using "sampleKey".
		//Store in char pointer "*encryptedStr"
	char *encryptedStr = caesar_encrypt(sampleStr, sampleKey);
	printf("\n\n\"%s\" was encrypted to \"%s\"\n\n", sampleStr, encryptedStr);

	//Now, decrypt "encryptedStr" using "caesar_decrypt(char *cipher, char *key)" to verify caesar works!
	char *decryptedStr = caesar_decrypt(encryptedStr, sampleKey);
	printf("\n\n\"%s\" was decrypted back to \"%s\"\n\n", encryptedStr, decryptedStr);

	printf("running default tests!!\n\n");

	default_tests();

	return 0;
}
