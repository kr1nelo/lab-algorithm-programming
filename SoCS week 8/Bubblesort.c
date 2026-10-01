#include <stdio.h>

void bubble_sort(int a[], int b){

    for(int i = 0; i < b - 1; i++){
        for(int j = 0; j < b - i - 1; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void hasil(int x[], int y){
    for(int i = 0; i < y; i++){
        printf("%d\n", x[i]);
    }
}

int main(){
    int data[] = {80, 40, 20, 76, 11, 35};
    int n = sizeof(data) / sizeof(data[0]);

    bubble_sort(data, n);
    hasil(data, n);
    
    return 0;
}
