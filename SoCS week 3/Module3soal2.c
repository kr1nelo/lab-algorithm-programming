//soal no 2
#include <stdio.h>

int main(){
	int n = 2;
	switch (n){
		case 1:
			printf("The number is 1\n"); //kesalahan pada kode ini adalah pada case 1 setelah printf("The number is 1\n"); tidak terdapat break; yang dimana jika kita meng-input angka 1 maka "The number is 2" akan ikut ter-print juga
			break; //break; ditambahkan pada case 1 ini berfungsi agar ketika pengguna meng-input angka 1 maka yang ter-print adalah "The number is 1" saja, karena program membaca adanya break; yang berarti jeda
		case 2:
			printf("The number is 2\n");
			break;
		default:
			printf("The number is not 1 or 2\n");
			break;
	}
}
