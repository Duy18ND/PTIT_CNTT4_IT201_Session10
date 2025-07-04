#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Ham them vao dau
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addToEnd(Node** head, int value) {
    if (*head == NULL) {
        *head = createNode(value);
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(value);
}

// Ham in
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

int main() {
    Node* n1 = createNode(5);
    Node* n2 = createNode(4);
    Node* n3 = createNode(3);
    Node* n4 = createNode(2);
    Node* n5 = createNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    //In mang ban dau
    printList(n1);
    printf("\n");

    int value;
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &value);

    if (value < 0) {
        printf("So nguyen duong khong hop le!");
        return 0;
    }

    addToEnd(&n1, value);

    // In khi them vao cuoi
    printList(n1);

    return 0;
}
