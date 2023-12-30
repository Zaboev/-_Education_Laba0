#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int mas[10], max = 0, min = 200;
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++)
	{
		mas[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		if (mas[i] > max)
			max = mas[i];
		if (mas[i] < min)
			min = mas[i];
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", mas[i]);
	}
	printf("\n");
	printf("max = %d\n", max);
	printf("min = %d\n", min);
	for (int i = 0; i < 10; i++)
	{
		if (mas[i] == max)
			mas[i] = min;
		else if (mas[i] == min)
			mas[i] = max;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", mas[i]);
	}
	return 0;
}