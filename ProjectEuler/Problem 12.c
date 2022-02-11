#include<stdio.h>

int main () {
	
	//What is the value of the first triangle number to have over five hundred divisors?
	
	int i, counter, flag=0, sum=12351;
	long long int number=76267425;	//12350th triangle number
	
	while (flag==0) {
		number+=sum;
		sum++;
		
		i=0;
		counter=0;
		while (i<=number) {
			i++;
			if (number%i==0) {
				counter++;
			}
		}
		
		if (counter>=500) {
			flag = 1;
		}
		
//		printf("Number %llu - Sum %d - Counter %d\n", number, sum, counter);
	}
	
	printf("The number you are looking for is %llu", number);
	
	//Result is 76576500
	
	return 0;
}
