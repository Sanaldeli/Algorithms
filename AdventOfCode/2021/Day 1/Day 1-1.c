#include<stdio.h>

int main () {
	
	// Answer: 1559
	
	int i, sum, last;
	int count = 0;
	
	FILE *input = fopen("Input.txt", "r+");
	
	fscanf(input, "%d", &last);
	
	for (i = 0; i < 2000; ++i) {
		fscanf(input, "%d", &sum);
		
		if (last < sum) count++;
		last = sum;
	}
	
	printf("%d", count);
	
	fclose(input);
	
	return 0;
}
