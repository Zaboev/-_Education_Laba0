#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void free_memory(void* newFN, void* newWay)
{
	free(newFN);
	newFN = NULL;
	free(newWay);
	newWay = NULL;
}

int main(int arguments, char* arg[])
{
	bool is_here_way;
	char theWay[100];
	char filename[100];
	int x, y, z;
	char* newWay;
	char* newFN;
	char prefix[] = "out_";
	int count = 0;
	if (arguments < 2)
	{
		printf("Debugging error, missing necessary elements");
		return 5;
	}
	x = (strlen(arg[2]) - 1);
	while (arg[2][x] != '\\')
	{
		x--;
		if (x == (-1))
			break;
	}
	if (x == (-1))
		is_here_way = false;
	for (y = (x + 1); arg[2][y] != '\0'; y++)
	{
		filename[count] = arg[2][y];
		count++;
	}
	filename[count] = '\0';
	if (is_here_way)
	{
		for (z = 0; z < (x + 1); z++)
			theWay[z] = arg[2][z];
		theWay[z] = '\0';
		newFN = (char*)malloc(strlen(prefix) + strlen(filename) + 1);
		if (newFN == NULL)
		{
			printf("Process is failed");
			return NULL;
		}
		strcpy(newFN, prefix);
		strcat(newFN, filename);
		newWay = (char*)malloc(strlen(theWay) + strlen(newFN) + 1);
		if (newWay == NULL)
		{
			free(newFN);
			newFN = NULL;
			printf("Process is failed");
			return NULL;
		}
		strcpy(newWay, theWay);
		strcat(newWay, newFN);
	}
	else
	{
		newWay = (char*)malloc(strlen(prefix) + strlen(filename) + 1);
		if (newWay == NULL)
		{
			printf("Process is failed");
			return NULL;
		}
		strcpy(newWay, prefix);
		strcat(newWay, filename);
		newFN = (char*)malloc(sizeof(char));
	}

	if (strcmp(arg[1], "-fi") == 0)
	{
		FILE* file;
		if ((file = fopen(arg[2], "r")) != NULL)
		{
			FILE* fileout;
			if ((fileout = fopen(newWay, "a")) != NULL)
			{
				char filenames[100];
				char v;
				char m;
				int kol = 0;
				int kol2 = 0;
				while ((v = fgetc(file, "%c", filenames)) != EOF)
				{
					if (v == '\"' && kol % 2 == 0 && kol != 0)
					{
						filenames[kol2] = '\0';
						FILE* file2;
						if ((file2 = fopen(filenames, "r")) != NULL)
						{
							while ((m = fgetc(file2)) != EOF)
							{
								fprintf(fileout, "%c", m);
							}
						}
						else
						{
							free_memory(newFN, newWay);
							fclose(fileout);
							fclose(file);
							return 31;
						}
						fclose(file2);
						kol++;
						kol2 = 0;
						continue;
					}
					if (v == '\"')
					{
						kol++;
						continue;
					}
					if (kol % 2 != 0)
					{
						filenames[kol2] = v;
						kol2++;
					}
				}
				filenames[kol2] = '\0';
				FILE* file2;
				if ((file2 = fopen(filenames, "r")) != NULL)
				{
					while ((m = fgetc(file2)) != EOF)
					{
						fprintf(fileout, "%c", m);
					}
				}
				else
				{
					free_memory(newFN, newWay);
					fclose(fileout);
					fclose(file);
					return 3;
				}
				fclose(file2);
			}
			else
			{
				free_memory(newFN, newWay);
				fclose(file);
				return 2;
			}
			fclose(fileout);
		}
		else
		{
			free_memory(newFN, newWay);
			return 1;
		}
		fclose(file);
	}
	else if (strcmp(arg[1], "-cin") == 0)
	{
		int i;
		char a;
		printf("Number of files to process: ");
		scanf("%d", &i);
		for (int x = 0; x < i; x++)
		{
			FILE* file;
			char mas[1000];
			scanf("%s", mas);
			int len = strlen(mas);
			mas[len] = '\0';
			if ((file = fopen(mas, "r")) != NULL)
			{
				FILE* fileout;
				if ((fileout = fopen(newWay, "a")) != NULL)
				{
					while ((a = fgetc(file)) != EOF)
					{
						fprintf(fileout, "%c", a);
					}
				}
				else
				{
					free_memory(newFN, newWay);
					fclose(file);
					return 2;
				}
				fclose(fileout);
			}
			else
			{
				free_memory(newFN, newWay);
				return 2;
			}
			fclose(file);
		}
	}
	else if (strcmp(arg[1], "-arg") == 0)
	{
		for (int j = 2; j < (arguments); j++)
		{
			if (arg[j] != NULL)
			{
				char p;
				FILE* file;
				if ((file = fopen(arg[j], "r")) != NULL)
				{
					FILE* fileout;
					if ((fileout = fopen(newWay, "a")) != NULL)
					{
						while ((p = fgetc(file)) != EOF)
						{
							fprintf(fileout, "%c", p);
						}
					}
					else
					{
						free_memory(newFN, newWay);
						fclose(file);
						return 3;
					}
					fclose(fileout);
				}
				else
				{
					free_memory(newFN, newWay);
					return 2;
				}
				fclose(file);
			}
			else
			{
				free_memory(newFN, newWay);
				return 1;
			}
		}
	}
	else
		printf("Invalid command line argument");
	free_memory(newFN, newWay);
	return 0;
}