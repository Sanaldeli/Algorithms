#include<stdio.h>
#include<string.h>

int main () {
	
	int i=0,j,total=0,count=0;
	char pass[200];
	char req[10][10]={"byr:","iyr:","eyr:","hgt:","hcl:","ecl:","pid:"};
	
	FILE*dosya=fopen("Input.txt","r+");
	
	for (;i<1101;i++) {
		fgets(pass,200,dosya);
		
		if (pass[0]=='\n') {
			if (count==7) {
				total++;
			}
			count=0;
		}
		
		for (j=0;j<7;j++) {
			if (strstr(pass,req[j])!=0) {
				count++;
			}
		}
		
	}
	
	fclose(dosya);
	
	printf("%d",total);
	
	return 0;
}
