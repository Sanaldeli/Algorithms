#include <stdio.h>

int main()
{

	//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

	int i, temp, total1 = 0, total2 = 0, diff;

	for (i = 1; i <= 100; i++)
	{
		total1 += i * i;
		total2 += i;
	}

	printf("Result is: %d", (total2 * total2) - total1);

	//Result is 25164150

	return 0;
}
