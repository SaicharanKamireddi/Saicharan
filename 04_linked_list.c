#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev; // For doubly linked list
};

void menu() {
    printf("\n1. Singly Linked List \n2. Doubly Linked List \n3. Circular Linked List \n4. Exit");
    printf("\nChoose an option: ");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // For doubly linked list
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("\nThe list is empty.");
        return;
    }
    printf("\nThe elements in the list are: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void singlyLinkedList() {
    printf("\n*** Singly Linked List ***");
    struct Node* head = NULL;
    int data;
    char choice;
    do {
        printf("\nEnter node data: ");
        scanf("%d", &data);
        insertNode(&head, data);
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    displayList(head);
}

void doublyLinkedList() {
    printf("\n*** Doubly Linked List ***");
    struct Node* head = NULL;
    int data;
    char choice;
    do {
        printf("\nEnter node data: ");
        scanf("%d", &data);
        insertNode(&head, data);
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    displayList(head);
}

void circularLinkedList() {
    printf("\n*** Circular Linked List ***");
    struct Node* head = NULL;
    int data;
    char choice;
    do {
        printf("\nEnter node data: ");
        scanf("%d", &data);
        insertNode(&head, data);
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    // Make the list circular by connecting the last node to the head
    if (head != NULL) {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
    }
    displayList(head);
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                singlyLinkedList();
                break;
            case 2:
                doublyLinkedList();
                break;
            case 3:
                circularLinkedList();
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid Option");
        }
    } while (choice != 4);
    return 0;
}
/*Observations
This program helps to connect different lists and even ask for conformation if another list is to be inserted. limit to enter lists is unknown*/
