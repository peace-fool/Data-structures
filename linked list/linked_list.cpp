#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void push(Node** head_ref, int new_value){
    Node* new_node = new Node;
    new_node->data = new_value;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAt(Node* prev_node,int new_value){
    if(prev_node == NULL){
        cout << "previous node is null node";
        return;
    }
    Node* new_node = new Node;
    new_node->data = new_value;
    new_node->next = prev_node->next;
    prev_node->next =new_node;
}

void printList(Node* node){
    while(node != NULL){
        cout<< ' ' << node->data;
        node = node->next;
    }
}

void append(Node** head_ref, int new_value){
    Node* new_node = new Node;
    new_node->data = new_value;
    new_node->next = NULL;

    Node* last = *head_ref;
    //case1
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    //case2
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void deleteNode(Node** head_ref, int key){
    Node* temp = *head_ref , *prev;
    //case1- head node is not null and its data is the key
    if(temp != NULL && key == temp->data){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    //case2
    while(temp != NULL && key != temp->data){
        prev = temp;
        temp = temp->next;
    }
    //case3
    if(temp == NULL){
        cout << "There ain't any LL chief!";
        return;
    }
    prev->next = temp->next;
    free(temp); 
}

void deleteList(Node** head_ref){
    Node* current = *head_ref;
    Node* next;
    while(current != NULL){
       next = current->next;
       free(current);
       current = next;
    }
    *head_ref = NULL;
}

void nodeCount(Node** head_ref){
    Node* node = *head_ref;
    int i = 0;
    while(node != NULL){
        node = node->next;
        i++;
    }
    cout << "\n" <<i << "\n";
}

void reverse(Node** head_ref){
    Node* prev = NULL;
    Node* next = NULL;
    Node* current = *head_ref;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main(){

    Node* head = NULL;
    push(&head, 8);
    append(&head, 4);
    insertAt(head->next, 3);
    printList(head);
    nodeCount(&head);
    reverse(&head);
    printList(head);
}