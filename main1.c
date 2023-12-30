#include <stdio.h>
#include <string.h>
#include <math.h>

main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("No command line arguments found\n");
		return 1;
	}
	int x, y; //check for x
	if (sscanf(argv[2], "%d", &x) != 1)
	{
		printf("Invalid numeric value entered in command line arguments\n");
		return 4;
	}
	int ip = 0; // for case S/a
	int ip1 = 1; // for case f
	y = x;
	if (strcmp(argv[1], "-h") == 0 || (strcmp(argv[1], "/h") == 0))
	{
		if (x == 0)
			return 0;
		for (int i = 1; i <= 100; i++)
		{
			if (i % x == 0)
				printf("%d\n", i);
		}
	}
	else if (strcmp(argv[1], "-p") == 0 || (strcmp(argv[1], "/p") == 0))
	{
		if (x == 2 || x == 3)
		{
			printf("Number %d is s1mple\n", x);
			return 2;
		}
		for (int i = 3; i <= sqrt(x); i += 2)
		{
			if (x % i == 0)
			{
				printf("Number %d is composite\n", x);
				return 3;
			}
		}
		printf("Number %d is s1mple\n", x);
	}
	else if (strcmp(argv[1], "-s") == 0 || (strcmp(argv[1], "/s") == 0))
	{
		if (x > 9)
		{
			for (int i = 10; x > 9; i *= 10)
			{
				x /= 10;
				ip = i;
			}
			for (ip; ip != 1; ip /= 10)
			{
				printf("%d ", (y / ip));
				y = y % ip;
			}
			printf("%d\n", (y % 10));
		}
		else
			printf("%d", x);
	}
	else if (strcmp(argv[1], "-e") == 0 || (strcmp(argv[1], "/e") == 0))
	{
		for (int i = 1; i < 11; i++)
		{
			for (int j = 0; j < y + 1; j++)
			{
				printf("%d ", pow(i, j));
			}
			printf("\n");
		}
	}
	else if (strcmp(argv[1], "-a") == 0 || (strcmp(argv[1], "/a") == 0))
	{
		ip = (1 + x) / 2 * x;
		printf("%d\n", ip);
	}
	else if (strcmp(argv[1], "-f") == 0 || (strcmp(argv[1], "/f") == 0))
	{
		for (int i = 2; i < x + 1; i++)
			ip1 *= i;
		printf("%d\n", ip1);
	}
	else
		printf("No flags available\n");
	return 0;
}