#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int word_counter = 0;
char* dictionary_english[1000];
char* dictionary_german[1000];

void readfile()
{
	char* result;
	char line[80];
	char english_word[80];
	char german_word[80];
	FILE* file;

	file = fopen("Vokabeln.txt", "rt");
	do
	{
		result = fgets(&(line[0]), 80, file);
		if (result != NULL)
		{
			sscanf(&line[0], "%s %s", &(english_word[0]), &(german_word[0]));
			dictionary_english[word_counter] = malloc(sizeof(char), strlen(&(english_word[0]) + 1));
			dictionary_german[word_counter] = malloc(sizeof(char), strlen(&(german_word[0]) + 1));
			strcpy(dictionary_english[word_counter], &(english_word[0]));
			strcpy(dictionary_german[word_counter], &(german_word[0]));
			word_counter++;
		}
	} while (result != NULL);
	fclose(file);
}


int main()
{
	char input[80];
	readfile();

	srand(time(NULL));   // Initialization, should only be called once.
	int index = rand() % word_counter;         // Returns a pseudo-random integer between 0 and RAND_MAX.

	for (; ; )
	{
		printf("What means '%s' ? ", dictionary_english[index]);
		scanf("%s", &(input[0]));

		if (strcmp("end", input) == 0)
			break;

		if (strcmp(dictionary_german[index], input) == 0)
		{
			printf(" correct !\n\n");
			index = rand() % word_counter;
		}
		else
			printf(" wrong !\n\n");
	}
}

