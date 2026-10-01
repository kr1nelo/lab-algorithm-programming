#include <stdio.h>
#include <math.h>

int main() {
	int num1;
	int num2;
	int tambah;
	int kurang;
	int kali;
	double bagi;
	int sisa;
	
	printf("Input angka pertama : ");
	scanf("%d", &num1);
	printf("input angka kedua : ");
	scanf("%d", &num2);
	
	tambah = num1 + num2;
	kurang = num1 - num2;
	kali = num1 * num2;
	bagi = num1 / num2;
	sisa = num1 % num2;
	
	printf("hasil penambahan : %d\n", tambah);
	printf("hasil pengurangan : %d\n", kurang);
	printf("hasil perkalian : %d\n", kali);
	printf("hasil pembagian : %.2lf\n", bagi);
	printf("hasil sisa bagi : %d\n", sisa);
	
	return 0;
}
