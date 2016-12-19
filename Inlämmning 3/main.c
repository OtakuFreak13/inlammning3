//Björn Johansson
#include<stdio.h>
#include"crypto.h"
#include <crtdbg.h>
#include<ctype.h>

void runner();

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char fileName[30];
	printf("Which file do you want to read? ");
	scanf("%s", &fileName);
	getchar();
	char *fromFile = readFromFile(fileName);
	//char *blabli = getDecrypt('A', 5);
	if (fromFile != "-1")
	{
		
		printf("What do you want to do with said file? \n Press '1' to encrypt it or '2' to decrypt it. ");
		int whatToDo = 0;
		scanf("%d", &whatToDo);
		getchar();
		if (whatToDo == 1)
		{
			int key2 = 0;
			printf("Input key. ");
			scanf("%d", &key2);
			getchar();
			int rLength = arrLength(fromFile);
			printf("%s\n", fromFile);
			char *textThatIsEncrypted = encryptText(fromFile, rLength, key2);
			if (textThatIsEncrypted != "-1") 
			{
				writeToFile(fileName, textThatIsEncrypted);
				printf("%s", textThatIsEncrypted);
			}
			else
			{
				printf("Error while choosing the key. Closing program...");
			}
			free(textThatIsEncrypted);
		}
		else if (whatToDo == 2)
		{
			
			//writeToFile(fileName, decryptText);
			int key3 = 0;
			printf("Input key. ");
			scanf("%d", &key3);
			getchar();
			int rrLength = arrLength(fromFile);
			printf("%s\n", fromFile);
			char *textThatIsDecrypted = decryptText(fromFile, rrLength, key3);
			if (textThatIsDecrypted != "-1")
			{
				writeToFile(fileName, textThatIsDecrypted);
				printf("%s", textThatIsDecrypted);
			}
			else
			{
				printf("Error while choosing the key. Closing program...");
			}
			free(textThatIsDecrypted);
		}
		else
		{
			printf("Nothing chosen. Closing program...");
		}
		//writeToFile("1.txt", "hester eter mat\nKollomango\nanfhr jhdfhr 2134.");

		//printf("%c", blabli);

		//char T = toupper('t');
		//printf("%c", T);


		free(fromFile);
	}

	getchar();
	getchar();
	return 0;
}

void runner()
{
	printf("Select a file name to wit");
}