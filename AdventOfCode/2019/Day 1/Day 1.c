#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int fuel (int);

int main () {
	
	//Day 1-1	Answer: 3336439
	//Day 1-2	Answer: 5001791
	
	FILE*dosya = fopen("Input.txt", "r+");
	
	int i, j;
	char input[MAX];
	long long int totalFuel1 = 0, totalFuel2 = 0;
	
	for(i = 0; i < 100; i++) {
		j = 0;
		do {
			fscanf(dosya, "%c", &input[j]);
		} while (input[j] >= '0' && input[j++] <= '9');
		
		totalFuel1 += fuel1(atoi(input));
		totalFuel2 += fuel2(atoi(input));
	}
	
	printf("Part 1: %lld\nPart 2: %lld", totalFuel1, totalFuel2);
	
	fclose(dosya);
	
	return 0;
}

int fuel1 (int mass) {
	return (mass / 3) - 2;
}

int fuel2 (int mass) {
	int calc = (mass / 3) - 2;
	if (calc>=0) {
		return calc + fuel2(calc);
	}
	return 0;
}
