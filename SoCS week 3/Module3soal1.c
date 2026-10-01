//soal no 1
#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, y, z;
	
	printf("masukkan 3 angka acak :\n");
	scanf("%d %d %d", &x, &y, &z);
	
	if(x>z, x>y)
	{
		printf("The largest number is %d", x);
	}
	else if(y>x, y>z)
	{
		printf("The largest number is %d", y);
	}
	else if(z>x, z>y)
	{
		printf("The largest number is %d", z);
	}
	
	return 0;
}
