#include <stdio.h>

const int million = 1000000;

unsigned long collatz(unsigned long n)
{
	unsigned long seq = 0;
	while (n != 1)
	{
		if ((n % 2) == 0)
			n = n / 2;
		else
			n = n * 3 + 1;

		seq++;
	}
	return seq;
}

int main()
{
	// Which starting number, under one million, produces the longest chain?

	unsigned long i, temp;
	unsigned long max = 0, startNumber;
	unsigned long seq;

	for (i = 2; i <= million; ++i)
	{
		seq = collatz(i);

		if (seq >= max)
		{
			max = seq;
			startNumber = i;
		}
	}

	printf("%u produces the longest chain with %u terms.\n", startNumber, max);

	// Result is 837799

	return 0;
}
