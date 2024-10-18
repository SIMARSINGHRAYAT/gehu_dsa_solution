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

void length(struct node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    printf("Length of the singly linked list is: %d\n", len);
}

struct node* reverse(struct node* head) {
    struct node* current = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void searchDelete(struct node** head, int key){
	if(*head == NULL) {
		exit(1);
	}
	struct node* temp = *head;
	while(temp != NULL){
		if(temp -> data == key){
			*head = temp -> next;
			printf("element deleted : %d.\n", temp -> data);
			free(temp);
			return;
		}
	}
	printf("Element does not exist.\n");
}

int main() {
    struct node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert a node\n");
        printf("2. Display the list\n");
        printf("3. Get length of the list\n");
        printf("4. Reverse the list\n");
        printf("5. Search and delete a node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                length(head);
                break;
            case 4:
                head = reverse(head);
                printf("List reversed.\n");
                break;
            case 5:
                printf("Enter element to search and delete: ");
                scanf("%d", &data);
                searchDelete(&head, data);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}