#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_SHOP_LENGTH 100

struct Product {
    char name[MAX_NAME_LENGTH];
    char shop[MAX_SHOP_LENGTH];
    float price;
};

void addRecord(FILE* pc) {
    struct Product product;

    printf("Введите название товара: ");
    scanf("%s", product.name);
    printf("Введите название магазина: ");
    scanf("%s", product.shop);
    printf("Введите цену товара: ");

    scanf("%f", &product.price);

    fwrite(&product, sizeof(struct Product), 1, pc);
}

void processFile(FILE* pc) {
    struct Product product;

    printf("Введите название магазина, товары которого вы хотите увидеть: ");
    char choice[MAX_SHOP_LENGTH];
    scanf("%s", choice);

    while (fread(&product, sizeof(struct Product), 1, pc) == 1) {
        if (strcmp(choice, product.shop) == 0) {
            printf("%s %s %.2f\n", product.name, product.shop, product.price);
        }
    }
}

int main() {
    char filename[] = "PriceList.dat";
    FILE* pc;
    int choice;

    do {
        printf("\nМеню:\n");
        printf("1. Добавить запись в файл\n");
        printf("2. Начать обработку созданного файла\n");
        printf("3. Выйти из программы\n");
        printf("Выберите действие: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pc = fopen(filename, "ab"); // Открываем файл для добавления бинарных данных в конец
                if (pc == NULL) {
                    printf("Ошибка открытия файла.\n");
                    return 1;
                }
                addRecord(pc);
                fclose(pc);
                break;
            case 2:
                pc = fopen(filename, "rb"); // Открываем файл для чтения бинарных данных
                if (pc == NULL) {
                    printf("Ошибка открытия файла.\n");
                    return 1;
                }
                
                processFile(pc);
                fclose(pc);
                break;
            case 3:
                printf("Программа завершена.\n");
                break;
            default:
                printf("Неверный выбор. Пожалуйста, выберите действие снова.\n");
        }
    } while (choice != 3);

    return 0;
}
