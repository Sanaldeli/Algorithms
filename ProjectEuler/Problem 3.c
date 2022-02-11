#include <stdio.h>

//What is the largest prime factor of the number 600851475143

int main()
{

	unsigned long long int x = 600851475143, tmp, pf = 2;

	//	printf("Please enter the number: "); scanf("%llu",&x);
	tmp = x;

	while (pf <= x)
	{

		if (x % pf == 0)
			x = x / pf;
		else
			pf++;
	}

	printf("> Largest prime factor of %llu is %llu", tmp, pf);

	//Result is 6857

	return 0;
}
