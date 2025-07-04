#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

//Them gia tri vao list
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//In
void printNode(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    //Them 5 phan tu va in toan bo phan tu do
    //Them gia tri
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);
    //Noi cac phan tu
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    //In
    printNode(head);
    return 0;
}
