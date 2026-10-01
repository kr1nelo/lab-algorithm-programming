#include <stdio.h>

int main(){
	int a;
	
	scanf("%d", &a);
	
	for(int i = 1; i <= a; i++){
		printf("Case #%d: ", i);
		scanf("%d", &a);
	}
	
	return 0;
}
