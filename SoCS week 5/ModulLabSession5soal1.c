#include <stdio.h>

int a(int arr[], int b){
	
	int x = arr[0];
	
	for(int i = 0; i < b; i++){
		if(arr[i] > x){
			x = arr[i];
		}
	}
	
	return x;
}

int main(){
	int c;
	
	printf("input sebuah angka : ");
	scanf("%d", &c);
	
	int arr[c];
	
	for(int j = 0; j < c; j++)
	{
		printf("masukkan angka ke-%d : ", j + 1);
		scanf("%d", &arr[j]);
	}
	int z = a(arr, c);
	printf("angka terbesar adalah : %d\n", z);
	
	return 0;
}
