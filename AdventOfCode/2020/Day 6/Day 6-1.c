#include<stdio.h>

int main () {
	
	int i, j, blank=0, yes_c=0, alp[26];
	char yes[30];
	
	for(i=0;i<26;i++) {
		alp[i]=0;
	}
	
	FILE*dosya=fopen("Input.txt","r+");
	
	for(i=0;i<2228;i++) {		//Tüm satýrlarý tarama kýsmý
		fgets(yes,30,dosya);
		
		if (yes[0]>='a' && yes[0]<='z') {	//Satýrda harflerin olduðu kontrolü
			blank = 0;
			j=0;
			while (yes[j]!='\0') {			//Satýr sonuna kadar harfleri matriste yerleþtirme
				alp[(yes[j]-'a')]++;
				j++;
			}
		} else {							//Satýrda harf yoksa sistemin sýfýrlanmasý
			for(j=0; j<26; j++) {
				if (alp[j]!=0) {
					yes_c++;
				}
			}
			
			blank = 1;
			for(j=0;j<26;j++) {
				alp[j]=0;
			}
		}
	}
	
	fclose(dosya);
	
	printf("Sonuc: %d", yes_c);
	
	return 0;
}
