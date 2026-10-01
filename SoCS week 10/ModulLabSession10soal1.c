#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    int price;
    char category;
    
    union{
        struct{
            char meat;
            char packaging[11];
            char exp[11];
        }daging;
        
        struct{
            char produce;
            char received[11];
        }hasil_bumi;
        
        struct{
            char exp[11];
        }dairy;
        
        struct{
            int exp_month;
            int exp_year;
            int aisle_num;
            char aisle_side;
        }canned_goods;
        
        struct{
            char category;
            int aisle_num;
            char aisle_side;
        }non_foods;
        
    }data;
}Produk;

void cetak_produk(Produk p){
    printf("Name: %s\n", p.name);
    printf("Price: %d sen\n", p.price);
    printf("Category: %c\n", p.category);

    switch(p.category){
        case 'M':
            printf("Meat type: %c\n", p.data.daging.meat);
            printf("Date of packaging: %s\n", p.data.daging.packaging);
            printf("Expiration date: %s\n", p.data.daging.exp);
            break;
            
        case 'P':
            printf("Produce type: %c\n", p.data.hasil_bumi.produce);
            printf("Date received: %s\n", p.data.hasil_bumi.received);
            break;
            
        case 'D':
            printf("Expiration date: %s\n", p.data.dairy.exp);
            break;
            
        case 'C':
            printf("Expiration date: %02d/%04d\n", p.data.canned_goods.exp_month, p.data.canned_goods.exp_year);
            printf("Aisle number: %d\n", p.data.canned_goods.aisle_num);
            printf("Aisle side: %c\n", p.data.canned_goods.aisle_side);
            break;
            
        case 'N':
            printf("Nonfoods type: %c\n", p.data.non_foods.category);
            printf("Aisle number: %d\n", p.data.non_foods.aisle_num);
            printf("Aisle side: %c\n", p.data.non_foods.aisle_side);
            break;
            
        default:
            printf("Category undefined/not found\n");
    }
}

int main(){
    Produk corn = {"corn", 89, 'C', .data.canned_goods = {11, 2000, 12, 'B'}};

    cetak_produk(corn);

    return 0;
}
