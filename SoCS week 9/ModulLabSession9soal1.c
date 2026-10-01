#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOOLS 100

typedef struct{
    int record_number;
    char tool_name[30];
    int quantity;
    double cost;
}Tool;

void open_file();
void list_tools();
void add_tools();
void delete_tools();
void update_tools();

int main(){
    int choice;
    open_file();

    do{
        printf("\nMenu:\n");
        printf("1. Daftar semua alat\n");
        printf("2. Tambah alat baru\n");
        printf("3. Hapus alat\n");
        printf("4. Perbarui alat\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: list_tools();
			break;
            case 2: add_tools();
			break;
            case 3: delete_tools();
			break;
            case 4: update_tools();
			break;
            case 5:
			break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while(choice != 5);

    return 0;
}

void open_file(){
    FILE *file = fopen("hardware.txt", "wb");
    Tool empty_tools = {0, "", 0, 0.0};

    for(int i = 0; i < MAX_TOOLS; i++){
        fwrite(&empty_tools, sizeof(Tool), 1, file);
    }

    Tool tools[] ={
        {3, "Electric sander", 7, 57.98}, {17, "Hammer", 76, 11.99}, {24, "Jig saw", 21, 11.00}, {39, "Lawn mower", 3, 79.50}, {56, "Power saw", 18, 99.99}, {68, "Screwdriver", 106, 6.99}, {77, "Sledge hammer", 11, 21.50}, {83, "Wrench", 34, 7.50}
    };

    for(int i = 0; i < 8; i++){
        fseek(file, (tools[i].record_number - 1) * sizeof(Tool), SEEK_SET);
        fwrite(&tools[i], sizeof(Tool), 1, file);
    }

    fclose(file);
}

void list_tools(){
    FILE *file = fopen("hardware.txt", "rb");
    Tool tool;

    printf("\nDaftar Alat:\n");
    printf("%-10s %-20s %-10s %-10s\n", "Record #", "Tool name", "Quantity", "Cost");
    while(fread(&tool, sizeof(Tool), 1, file)){
        if(tool.record_number != 0){
            printf("%-10d %-20s %-10d %-10.2f\n", tool.record_number, tool.tool_name, tool.quantity, tool.cost);
        }
    }
    fclose(file);
}

void add_tools(){
    FILE *file = fopen("hardware.txt", "rb+");
    Tool tool;

    printf("\nMasukkan nomor record # (1-100): ");
    scanf("%d", &tool.record_number);
    printf("Masukkan nama alat: ");
    scanf(" %[^\n]", tool.tool_name);
    printf("Masukkan jumlah: ");
    scanf("%d", &tool.quantity);
    printf("Masukkan biaya: ");
    scanf("%lf", &tool.cost);

    fseek(file, (tool.record_number - 1) * sizeof(Tool), SEEK_SET);
    fwrite(&tool, sizeof(Tool), 1, file);

    fclose(file);
}

void delete_tools(){
    FILE *file = fopen("hardware.txt", "rb+");
    Tool empty_tools = {0, "", 0, 0.0};
    int record_num;

    printf("\nMasukkan nomor record # yang akan dihapus: ");
    scanf("%d", &record_num);

    fseek(file, (record_num - 1) * sizeof(Tool), SEEK_SET);
    fwrite(&empty_tools, sizeof(Tool), 1, file);

    fclose(file);
}

void update_tools(){
    FILE *file = fopen("hardware.txt", "rb+");
    Tool tool;
    int record_num;

    printf("\nMasukkan nomor record # yang akan diperbarui: ");
    scanf("%d", &record_num);

    fseek(file, (record_num - 1) * sizeof(Tool), SEEK_SET);
    fread(&tool, sizeof(Tool), 1, file);

    if(tool.record_number == 0){
        printf("Record # tidak ditemukan.\n");
        fclose(file);
        return;
    }

    printf("Masukkan data baru:\n");
    printf("Nama alat (%s): ", tool.tool_name);
    scanf(" %[^\n]", tool.tool_name);
    printf("Jumlah (%d): ", tool.quantity);
    scanf("%d", &tool.quantity);
    printf("Biaya (%.2f): ", tool.cost);
    scanf("%lf", &tool.cost);

    fseek(file, (record_num - 1) * sizeof(Tool), SEEK_SET);
    fwrite(&tool, sizeof(Tool), 1, file);

    fclose(file);
}
