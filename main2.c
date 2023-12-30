#include <stdio.h>
#include <string.h>
#include <math.h>

int quadratic_equation(int a, int b, int c, double* x1, double* x2)
{
	double D, d;
	if (a == 0)
	{
		*x1 = (-c) / b;
		return 7;
	}
	D = b * b - 4 * a * c;
	d = sqrt(D);
	if (D == 0)
	{
		*x1 = (-b) / (2 * a);
		return 7;
	}
	else if (D < 0)
		return NULL;
	else
	{
		*x1 = (-b + d) / (2 * a);
		*x2 = (-b - d) / (2 * a);
		return 10;
	}
}

int triangle_sides(int a, int b, int c)
{
	int max = a;
	if (a > b)
	{
		if (a > c)
		{
			if (a * a == b * b + c * c)
				return 7;
			else return 10;
		}
		else if (c > a)
		{
			if (c * c == b * b + a * a)
				return 7;
			else return 10;
		}
		else return 10;
	}
	else if (b > a)
	{
		if (b > c)
		{
			if (b * b == a * a + c * c)
				return 7;
			else return 10;
		}
		else if (c > b)
		{
			if (c * c == b * b + a * a)
				return 7;
			else return 10;
		}
		else return 10;
	}
	else
	{
		if (a > c)
			return 10;
		else if (c > a)
		{
			if (c * c == b * b + a * a)
				return 7;
			else return 10;
		}
		else return 10;
	}
}

main(int argi, char* argm[])
{
	if (argi < 2)
		return 11;
	if ((strcmp(argm[1], "/q") == 0) || (strcmp(argm[1], "-q") == 0))
	{
		if (argi < 5)
			return 5;
		int a, b, c;
		double* x1, * x2;
		if (sscanf(argm[2], "%d", &a) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 1;
		}
		if (sscanf(argm[3], "%d", &b) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 2;
		}
		if (sscanf(argm[4], "%d", &c) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 3;
		}
		//*************************************
		printf("If ax^2 + bx + c = 0\n");
		switch (quadratic_equation(a, b, c, &x1, &x2))
		{
		case 7:
			printf("x1 = %0.3f\n", x1);
			break;
		case 10:
			printf("x1 = %0.3f\n", x1);
			printf("x2 = %0.3f\n", x2);
			break;
		case NULL:
			printf("No roots\n");
			break;
		}
		//*************************************
		printf("\nIf ax^2 + cx + b = 0\n");
		switch (quadratic_equation(a, c, b, &x1, &x2))
		{
		case 7:
			printf("x1 = %0.3f\n", x1);
			break;
		case 10:
			printf("x1 = %0.3f\n", x1);
			printf("x2 = %0.3f\n", x2);
			break;
		case NULL:
			printf("No roots\n");
			break;
		}
		//*************************************
		printf("\nIf bx^2 + ax + c = 0\n");
		switch (quadratic_equation(b, a, c, &x1, &x2))
		{
		case 7:
			printf("x1 = %0.3f\n", x1);
			break;
		case 10:
			printf("x1 = %0.3f\n", x1);
			printf("x2 = %0.3f\n", x2);
			break;
		case NULL:
			printf("No roots\n");
			break;
		}
		//*************************************
		printf("\nIf bx^2 + cx + a = 0\n");
		switch (quadratic_equation(b, c, a, &x1, &x2))
		{
		case 7:
			printf("x1 = %0.3f\n", x1);
			break;
		case 10:
			printf("x1 = %0.3f\n", x1);
			printf("x2 = %0.3f\n", x2);
			break;
		case NULL:
			printf("No roots\n");
			break;
		}
		//*************************************
		printf("\nIf cx^2 + ax + b = 0\n");
		switch (quadratic_equation(c, a, b, &x1, &x2))
		{
		case 7:
			printf("x1 = %0.3f\n", x1);
			break;
		case 10:
			printf("x1 = %0.3f\n", x1);
			printf("x2 = %0.3f\n", x2);
			break;
		case NULL:
			printf("No roots\n");
			break;
		}
		//*************************************
		printf("\nIf cx^2 + bx + a = 0\n");
		switch (quadratic_equation(c, b, a, &x1, &x2))
		{
		case 7:
			printf("x1 = %0.3f\n", x1);
			break;
		case 10:
			printf("x1 = %0.3f\n", x1);
			printf("x2 = %0.3f\n", x2);
			break;
		case NULL:
			printf("No roots\n");
			break;
		}
	}
	else if ((strcmp(argm[1], "/m") == 0) || (strcmp(argm[1], "-m") == 0))
	{
		if (argi < 4)
			return 5;
		int x, y;
		if (sscanf(argm[2], "%d", &x) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 1;
		}
		if (sscanf(argm[3], "%d", &y) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 2;
		}
		if (x == 0)
		{
			printf("Division by zero");
			return 4;
		}
		if ((y % x) == 0)
			printf("Multiple");
		else
			printf("Ne Multiple");
	}
	else if ((strcmp(argm[1], "/t") == 0) || (strcmp(argm[1], "-t") == 0))
	{
		if (argi < 5)
			return 5;
		int a, b, c;
		if (sscanf(argm[2], "%d", &a) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 1;
		}
		if (sscanf(argm[3], "%d", &b) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 2;
		}
		if (sscanf(argm[4], "%d", &c) != 1)
		{
			printf("Invalid numeric value entered in command line arguments");
			return 3;
		}
		if (a < 1 || b < 1 || c < 1)
		{
			printf("One of the values is less than or equal to zero");
			return 5;
		}
		switch (triangle_sides(a, b, c))
		{
		case 7:
			printf("The sides belong to a right triangle");
			break;
		case 10:
			printf("The sides do not belong to a right triangle");
			break;
		}
	}
	return 0;
}