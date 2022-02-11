#include <stdio.h>

//By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

int main()
{

	int sum = 0, n1 = 1, n2 = 1, tmp;

	while (n1 < 4000000 && n2 < 4000000 && n1 + n2 < 4000000)
	{
		n1 = n1 + n2;
		n2 = n1 + n2;

		if (n1 % 2 == 0)
			sum += n1;
		else if (n2 % 2 == 0)
			sum += n2;
	}

	printf("Sum = %d", sum);

	//Result is 4613732

	return 0;
}
