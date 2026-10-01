#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	if(a + c > b){
		printf("Segitiga\n");
	} else{
		printf("Bukan Segitiga\n");
	}

	return 0;
}
