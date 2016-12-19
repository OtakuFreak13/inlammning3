//Björn Johansson
#ifndef CRYPTO_H
#define CRYPTO_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#pragma warning(disable: 4996)

char getDecrypt(char letter, int key);

char getEncrypt(char letter, int key);

char* encryptText(char *plainText, int arrLength, int key);

char* decryptText(char *cipherText, int arrLength, int key);

char* readFromFile(char fileName[]);

void writeToFile(char fileName[], char text[]);

int key();

int arrLength();

//char fileName[];


#endif // !CRYPTO_H
