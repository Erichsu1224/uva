#include <stdio.h>

int main(void)
{
	int row, column;
	while(scanf("%d %d", &row, &column) != 0)
	{
		int arr[1000][1000], counter = 0;;
		for(int i = 0; i < row; i++)
			for(int n = 0; n < column; n++)
				arr[i][n] = 0;

		for(int i = 0; i < row; i++)
		{
			for(int n = 0; n < column; n++)
			{
				if(arr[i][n] == 0)
				{
					arr[i][n] = 5;
					arr[i+2][n+1] = 1;
					arr[i+1][n+2] = 1;
					counter++;
				}
			}
		}
		for(int i = 0; i < row; i++)
			for(int n = 0; n < column; n++)
			{
				if(n == column - 1)
					printf("%3d\n", arr[i][n]);
				else
					printf("%3d ", arr[i][n]);
			}
		printf("%d knights may be placed on a %d row %d column board.\n", counter, row, column);
	}
	return 0;
}