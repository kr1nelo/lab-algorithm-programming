#include <stdio.h>

int main(){
	int x;
	int y;
	int KPK1;
	int KPK2;
	int KPK3;
	int hasil;
	
	scanf("%d %d", &x, &y);
	
	KPK1 = y;
	KPK2 = y;
	KPK3 = KPK1 * KPK2;
	
	printf("%d\n", KPK3);
	return 0;
}
