#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

main(int kol, char* mas[])
{
	if (kol < 2)
	{
		printf("Not enough arguments on the command line");
		return 6;
	}
	if (mas[1] != NULL)
	{
		FILE* file;
		if ((file = fopen(mas[1], "r")) != NULL)
		{
			int i, j, k;
			char filename[100];
			char theWay[100];
			int count = 0;
			i = strlen(mas[1]) - 1;
			while (mas[1][i] != '\\')
			{
				i--;
			}
			for (j = i + 1; mas[1][j] != '\0'; j++)
			{
				filename[count] = mas[1][j];
				count++;
			}
			filename[count] = '\0';
			for (k = 0; k < i + 1; k++)
			{
				theWay[k] = mas[1][k];
			}
			theWay[k] = '\0';
			char prefix[] = "0";
			char* newFN = malloc(strlen(prefix) + strlen(filename) + 1);
			if (newFN == NULL)
			{
				fclose(file);
				return NULL;
			}
			strcpy(newFN, prefix);
			strcat(newFN, filename);
			char* newWay = malloc(strlen(theWay) + strlen(newFN) + 1);
			if (newWay == NULL)
			{
				fclose(file);
				free(newFN);
				newFN = NULL;
				return NULL;
			}
			strcpy(newWay, theWay);
			strcat(newWay, newFN);
			FILE* fileout;
			if ((fileout = fopen(newWay, "w")) != NULL)
			{
				char a[100];
				char b[100];
				char c[100];
				while (fscanf(file, "%s %s %s", a, b, c) == 3)
					fprintf(fileout, "%s %s %s\n", c, a, b);
			}
			else
			{
				fclose(file);
				free(newFN);
				free(newWay);
				newFN = NULL;
				newWay = NULL;
				return 3;
			}
			fclose(fileout);
			FILE* file1;
			FILE* file2;
			if ((file2 = fopen(newWay, "r")) == NULL)
			{
				fclose(file);
				free(newFN);
				free(newWay);
				newFN = NULL;
				newWay = NULL;
				return 5;
			}
			if ((file1 = fopen(mas[1], "w")) == NULL)
			{
				fclose(file);
				fclose(file2);
				free(newFN);
				free(newWay);
				newFN = NULL;
				newWay = NULL;
				return 4;
			}
			char c;
			while ((c = fgetc(file2)) != EOF)
				fprintf(file1, "%c", c);
			fclose(file1);
			fclose(file2);
			free(newFN);
			free(newWay);
			newFN = NULL;
			newWay = NULL;
		}
		else
			return 2;
		fclose(file);
	}
	else
		return 1;

	return 0;
}