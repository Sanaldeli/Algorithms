#include<stdio.h>

int main () {
	
	//Day 1
	
	int i,j,k,str[200];
	double toplam;
	FILE*dosya=fopen("Input.txt","r+");
	
	for(i=0;i<200;i++){
		fscanf(dosya,"%d",&str[i]);
		//printf("%d,",str[i]);
	}
	
	fclose(dosya);
	
	for(i=0;i<200;i++){
		
		for(j=1;j<200;j++){
			
			for(k=2;k<200;k++){
				
				if((str[i]+str[j]+str[k])==2020){
					printf("%d + %d + %d = %d",str[i],str[j],str[k],str[i]*str[j]*str[k]);
					return 0;
					
				}
				
			}
			
		}
		
	}
	
	
	
	return 0;
}
