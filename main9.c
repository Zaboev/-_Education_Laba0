#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int calc(int x, int y)
{
	char res[100];
	int sch = 0;
	printf("in %d notation is ", y);
	while (x >= y)
	{
		if (x % y < 10)
			res[sch] = (x % y) + 48;
		else
			res[sch] = (x % y) + 55;
		x = x / y;
		sch++;
	}
	if (x < 10)
		res[sch] = x + 48;
	else
		res[sch] = x + 55;
	res[sch + 1] = '\0';
	for (int i = sch; i > -1; i--)
		printf("%c", res[i]);
}

main() // 0-9 (48 - 57) A-Z (65 - 90) (83 116 111 112)
{
	int i, x, max = 0;
	char mas[100];
	char best[100];
	scanf("%d", &x);
	if (x < 2 || x > 36)
	{
		printf("Error when entering the number system");
		return 1;
	}
	while (mas[0] != 83 && mas[1] != 116 && mas[2] != 111 && mas[3] != 112)
	{
		scanf("%s", &mas);
		if (mas[0] == 83 && mas[1] == 116 && mas[2] == 111 && mas[3] == 112)
			break;
		int j = 0;
		int k = 0;
		for (i = (strlen(mas) - 1); i > -1; i--)
		{
			if (mas[i] >= 48 && mas[i] <= 57)
			{
				j += (mas[i] - 48) * pow(x, k);
				k++;
			}
			else if (mas[i] >= 65 && mas[i] <= 90)
			{
				j += (mas[i] - 55) * pow(x, k);
				k++;
			}
			else
			{
				printf("Incorrect number entered");
				return 2;
			}
		}
		if (max < j)
		{
			max = j;
			strcpy(best, mas);
		}
	}
	printf("Max number is %s\n", best);
	printf("From %d notation ", x);
	calc(max, 9);
	printf("\n");
	printf("From %d notation ", x);
	calc(max, 18);
	printf("\n");
	printf("From %d notation ", x);
	calc(max, 27);
	printf("\n");
	printf("From %d notation ", x);
	calc(max, 36);
	printf("\n");
	return 0;
}