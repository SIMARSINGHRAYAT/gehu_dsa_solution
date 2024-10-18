#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {  
    struct node* newnode = (struct node*)malloc(sizeof(struct node));  
    if (newnode == NULL) {  
        printf("Memory Allocation failed.\n");  
        exit(1);  
    }  
    newnode->data = data;  
    newnode->next = NULL;  
    return newnode;  
}  

void insert(struct node** head, int data) {  
    struct node* newnode = create(data);  
    if (*head == NULL) {  
        *head = newnode;  
    } else {  
        struct node* temp = *head;  
        while (temp->next != NULL) {  
            temp = temp->next;  
        }  
        temp->next = newnode;  
    }  
}

void verify(struct node** head, int k) {
    struct node* temp = *head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data % k == 0) {
            printf("Node multiple of k: %d\n", temp->data);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No node found that is a multiple of k.\n");
    }
}

void display(struct node* head) {
    struct node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The list contains: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, k;

    while (1) {
        printf("\n1. Insert a node");
        printf("\n2. Verify multiples of k");
        printf("\n3. Display the list");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                verify(&head, k);
                break;
            case 3:
                display(head);
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