#include <stdio.h>

int faktorial(int n){
    if(n <= 1)
        return 1;
    else
        return n * faktorial(n - 1);
}

int main(){
    int angka;

    scanf("%d", &angka);
    printf("%d\n", faktorial(angka));

    return 0;
}
