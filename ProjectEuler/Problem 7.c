#include <stdio.h>

int main()
{

	//What is the 10.001st prime number?

	int i = 1, j = 2, k, tmp, prime = 3, flag = 1, counter;

	while (i < 10001 || flag == 1)
	{

		counter = 0;

		for (j = 2; j <= prime; j++)
		{
			if (prime % j == 0)
				counter++;
		}

		prime += 2;

		if (counter == 1)
			i++;
		if (i == 10001)
			flag = 0;
	}

	printf("10.001st prime number is %d", (prime - 2));

	//Result is 104743

	return 0;
}
