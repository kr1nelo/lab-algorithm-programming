#include <stdio.h>

int main(){
    double a;
    double b;

    do{
        printf("Enter sales in dollars (-1 to end): ");
        scanf("%lf", &a);
        
        if (a != -1)
		{
            b = 200 + (0.09 * a);
            printf("Salary is: $%.2f\n", b);
        }
    } while (a != -1);

    return 0;
}
