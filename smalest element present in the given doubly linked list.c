#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void searchSmallerElements(struct Node* head, int data) {
    struct Node* temp = head;
    int found = 0;
    
    printf("Elements smaller than %d in the list are:\n", data);
    while (temp != NULL) {
        if (temp->data < data) {
            printf("%d ", temp->data);
            found = 1;
        }
        temp = temp->next;
    }
    
    if (!found) {
        printf("No elements smaller than %d found in the list.\n", data);
    } else {
        printf("\n");
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert at beginning");
        printf("\n2. Search for smaller elements");
        printf("\n3. Display the list");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                printf("Enter the value to search for smaller elements: ");
                scanf("%d", &data);
                searchSmallerElements(head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}