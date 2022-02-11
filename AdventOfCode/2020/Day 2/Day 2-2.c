#include<stdio.h>

//1-13 r: gqdrspndrpsrjfjx
//5-16 j: jjjjkjjzjjjjjfjzjjj
//14-16 r: rrrnrrrrrcnrgxrr
//1-3 k: bkktwhgktv
//3-5 q: dxqqqzmqvs

int main () {
	
	int i,j,start,stop,count,total=0;
	char lett,array[50],pass[50];
	
	FILE*dosya=fopen("Input.txt","r+");
		
		for(i=0;i<1000;i++){
			fscanf(dosya,"%d-%d %c: ",&start,&stop,&lett);
			fgets(array,50,dosya);
			count=0;
			j=0;
			
			if((array[start-1]==lett || array[stop-1]==lett) && array[start-1]!=array[stop-1]){
				total++;
			}
			
			//printf("%d-%d %c: %s\n",start,stop,lett,array);
		}
	
	fclose(dosya);
	
	printf("total: %d",total);
	
	
	//printf("\n%s",array);
	
	return 0;
}
