#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int** matrix_highlight(int rows, int columns)
{
	int** matrix = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (int*)malloc(columns * sizeof(int));
		if (matrix[i] == NULL)
		{
			for (int j = 0; j <= i; j++)
				free(matrix[j]);
			free(matrix);
			return NULL;
		}
	}
	return matrix;
}

double** matrix_highlight_double(int rows, int columns)
{
	double** matrix = (double**)malloc(rows * sizeof(double*));
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (double*)malloc(columns * sizeof(double));
		if (matrix[i] == NULL)
		{
			for (int j = 0; j <= i; j++)
				free(matrix[j]);
			free(matrix);
			return NULL;
		}
	}
	return matrix;
}

int generator(int* rows, int* columns, int*** generated_matrix)
{
	int** matrix;
	int generated_rows, generated_columns, coin_analogue;
	generated_rows = rand() % 10 + 1;
	generated_columns = rand() % 10 + 1;
	matrix = matrix_highlight(generated_rows, generated_columns); //Memory for arr
	if (matrix == NULL)
		return NULL;
	for (int i = 0; i < generated_rows; i++)
	{
		for (int j = 0; j < generated_columns; j++)
		{
			coin_analogue = rand() % 2;
			if (coin_analogue == 0)
				matrix[i][j] = rand() % 101; //interval(0 -> 100)
			else if (coin_analogue == 1)
				matrix[i][j] = (rand() % 100 + 1) * (-1); //interval(-100 -> -1)
		}
	}
	*rows = generated_rows;
	*columns = generated_columns;
	*generated_matrix = matrix;
	return 0;
}

int multiplication(int rows, int columns, int rows2, int columns2, int** result_matrix, int** result2_matrix, int*** multiplication_matrix)
{
	int** matrix_multiplication;
	int sum = 0;
	if (columns != rows2)
		return 1;
	matrix_multiplication = matrix_highlight(rows, columns2);
	if (matrix_multiplication == NULL)
		return NULL;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns2; j++)
		{
			for (int k = 0; k < columns; k++)
			{
				sum += result_matrix[i][k] * result2_matrix[k][j];
			}
			matrix_multiplication[i][j] = sum;
			sum = 0;
		}
	}
	*multiplication_matrix = matrix_multiplication;
	return 2;
}

double determinal(int rows, int columns, int** matrix, double* det)
{
	if (rows != columns)
		return 3;
	double** double_matrix;
	double coef, result_det = 1;
	double_matrix = matrix_highlight_double(rows, columns);
	if (double_matrix == NULL)
		return 0.0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			double_matrix[i][j] = (double)matrix[i][j];
	}
	for (int i = 0; i < (rows - 1); i++) //rows1
	{
		for (int j = i + 1; j < rows; j++) //next rows2 after rows1
		{
			coef = double_matrix[j][i] / double_matrix[i][i];
			for (int k = 0; k < columns; k++) //columns
			{
				double_matrix[j][k] -= double_matrix[i][k] * coef;
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		result_det *= double_matrix[i][i];
	}
	*det = result_det;
	return 4;
}

int main()
{
	srand((unsigned)time(0));
	int rows, columns, rows2, columns2;
	double det1, det2;
	int** result_matrix;
	int** result2_matrix;
	int** multiplication_matrix;

	switch (generator(&rows, &columns, &result_matrix))
	{
	case 'NULL':
		printf("Failed to allocate memory for the matrix\n");
		break;
	case 0:
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				printf("%4d ", result_matrix[i][j]);
			printf("\n");
		}
		break;
	}
	printf("\n");

	switch (generator(&rows2, &columns2, &result2_matrix))
	{
	case 'NULL':
		printf("Failed to allocate memory for the matrix\n");
		break;
	case 0:
		for (int i = 0; i < rows2; i++)
		{
			for (int j = 0; j < columns2; j++)
				printf("%4d ", result2_matrix[i][j]);
			printf("\n");
		}
		break;
	}
	printf("\n");

	switch (multiplication(rows, columns, rows2, columns2, result_matrix, result2_matrix, &multiplication_matrix))
	{
	case 'NULL':
		printf("Failed to allocate memory for the matrix\n");
		break;
	case 1:
		printf("Matrices cannot be multiplied\n");
		break;
	case 2:
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns2; j++)
				printf("%8d ", multiplication_matrix[i][j]);
			printf("\n");
		}
		break;
		free(multiplication_matrix);
	}
	printf("\n");

	if (determinal(rows, columns, result_matrix, &det1) == 3)
		printf("The matrix is not square\n");
	else if (determinal(rows, columns, result_matrix, &det1) == 0.0)
		printf("Failed to allocate memory for the matrix\n");
	else if (determinal(rows, columns, result_matrix, &det1) == 4)
		printf("%f\n", det1);

	if (determinal(rows2, columns2, result2_matrix, &det2) == 3)
		printf("The matrix is not square\n");
	else if (determinal(rows, columns, result_matrix, &det1) == 0.0)
		printf("Failed to allocate memory for the matrix\n");
	else if (determinal(rows, columns, result_matrix, &det1) == 4)
		printf("%f\n", det2);

	free(result_matrix);
	free(result2_matrix);

	return 5;
}