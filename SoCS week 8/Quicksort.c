#include <stdio.h>

void quick_sort(int a[], int low, int high){
    if(low < high){
        int b = a[high];
        int i = (low - 1);
        
        for(int j = low; j < high; j++){
            if(a[j] < b){
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        
        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int z = i + 1;

        quick_sort(a, low, z - 1);
        quick_sort(a, z + 1, high);
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

    
    quick_sort(data, 0, n - 1);
    hasil(data, n);

    return 0;
}
