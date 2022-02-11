#include<stdio.h>

void toDigits (int number, int x[]) {
	int i, div = 10;
	for (i = 5; i >= 0; i--) {
		x[i] = (number % div) / (div / 10);
		div *= 10;
	}
}

int isAscending (int x[]) {
	int i;
	for (i = 1; i < 6; i++)
		if (x[i] < x[i - 1]) return 0;
	return 1;
}

int isAdjacent1 (int x[]) {
	int i;
	for (i = 1; i < 6; i++) if (x[i] == x[i - 1]) return 1;
	return 0;
}

int isAdjacent2 (int x[]) {
	int i, j;
	for (i = 5; i > 0; i = j) {
		j = i - 1;
		while (j >= 0 && x[j] == x[i]) j--;
		
		if (i - j == 2) return 1;
	}
	return 0;
}

int main () {
	
	//Day 4-1	Answer: 1864
	//Day 4-2	Answer: 1258
	
	int i, counter1 = 0, counter2 = 0;
	int x[6];
	
	for (i = 137683; i <= 596253; i++) {
		toDigits(i, x);
		if (isAscending(x)) {
			if (isAdjacent1(x)) counter1++;
			if (isAdjacent2(x)) counter2++;
		}
	}
	
	printf("Part 1: %d\nPart 2: %d", counter1, counter2);
	
	return 0;
}
