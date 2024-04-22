#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class List{
private:
    Node* head;
    Node* tail;
    
public:
    List(){
         this->head = NULL;
         this->tail = NULL;
    }

void push(int data){
    Node* node = new Node(data);
    if (head == NULL){
        head = tail = node;
    }
    else if (head == tail){
        head->next = node;
        tail = node;
    }
    else if (head->next != NULL){
        tail->next = node;
        tail = node;
    }
    else cout << "ТЫ ЕБЛАН!" << endl;
}

void display(){
    Node* ptr;
    if (head == NULL) cout << "ТЫ ЕБЛАН!" << endl;
    else{
        ptr = head;
        for(head; ptr != NULL; ptr = ptr->next){
            cout << "Элемент: " << ptr->data << endl;
        }
    }
}
};

int main(){
    List lst;

    lst.push(43);
    lst.push(33);
    lst.push(54);
    lst.push(51);
    lst.display();
}