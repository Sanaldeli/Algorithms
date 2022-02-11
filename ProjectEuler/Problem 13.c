#include <stdio.h>

#define NUMBERS 100
#define DIGITS 50
#define ROWS 51

int digits[NUMBERS][DIGITS];
int resultingNumber[NUMBERS] = {0};

void output()
{
	int i;

	printf("First 10 digits of the sum is ");
	for (i = 0; i < 10; ++i)
		printf("%d", resultingNumber[i]);
	printf("\n");
}
void calculate()
{
	int i, j, k;
	int sum;

	for (i = DIGITS - 1; i >= 0; --i)
	{
		sum = 0;
		for (j = 0; j < NUMBERS; ++j)
			sum += digits[j][i];

		k = i + 2; // 2 is a magic number :)
		while (sum > 0)
		{
			if (resultingNumber[k] + sum % 10 > 9)
			{
				resultingNumber[k - 1]++;
				resultingNumber[k] -= 10;
			}
			resultingNumber[k] += sum % 10;
			sum /= 10;
			k--;
		}
	}
}

int main()
{
	// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

	int i, j;
	char input[ROWS];
	FILE *file;

	if ((file = fopen("Inputs\\Problem13.txt", "r")) == NULL)
	{
		printf("File not found!\n");
		return -1;
	}

	j = 0;
	while (!feof(file))
	{
		fscanf(file, "%[^\n]\n", input);
		for (i = DIGITS - 2; i >= 0; --i)
			digits[j][i] = input[i] - '0';
		++j;
	}

	calculate();
	output();

	fclose(file);

	// Result is 5537376230

	return 0;
}
