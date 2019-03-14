#include <stdio.h>

int main(void)
{
	int time;
	scanf("%d", &time);
	while(time--)
	{
		int code[16], input, total = 0;
		for(int i = 0; i < 4; i++)
		{
			scanf("%d", &input);
			code[i * 4 + 3] = input % 10;
			input /= 10;
			code[i * 4 + 2] = input % 10;
			input /= 10;
			code[i * 4 + 1] = input % 10;
			input /= 10;
			code[i * 4] = input % 10;
		}
		for(int i = 0; i < 16; i = i + 2)
		{
			code[i] *= 2;
			total += code[i] % 10;
			code[i] /= 10;
			total += code[i] % 10;
		}
		for(int i = 1; i < 16; i += 2)
		{
			total += code[i];
		}

		if(total % 10 == 0)
			printf("Valid\n");
		else
			printf("Invalid\n");
	}

	return 0;
}