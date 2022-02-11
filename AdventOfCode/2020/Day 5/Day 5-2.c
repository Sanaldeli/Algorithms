#include<stdio.h>
#include<string.h>

//BFFFBBFRLR
//FBFFFBBLRL
//BFFFFFBRRR
//FBBBFFFLRR

int main(){
	
	int i=1,j,k,l,total=0,bin1,bin2,id_bf,id_lr,ids[1578],max=0,tmp,ida[789];
	char id[10];
	
	FILE*dosya=fopen("Input.txt","r");
		
	for(i=0;i<1578;i++){
	
		fgets(id,11,dosya);
		
		id_bf=0;
		id_lr=0;
		bin1=64;
		bin2=4;
	
		for(j=0;j<7;j++){
			if(id[j]=='B'){
				id_bf = id_bf + bin1;
			}
			bin1 = bin1 / 2;
		}
		
		for(k=7;k<10;k++){
			if(id[k]=='R'){
				id_lr = id_lr + bin2;
			}
			bin2 = bin2 / 2;
		}
		
		ids[i] = (id_bf * 8) + id_lr;
		
	}
	
	fclose(dosya);
	
	j=0;
	for(i=0;i<1579;i+=2){
		ida[j]=ids[i];
		j++;
	}
	
	for(i=0;i<789;i++){			//Bilet ID'lerini sýralama
		for(j=0;j<(789-i);j++){
			if(ida[j]>ida[j+1]){
				tmp=ida[j];
				ida[j]=ida[j+1];
				ida[j+1]=tmp;
			}
		}
	}
	
	for(i=1;i<789;i++){
		if(ida[i]!=ida[i+1]-1){
			printf("Your ID: %d",ida[i]+1);
		}
	}
	
	return 0;
}
