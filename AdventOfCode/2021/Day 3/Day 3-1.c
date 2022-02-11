#include <stdio.h>
#define MAX 15

int binaryCalculator(char[]);

int main()
{

	// Answer: 3895776

	int i, j;
	int digitCounter[MAX] = {0};
	char input[MAX];
	char gammaRate[MAX];
	char epsilonRate[MAX];

	FILE *file = fopen("Input.txt", "r+");

	for (i = 0; i < 1000; ++i)
	{
		fscanf(file, "%s", &input);

		j = 0;
		while (input[j] != '\0')
		{
			if (input[j] == '1')
				digitCounter[j]++;
			j++;
		}
	}

	for (i = 0; i < 12; ++i)
	{
		if (digitCounter[i] >= 500)
		{
			gammaRate[i] = '1';
			epsilonRate[i] = '0';
		}
		else
		{
			gammaRate[i] = '0';
			epsilonRate[i] = '1';
		}
	}

	printf("%d", binaryCalculator(gammaRate) * binaryCalculator(epsilonRate));

	fclose(file);

	return 0;
}

int binaryCalculator(char number[])
{
	int i = 0, j;
	int multiplier = 1;
	int result = 0;

	while (number[i] != '\0')
		++i;

	for (j = i - 1; j >= 0; --j)
	{
		result += (number[j] == '1') ? multiplier : 0;
		multiplier *= 2;
	}

	return result;
}
