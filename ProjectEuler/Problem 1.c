#include <stdio.h>

//Find the sum of all the multiples of 3 or 5 below 1000

int main()
{

	int th = 0, fi = 0, sum = 0, i = 0;

	while (th < 997)
	{
		th += 3;
		sum += th;
	}

	while (fi < 995)
	{
		fi += 5;
		if ((fi % 15) != 0 && fi < 1000)
			sum += fi;
	}

	printf("Sum = %d", sum);

	//Result is 233168

	return 0;
}
