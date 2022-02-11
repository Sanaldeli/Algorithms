#include<stdio.h>

int main () {
	
	// Answer: 2019945
	
	int i, amount;
	int depth, horizontal;
	char direction[10];
	
	depth = horizontal = 0;
	
	FILE *input = fopen("Input.txt", "r+");
	
	for (i = 0; i < 1000; ++i) {
		fscanf(input, "%s %d", &direction, &amount);
		
		switch (direction[0]) {
			case 'f':
				horizontal += amount;
				break;
			
			case 'd':
				depth += amount;
				break;
			
			case 'u':
				depth -= amount;
				break;
		}
	}
	
	fclose(input);
	
	printf("%d", horizontal * depth);
	
	return 0;
}
