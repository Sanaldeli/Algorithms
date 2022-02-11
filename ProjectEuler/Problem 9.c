#include<stdio.h>

int isTriplet (int a, int b, int c) {
	if ((a*a + b*b)==(c*c))
		return 1;
	else
		return 0;
}

int main () {
	
	//There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product a*b*c.
	
	int a,b,c,x,y,z,tmp,count,counter=0,flag=0,total,result;
	
	a = 1;
	while (a<998 && flag==0) {
		b=a+1;
		while (b<998 && flag==0) {
			c=1000-(a+b);
				if (isTriplet(a,b,c) && a+b+c==1000) {
					printf("a=%d | b=%d | c=%d\na+b+c = %d\n\na*b*c = %d",a,b,c,(a+b+c),(a*b*c));
					flag = 1;
				}
			b++;
			counter++;
		}
		a++;
	}
	
	//Result is 31875000
	
	return counter;
}
