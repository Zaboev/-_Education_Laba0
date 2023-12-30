#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void free_memory(void** filename, void** TheWay, void** newfilename, void** newWay, bool trully)
{
	if (trully)
	{
		free(*filename);
		*filename = NULL;
		free(*newfilename);
		*newfilename = NULL;
		free(*TheWay);
		*TheWay = NULL;
		free(*newWay);
		*newWay = NULL;
	}
	else
	{
		free(*filename);
		*filename = NULL;
		free(*newWay);
		*newWay = NULL;
	}
}

main(int argkol, char* mason[])
{
	if (argkol < 3)
		return 5;
	//The start of the development a file with prefix
	int len = strlen(mason[2]);
	char* filename;
	char* TheWay;
	char* newWay;
	char* newfilename;
	int x = 0, y = 0, x1;
	bool is_here_way = false;
	for (int i = (len - 1); i >= 0; i--)
	{
		x++;
		if (mason[2][i] == '\\')
		{
			is_here_way = true;
			for (int j = 0; j < len - x; j++)
			{
				y++;
			}
			x--;
			y++;
			break;
		}
	}
	char prefix = "out_";
	x1 = x;
	if (is_here_way)
	{
		filename = (char*)malloc(x * sizeof(char) + 1);
		if (filename == NULL)
			return NULL;
		for (int i = (len - 1); i != (y - 1); i--)
		{
			filename[x - 1] = mason[2][i];
			x--;
		}
		filename[x1] = '\0';
		TheWay = (char*)malloc(y * sizeof(char) + 1);
		if (TheWay == NULL)
		{
			free(filename);
			filename = NULL;
			return NULL;
		}
		for (int i = 0; i <= (len - strlen(filename) - 1); i++)
		{
			TheWay[i] = mason[2][i];
		}
		TheWay[y] = '\0';
		newfilename = malloc(strlen(prefix) + strlen(filename) + 1);
		if (newfilename == NULL)
		{
			free(TheWay);
			free(filename);
			TheWay = NULL;
			filename = NULL;
			return NULL;
		}
		strcpy(newfilename, prefix);
		strcat(newfilename, filename);
		newWay = malloc(strlen(TheWay) + strlen(newfilename) + 1);
		if (newWay == NULL)
		{
			free(filename);
			free(TheWay);
			free(newfilename);
			TheWay = NULL;
			filename = NULL;
			newfilename = NULL;
			return NULL;
		}
		strcpy(newWay, TheWay);
		strcat(newWay, newfilename);
	}
	else
	{
		filename = (char*)malloc(x * sizeof(char) + 1);
		if (filename == NULL)
			return NULL;
		for (int i = (len - 1); i != (y - 1); i--)
		{
			filename[x - 1] = mason[2][i];
			x--;
		}
		filename[x1] = '\0';
		newWay = malloc(strlen(prefix) + strlen(filename) + 1);
		if (newWay == NULL)
		{
			free(filename);
			filename = NULL;
			return NULL;
		}
		strcpy(newWay, prefix);
		strcat(newWay, filename);
	}
	// The End of the development a file with prefix
	if (strcmp(mason[1], "/d") == 0 || strcmp(mason[1], "-d") == 0)
	{
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				FILE* fileout;
				if ((fileout = fopen(newWay, "w")) != NULL)
				{
					int i;
					while ((i = fgetc(file)) != EOF)
					{
						if (!isdigit(i))
							fprintf(fileout, "%c", i);
					}
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 4;
				}
				fclose(fileout);
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/nd") == 0 || strcmp(mason[1], "-nd") == 0)
	{
		if (argkol < 4)
			return 5;
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				if (mason[3] != NULL)
				{
					FILE* fileout;
					if ((fileout = fopen(mason[3], "w")) != NULL)
					{
						int i;
						while ((i = fgetc(file)) != EOF)
						{
							if (!isdigit(i))
							{
								fprintf(fileout, "%c", i);
							}
						}
					}
					else
					{
						fclose(file);
						free_memory(filename, TheWay, newfilename, newWay, is_here_way);
						return 4;
					}
					fclose(fileout);
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 3;
				}
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/i") == 0 || strcmp(mason[1], "-i") == 0)
	{
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				FILE* fileout;
				if ((fileout = fopen(newWay, "w")) != NULL)
				{
					char i;
					int count = 0;
					while ((i = fgetc(file)) != EOF)
					{
						if (isalpha(i))
						{
							count++;
						}
						if (i == '\n')
						{
							fprintf(fileout, "%d ", count);
							count = 0;
						}
					}
					fprintf(fileout, "%d", count);
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 4;
				}
				fclose(fileout);
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "-ni") == 0 || strcmp(mason[1], "/ni") == 0)
	{
		if (argkol < 4)
			return 5;
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				if (mason[3] != NULL)
				{
					FILE* fileout;
					if ((fileout = fopen(mason[3], "w")) != NULL)
					{
						char i;
						int count = 0;
						while ((i = fgetc(file)) != EOF)
						{
							if (isalpha(i))
							{
								count++;
							}
							if (i == '\n')
							{
								fprintf(fileout, "%d ", count);
								count = 0;
							}
						}
						fprintf(fileout, "%d", count);
					}
					else
					{
						fclose(file);
						free_memory(filename, TheWay, newfilename, newWay, is_here_way);
						return 4;
					}
					fclose(fileout);
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 3;
				}
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/s") == 0 || strcmp(mason[1], "-s") == 0)
	{
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				FILE* fileout;
				if ((fileout = fopen(newWay, "w")) != NULL)
				{
					char i;
					int count = 0;
					while ((i = fgetc(file)) != EOF)
					{
						if (!isalpha(i) && !isdigit(i) && !isspace(i))
							count++;
						if (i == '\n')
						{
							fprintf(fileout, "%d ", count);
							count = 0;
						}
					}
					fprintf(fileout, "%d", count);
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 4;
				}
				fclose(fileout);
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/ns") == 0 || strcmp(mason[1], "-ns") == 0)
	{
		if (argkol < 4)
			return 5;
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				if (mason[3] != NULL)
				{
					FILE* fileout;
					if ((fileout = fopen(mason[3], "w")) != NULL)
					{
						char i;
						int count = 0;
						while ((i = fgetc(file)) != EOF)
						{
							if (!isalpha(i) && !isdigit(i) && !isspace(i))
								count++;
							if (i == '\n')
							{
								fprintf(fileout, "%d ", count);
								count = 0;
							}
						}
						fprintf(fileout, "%d", count);
					}
					else
					{
						fclose(file);
						free_memory(filename, TheWay, newfilename, newWay, is_here_way);
						return 4;
					}
					fclose(fileout);
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 3;
				}
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/a") == 0 || strcmp(mason[1], "-a") == 0)
	{
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				FILE* fileout;
				if ((fileout = fopen(newWay, "w")) != NULL)
				{
					char i;
					while ((i = fgetc(file)) != EOF)
					{
						if (isdigit(i))
						{
							fprintf(fileout, "(%c)", i);
						}
						else
						{
							fprintf(fileout, "%d", i);
						}
					}
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 4;
				}
				fclose(fileout);
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/na") == 0 || strcmp(mason[1], "-na") == 0)
	{
		if (argkol < 4)
			return 5;
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				if (mason[3] != NULL)
				{
					FILE* fileout;
					if ((fileout = fopen(mason[3], "w")) != NULL)
					{
						char i;
						while ((i = fgetc(file)) != EOF)
						{
							if (isdigit(i))
								fprintf(fileout, "(%c)", i);
							else
								fprintf(fileout, "%d", i);
						}
					}
					else
					{
						fclose(file);
						free_memory(filename, TheWay, newfilename, newWay, is_here_way);
						return 4;
					}
					fclose(fileout);
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 3;
				}
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/f") == 0 || strcmp(mason[1], "-f") == 0)
	{
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				FILE* fileout;
				if ((fileout = fopen(newWay, "w")) != NULL)
				{
					char lexems[100];
					int i = 0;
					int j = 0;
					while (fscanf(file, "%s", lexems) != EOF)
					{
						i++;
						if (i % 2 == 0)
						{
							for (j = 0; j < strlen(lexems); j++)
							{
								lexems[j] = tolower(lexems[j]);
							}
						}
						if (i % 5 == 0)
						{
							for (j = 0; j < strlen(lexems); j++)
							{
								fprintf(fileout, "%d", lexems[j]);
							}
							fprintf(fileout, " ");
						}
						if (i % 5 != 0)
							fprintf(fileout, "%s ", lexems);
					}
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 4;
				}
				fclose(fileout);
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	else if (strcmp(mason[1], "/nf") == 0 || strcmp(mason[1], "-nf") == 0)
	{
		if (argkol < 4)
			return 5;
		if (mason[2] != NULL)
		{
			FILE* file;
			if ((file = fopen(mason[2], "r")) != NULL)
			{
				if (mason[3] != NULL)
				{
					FILE* fileout;
					if ((fileout = fopen(mason[3], "w")) != NULL)
					{
						char lexems[100];
						int i = 0;
						int j = 0;
						while (fscanf(file, "%s", lexems) != EOF)
						{
							i++;
							if (i % 2 == 0)
							{
								for (j = 0; j < strlen(lexems); j++)
								{
									lexems[j] = tolower(lexems[j]);
								}
							}
							if (i % 5 == 0)
							{
								for (j = 0; j < strlen(lexems); j++)
								{
									fprintf(fileout, "%d", lexems[j]);
								}
								fprintf(fileout, " ");
							}
							if (i % 5 != 0)
								fprintf(fileout, "%s ", lexems);
						}
					}
					else
					{
						fclose(file);
						free_memory(filename, TheWay, newfilename, newWay, is_here_way);
						return 4;
					}
					fclose(fileout);
				}
				else
				{
					fclose(file);
					free_memory(filename, TheWay, newfilename, newWay, is_here_way);
					return 3;
				}
			}
			else
			{
				free_memory(filename, TheWay, newfilename, newWay, is_here_way);
				return 2;
			}
			fclose(file);
		}
		else
		{
			free_memory(filename, TheWay, newfilename, newWay, is_here_way);
			return 1;
		}
	}
	free_memory(filename, TheWay, newfilename, newWay, is_here_way);
	return 0;
}