#include <stdio.h>
#include <stdlib.h>

// Структура для элемента списка
struct Node {
    struct Node *next; // Поле для связи элементов в одном списке
    struct Node *link; // Поле для связи двух линейных списков
    int data;          // Информационное поле
};

// Глобальная переменная для хранения текущего элемента
struct Node *current;

// Функция для создания нового элемента списка
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->link = NULL;
    return newNode;
}

// Функция для добавления элемента в конец списка
void append(struct Node **headRef, int data) {
    struct Node *newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node *temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Функция для построения списочной структуры
void buildListStructure(struct Node **S) {
    int N = 0; // Используем для подсчета количества элементов
    int num;
    printf("Введите последовательность целых чисел (введите 0 для завершения ввода): \n");
    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;
        append(S, num);
        N++;
    }

    // Проверка на нечетность N и добавление NIL, если необходимо
    if (N % 2 != 0) {
        struct Node *temp = *S;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(0);
        N++;
    }

    // Деление списка на два линейных списка
    struct Node *temp = *S;
    struct Node *S1 = NULL;
    struct Node *S2 = NULL;
    for (int i = 0; i < N / 2; i++) {
        append(&S1, temp->data);
        temp = temp->next;
    }
    for (int i = N / 2; i < N; i++) {
        append(&S2, temp->data);
        temp = temp->next;
    }

    // Установка ссылок между списками
    temp = S1;
    while (temp->next != NULL) {
        temp->link = S2;
        temp = temp->next;
    }
    temp->link = S2;

    current = S1;
}

// Функция для вывода списка
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Функция для перемещения текущего элемента
void move(char direction) {
    if (direction == 'w' && current->link != NULL) {
        current = current->link;
    } else if (direction == 'a' && current->next != NULL) {
        current = current->next;
    } else if (direction == 's' && current->link != NULL) {
        current = current->link;
    } else if (direction == 'd' && current->next != NULL) {
        current = current->next;
    } else {
        printf("Невозможно выполнить это действие.\n");
    }
}

int main() {
    struct Node *S = NULL;
    buildListStructure(&S);
    printf("Исходный список S1: ");
    printList(S);
    if (S->link != NULL) {
        printf("Исходный список S2: ");
        printList(S->link);
    }
    printf("Текущий элемент: %d\n", current->data);
    printf("Для перемещения используйте клавиши w (вверх), a (влево), s (вниз) и d (вправо).\n");
    printf("Введите q для выхода.\n");
    char direction;
    while (1) {
        scanf(" %c", &direction);
        if (direction == 'q') {
            break;
        }
        move(direction);
        printf("Текущий элемент: %d\n", current->data);
    }
    return 0;
}
