#include<stdio.h>

int main () {
	
	int i, j, blank=0, alp[26], counter=0, total=0;
	char yes[30];
	
	for(i=0;i<26;i++) {
		alp[i]=0;
	}
	
	FILE*dosya=fopen("Input.txt","r+");
	
	for(i=0;i<2228;i++) {		//T�m sat�rlar� tarama k�sm�
		fgets(yes,30,dosya);
		
		if (yes[0]>='a' && yes[0]<='z') {	//Sat�rda harflerin oldu�u kontrol�
			blank = 0;
			j=0;
			while (yes[j]!='\0') {			//Sat�r sonuna kadar harfleri matriste yerle�tirme
				alp[(yes[j]-'a')]++;
				j++;
			}
			counter++;
		} else {							//Sat�rda harf yoksa sistemin s�f�rlanmas�
			for(j=0; j<26; j++) {
				if (alp[j]==counter) {
					total++;
				}
			}
			
			blank = 1;
			for(j=0;j<26;j++) {
				alp[j]=0;
			}
			
			counter = 0;
		}
	}
	
	fclose(dosya);
	
	printf("Sonuc: %d", total);
	
	return 0;
}
