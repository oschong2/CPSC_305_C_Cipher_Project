#ifndef _AUGUSTUS_H
#define _AUGUSTUS_H

char *augustus_encrypt(char *plain, char *key);
char *augustus_decrypt(char *cipher, char *key);
char Augustus_encrypt_char(char plain, int key);
char *Augustus_encrypt(char *plain, char *key);
#endif //_AUGUSTUS_H
