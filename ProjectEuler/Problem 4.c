#include <stdio.h>

int main()
{

	//Find the largest palindrome made from the product of two 3-digit numbers.

	int i = 999, j, palindrome = 0, mul, a, b, count;

	while (palindrome == 0 && i > 99)
	{
		j = i;
		while (j >= 900 && palindrome == 0)
		{
			mul = i * j;

			a = 100000;
			b = 1;
			count = 0;

			while ((mul / a) % 10 == (mul / b) % 10 && a > b)
			{
				count++;
				a /= 10;
				b *= 10;
			}

			if (count == 3)
			{
				printf("%d * %d = %d", i, j, mul);
				palindrome = 1;
			}

			j--;
		}
		i--;
	}

	//Result is 906609

	return 0;
}
