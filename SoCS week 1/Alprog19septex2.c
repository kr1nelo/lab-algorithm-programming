#include <stdio.h>
#include <string.h>

int main() {
    char N[101];  
    char M[11]; 
    int length, i, j = 0;

    printf("");
    scanf("%s", N);

    length = strlen(N);

    for (i = length - 2; i > 0; i--) {
        M[j++] = N[i];
    }

    M[j] = '\0';  

    printf("-%s-\n", M);

    return 0;
}
