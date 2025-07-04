#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

//Them cac phan tu
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//In
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("NULL");
}
int main(){
//Khoi tao mang linked List
    //Tao cac phan tu
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);

    //Noi lai thanh 1 danh sach lien ket
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    //In cac phan tu trong danh sach
    printList(head);
return 0;
}