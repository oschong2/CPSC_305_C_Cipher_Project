#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#include "caesar.h"
#include "augustus.h"
#include "default_tests.h"


int main() {

	//Create a char pointer "*sampleStr" as a string to encrypt.
	char *sampleStr = "Hello!";

	//Create a char pointer "*sampleKey" as an encryption key.
	char *sampleKey = "13";

	//Call "caesar_encrypt(char *plain, char *key)" to encrypt "sampleStr" using "sampleKey".
		//Store in char pointer "*encryptedStr"
	char *encryptedStr = augustus_encrypt(sampleStr, sampleKey);
	printf("\n\n\"%s\" was Augustus encrypted to \"%s\"\n\n", sampleStr, encryptedStr);

	//Now, decrypt "encryptedStr" using "caesar_decrypt(char *cipher, char *key)" to verify caesar works!
	char *decryptedStr = augustus_decrypt(encryptedStr, sampleKey);
	printf("\n\n\"%s\" was Augustus decrypted back to \"%s\"\n\n", encryptedStr, decryptedStr);

	printf("DEFAULT TESTS\n\n");

	default_tests();
	printf("\n\n");

	return 0;
}
