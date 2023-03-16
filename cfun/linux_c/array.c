#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int i,j,k,array[10][10][10];
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			for(k = 0; k < 10; k++)
			{
				array[i][j][k] = k;
				printf("value: %d, address: 0x%p.\n", array[i][j][k], &array[i][j][k]);
			}
		}
	}
	return 0;
}
