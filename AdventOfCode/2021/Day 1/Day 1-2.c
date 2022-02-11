#include<stdio.h>

int main () {
	
	// Answer: 1600
	
	int i, j;
	int currSum = 0;
	int lastSum = 0;
	int count = 0;
	int inputs[3];
	
	FILE *input = fopen("Input.txt", "r+");
	
	for (i = 0; i < 3; ++i) {
		fscanf(input, "%d", &inputs[i]);
		lastSum += inputs[i];
	}
	for (i = 0; i < 2; ++i) inputs[i] = inputs[i + 1];
	fscanf(input, "%d", &inputs[2]);
	for (i = 0; i < 3; ++i) currSum += inputs[i];
	if (currSum > lastSum) count++;
	
	for (i = 0; i < 1996; ++i) {
		fscanf(input, "%d", &inputs[2]);		// Third input
		
		lastSum = currSum;
		currSum = 0;
		for (j = 0; j < 3; ++j) currSum += inputs[j];
		
		if (currSum > lastSum) count++;
		
		for (j = 0; j < 2; ++j) inputs[j] = inputs[j + 1];		// Shifting inputs for the next input
	}
	
	printf("%d", count);
	
	fclose(input);
	
	return 0;
}
