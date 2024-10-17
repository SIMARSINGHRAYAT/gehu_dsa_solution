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

void print(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void search(struct node* head, int key) {
    struct node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Key %d not found in the list.\n", key);
}

void modify(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;

    printf("Deleted node: %d\n", temp->data);
    free(temp);
}

int main() {
    struct node* head = NULL;
    int choice, data, val;

    while (1) {
        printf("\n1. Insert\n2. Print\n3. Search\n4. Modify (Delete)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                print(head);
                break;
            case 3:
                printf("Enter your key to search: ");
                scanf("%d", &val);
                search(head, val);
                break;
            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &val);
                modify(&head, val);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}