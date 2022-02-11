#include<stdio.h>
#define MAX 117

void resetOp (int op[]) {
	int tmp[MAX] = { 1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,9,19,1,19,5,23,2,23,13,27,
					1,10,27,31,2,31,6,35,1,5,35,39,1,39,10,43,2,9,43,47,1,47,5,51,
					2,51,9,55,1,13,55,59,1,13,59,63,1,6,63,67,2,13,67,71,1,10,71,
					75,2,13,75,79,1,5,79,83,2,83,9,87,2,87,13,91,1,91,5,95,2,9,95,
					99,1,99,5,103,1,2,103,107,1,10,107,0,99,2,14,0,0 };
	int i;
	for (i = 0; i < 117; i++) op[i] = tmp[i];
}

int operate (int op[]) {
	int i;
	for (i = 0; i < 117 ; i += 4) {
		switch (op[i])
		{
			case 1:
				op[op[i + 3]] = op[op[i + 1]] + op[op[i + 2]];
				break;
			case 2:
				op[op[i + 3]] = op[op[i + 1]] * op[op[i + 2]];
				break;
			case 99:
				break;
		}
	}
	return op[0];
}

int main () {
	
	//Day 2-1	Answer: 3895705
	//Day 2-2	Answer: 6417
	
	int n, v, res1, res2;
	int op[MAX];
	resetOp(op);
	
	printf("Part 1: %d", operate(op));
	
	for (n = 0; n < 100; n++) {
		for (v = 0; v < 100; v++) {
			resetOp(op);
			
			op[1] = n;
			op[2] = v;
			
			if (operate(op) == 19690720) {
				printf("\nPart 2: %d", 100 * n + v);
				return 0;
			}
		}
	}
	
	return 0;
}
