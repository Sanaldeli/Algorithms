#include<stdio.h>
#define latticePath(x, y) combination((x) + (y), (y))

double combination(int n, int k) {
	double comb = 1;
	
	for (; k > 0; --k, --n)
		comb *= (double)n / k;
	
	return comb;
}

int main () {
	// How many such routes are there through a 20×20 grid?
	
	printf("The number you are looking for is %.0lf\n", latticePath(20, 20));
	
	// Result is 137846528820
	
	return 0;
}
