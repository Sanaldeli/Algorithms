#include<stdio.h>

int main () {
	
	//Day 1
	
	int i,j,str[200];
	double toplam;
	FILE*dosya=fopen("Input.txt","r+");
	
	for(i=0;i<200;i++){
		fscanf(dosya,"%d",&str[i]);
		//printf("%d,",str[i]);
	}
	
	fclose(dosya);
	
	for(i=0;i<200;i++){
		
		for(j=1;j<200;j++){
			
			if((str[i]+str[j])==2020){
				printf("%d. eleman %d ve %d. eleman %d toplami 2020 ve cevap= %d!!!!\n",i+1,str[i],j+1,str[j],str[i]*str[j]);
				return 0;
				
			}
			
		}
		
	}
	
	
	
	return 0;
}
