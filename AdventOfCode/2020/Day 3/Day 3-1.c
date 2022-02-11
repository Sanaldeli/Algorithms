#include<stdio.h>
#include<string.h>

int main () {
	
	int i,j,k=0,count=0;
	char map[323][31];
	
	FILE*dosya=fopen("Input.txt","r+");
	
		for(i=0;i<323;i++){
			for(j=0;j<32;j++){
				
				fscanf(dosya,"%c",&map[i][j]);
				//printf("%c",map[i][j]);
				
			}
		}
	
	fclose(dosya);
	
	j=0;
	for(i=0;i<323;i++){
		
		if(map[i][j]=='#'){
			count++;
		}
		
		j += 1;
		j = j % 31;
		i++;
		
	}
	
	printf("%d",count);
	
	return 0;
}
