//Björn Johansson
#include"crypto.h"
#include <crtdbg.h>
char* encryptText(char *plainText, int arrLength, int key)
{
	char *encrypted = calloc(arrLength+1, sizeof(char));
	char letter = 0;
	key;
	if (key < 1 || key > 25)
	{
		encrypted = "-1";
	}
	else 
	{
		for (int i = 0; i < arrLength; i++)
		{
			letter = plainText[i];
			if ((int)'a' <= (int)letter && (int)letter <= (int)'z')
			{
				letter = toupper(letter);
			}
			if ((int)'A' <= (int)letter && (int)'Z' >= (int)letter)
			{
				encrypted[i] = getEncrypt(letter, key);
				
			}
			else
			{
				encrypted[i]=letter;
			}
		}
	
	}

	return encrypted;
}

char* decryptText(char *cipherText, int arrLength, int key)
{
	char *decrypted = calloc(arrLength + 1, sizeof(char));
	char letter = 0;
	key;
	if (key < 1 || key > 25)
	{
		decrypted = "-1";
	}
	else
	{
		for (int i = 0; i < arrLength; i++)
		{
			letter = cipherText[i];
			if ((int)'a' <= (int)letter && (int)letter <= (int)'z')
			{
				letter = toupper(letter);
			}

			if ((int)'A' <= (int)letter && (int)'Z' >= (int)letter)
			{
				decrypted[i] = getDecrypt(letter, key);
			}
			else
			{
				decrypted[i] = letter;
			}
		}
	}

	return decrypted;
}


int arrLength(char *readFromFile)
{
	char *length = readFromFile;
	int counter = 0;
	while(length[counter])
	{
		counter++;
	}
	return counter;
}

char getEncrypt(char letter, int key)
{ 
	letter = toupper(letter);
	if ((int)'Z' < ((int)letter + key))
	{
		int letterDif = ((int)'Z') - ((int)letter);
		key = key - letterDif;
		letter = ((int)'A')-1;
	}
	
	char encryptChar = (char)((int)letter + key);
	return encryptChar;
}

char getDecrypt(char letter, int key) {
	key = -key;
	letter = toupper(letter);

	if ((int)'A' > ((int)letter + key)) {
		int letterDif = ((int)'A') - ((int)letter);
		key = key - letterDif;
		letter = (((int)'Z') + 1);
	}
	char decryptChar = (char)((int)letter + key);
	return decryptChar;
}


int key()
{
	printf("Input cryptaion key: ");
	int key1 = 0;
	scanf("%d", &key1);
	return key1;
}





char* readFromFile(char fileName[])
{
	char *buffer="-1";
	FILE *infile = fopen(fileName, "r");
	if (infile != NULL)
	{
		fseek(infile, 0, SEEK_END);
		long nrOfBytes = ftell(infile);
		fseek(infile, 0, SEEK_SET);

		buffer = calloc(nrOfBytes+1, sizeof(char));

		fread(buffer, nrOfBytes+1, 1, infile);
		
		printf("%s", buffer);
		
		fclose(infile);
	}
	else
	{
		printf("Couldn't find the file.");
	}
	
	
	
	return buffer;
}

void writeToFile(char fileName[], char text[])
{
	FILE *infile = fopen(fileName, "r");
	if (infile != NULL)
	{
		fclose(infile);
		FILE * file = fopen(fileName, "w");

		fputs(text, file);
		fclose(file);
	}
	
}