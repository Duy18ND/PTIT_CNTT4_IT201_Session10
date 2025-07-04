#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteAll(Node** head, int target) {
    while (*head != NULL && (*head)->data == target) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == target) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int main() {
    Node* head = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(5);
    Node* node5 = createNode(2);
    Node* node6 = createNode(1);
    Node* node7 = createNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    printf("Danh sach ban dau:\n");
    printList(head);

    int target;
    printf("Kiem tra so trung lap va xoa ");
    scanf("%d", &target);

    deleteAll(&head, target);

    printf("Danh sach sau khi kiem tra %d:\n", target);
    printList(head);

    return 0;
}
