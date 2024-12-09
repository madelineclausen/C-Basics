#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	int count[] = {0,0,0,0,0,0,0,0,0,0,0};
	int lower = 1;
	int upper = 6;
	for (int i=0; i<100; i++)
	{
		// roll dice
		int dice1 = (rand() % (upper - lower + 1)) + lower;
		int dice2 = (rand() % (upper - lower + 1)) + lower;
		int roll = dice1 + dice2;
		// add to histogram
		for (int x=0; x<=10; x++)
		{
			if (roll == x + 2)
			{
				count[x] = count[x] + 1;
			}
		}
	}
	// print histogram
	for (int j=0; j<=10; j++)
	{
		printf("%d: %2d  ", j+2, count[j]);
		if (j+2 < 10)
		{
			printf(" ");
		}
		for (int y=0; y<count[j]; y++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
