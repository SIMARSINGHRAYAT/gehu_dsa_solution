#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct node** head, int data) {
    struct node* newNode = create(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void duplicateDelete(struct node** head, int data) {
    struct node* current = *head;
    struct node* prev = NULL;
    
    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            printf("Duplicate Node Deleted: %d.\n", current->data);
            struct node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);

    printf("Original list:\n");
    printList(head);

    duplicateDelete(&head, 2);

    printf("List after removing duplicates:\n");
    printList(head);

    return 0;
}