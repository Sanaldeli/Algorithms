#include<stdio.h>

int main () {
	
	// Answer: 1599311480
	
	int i, amount;
	int depth, horizontal, aim;
	char direction[10];
	
	depth = horizontal = aim = 0;
	
	FILE *input = fopen("Input.txt", "r+");
	
	for (i = 0; i < 1000; ++i) {
		fscanf(input, "%c %d", &direction, &amount);
		
		switch (direction[0]) {
			case 'f':
				horizontal += amount;
				depth += aim * amount;
				break;
			
			case 'd':
				aim += amount;
				break;
			
			case 'u':
				aim -= amount;
				break;
		}
	}
	
	fclose(input);
	
	printf("%d", horizontal * depth);
	
	return 0;
}
