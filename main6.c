#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

main() // 0-9 (48 - 57) A-Z (65 - 90)
{
	char mas[100];
	FILE* file;
	if ((file = fopen("Train.txt", "r")) != NULL)
	{
		while (fscanf(file, "%s", &mas) != EOF)
		{
			int i, j;
			int x = 0;
			int max = 0;
			unsigned long long int k = 0;

			for (i = 0; mas[i] != '\0'; i++)
			{
				if (mas[i] > max)
				{
					max = mas[i];
				}
			}
			if (48 <= max && max <= 57)
			{
				j = max - 47;
			}
			else if (65 <= max && max <= 90)
			{
				j = max - 54;
			}
			for (i = (strlen(mas) - 1); i > -1; i--)
			{
				if (48 <= mas[i] && mas[i] <= 57)
				{
					k += (mas[i] - 48) * pow(j, x);
					x++;
				}
				else if (65 <= mas[i] && mas[i] <= 90)
				{
					k += (mas[i] - 55) * pow(j, x);
					x++;
				}
			}
			FILE* fileout;
			if ((fileout = fopen("Train2.txt", "a")) != NULL)
			{
				fprintf(fileout, "Number = %15s	", mas);
				fprintf(fileout, "Notation = %15d	", j);
				fprintf(fileout, "In decimal notation = %15llu\n", k);
			}
			else
				perror("Failed");
			fclose(fileout);
		}
	}
	else
		perror("Failed");
	fclose(file);
	return 0;
}
