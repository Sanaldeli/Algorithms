#include<stdio.h>
#include<string.h>

int main () {
	
	int i,j,k,l,total=0,count=0,count2=0,count3=0,tmp,mul,byr,iyr,eyr,hgt,pid;
	char pass[200], eclList[10][10]={"amb","blu","brn","gry","grn","hzl","oth"};
	
	//byr,iyr,eyr,hgt,ecl,hcl,pid,cid
	
	FILE*dosya=fopen("Input.txt","r+");
	
	for (i=0; i<1100; i++) {
		fgets(pass,200,dosya);
		
		if (pass[0]=='\n') {
			if (count==7) {
				total++;
			}
			count=0;
		}
		
		if (strstr(pass,"byr")!=0) {												//byr	1920-2020
			
			tmp = strstr(pass,"byr")-pass+4;
			byr = 0;
			mul = 1000;
			for (j=tmp; j<tmp+4; j++) {
				byr += (pass[j]-'0')*mul;
				mul/=10;
			}
			
			if (byr>=1920 && byr<=2020) {
				count++;
			}
			
		} else if (strstr(pass,"iyr")!=0) {											//iyr	2010-2020
		
			tmp = strstr(pass,"iyr")-pass+4;
			iyr = 0;
			mul = 1000;
			for (j=tmp; j<tmp+4; j++) {
				iyr += (pass[j]-'0')*mul;
				mul/=10;
			}
			
			if(iyr>=2010 && iyr<=2020){
				count++;
			}
			
		} else if (strstr(pass,"eyr")!=0) {											//eyr	2020-2030
			
			tmp = strstr(pass,"eyr")-pass+4;
			eyr = 0;
			mul = 1000;
			for (j=tmp; j<tmp+4; j++) {
				eyr += (pass[j]-'0')*mul;
				mul/=10;
			}
			
			if(eyr>=2020 && eyr<=2030){
				count++;
			}
			
		} else if (strstr(pass,"hgt")!=0) {											//hgt	cm(150-193) in(59-76)
			
			tmp = strstr(pass,"hgt")-pass+6;
			
			if(pass[tmp+1]=='c'&&pass[tmp+2]=='m'){
				hgt = (pass[tmp-2]-'0')*100 + (pass[tmp-1]-'0')*10 + (pass[tmp]-'0');
				if(hgt>=150 && hgt<=193){
					count++;
				}
			}else if(pass[tmp]=='i'&&pass[tmp+1]=='n'){
				hgt = (pass[tmp-2]-'0')*10 + (pass[tmp-1]-'0');
				if(hgt>=59 && hgt<=76){
					count++;
				}
			}
			
		} else if (strstr(pass,"ecl")!=0) {											//ecl	amb,blu,brn,gry,grn,hzl,oth
			
			for (j=0; j<7; j++) {
				if (strstr(pass,eclList[j])!=0) {
					count++;
				}
			}
			
		} else if (strstr(pass,"hcl:#")!=0) {											//hcl	#(0-9 or a-f)
			
			tmp = strstr(pass,"hcl:#")-pass+5;
			
			j = 0;
			while ((pass[tmp+j]>='0' && pass[tmp+j]<='9') || (pass[tmp+j]>='a' && pass[tmp+j]<='f'))
				j++;
				
			if (j==6)
				count++;
			
		} else if (strstr(pass,"pid")!=0) {											//pid	9-digit-number
			tmp = strstr(pass,"pid")-pass+4;
			
			j = 0;
			while (pass[tmp+j]>='0' && pass[tmp+j]<='9')
				j++;
			
			if (j==9)
				count++;
			
		}
	//	printf("%d ",count);
	}
	
	fclose(dosya);
	
	printf("| TOTAL: %d",total);
	
	return 0;
}
