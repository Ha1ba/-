#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* nextel;
}Node;

struct Node* create_node(int data){
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Ошибка выделения памяти!");
        exit(1);
    }

    newNode->data = data;
    newNode->nextel = NULL;
    return newNode;
};

typedef struct List{
    Node* head;
    Node* tail;
}List;

void push(int data, Node** head, Node** tail){
    Node* node = create_node(data);
    if (*head == NULL){
        *head = node;
        *tail = node;
    }
    else{
        (*tail)->nextel = node;
        *tail = node;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    push(5, &head, &tail);
    printf("%d\n", head->data);
}