#include <stdio.h>

void bubble_sort(int arr[], int size){
    int i;
	int j;
	
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int test;
    
    scanf("%d", &test);
    
    for(int idx = 1; idx <= test; idx++){
        int num;
        
        scanf("%d", &num);
        
        int players[1000];
        for(int i = 0; i < num; i++){
            scanf("%d", &players[i]);
        }
        
        int target;
        scanf("%d", &target);
        
        bubble_sort(players, num);
        
        int low = -1;
		int high = -1;
		
        for(int i = 0; i < num; i++){
            if(players[i] < target){
                low = players[i];
            }
            if(players[i] > target && high == -1){
                high = players[i];
                break;
            }
        }
        
        int found = 0;
        for(int i = 0; i < num; i++){
            if(players[i] == target){
                found = 1;
                break;
            }
        }
        
        if(found){
            if(high == -1){
                printf("CASE #%d: %d %d\n", idx, low, target);
            } else{
                printf("CASE #%d: %d %d\n", idx, target, high);
            }
        } else{
            printf("CASE #%d: -1 -1\n", idx);
        }
    }
    
    return 0;
}
