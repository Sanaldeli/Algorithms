#include <stdio.h>

int main()
{

	//Find the sum of all the primes below two million.

	int i = 3, j;
	unsigned long long int total = 2;

	for (; i < 2000000; i++)
	{
		j = 2;
		while (i % j != 0)
		{
			j++;
		}

		if (i == j)
		{
			total += j;
		}
	}

	printf("The sum of all the primes below two million is %llu", total);

	//Result is 142913828922

	return 0;
}
