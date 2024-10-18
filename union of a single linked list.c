#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  

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

void printList(struct node* head) {  
    struct node* temp = head;  
    while (temp != NULL) {  
        printf("%d -> ", temp->data);  
        temp = temp->next;  
    }  
    printf("NULL\n");  
}  

bool contains(struct node* head, int data) {  
    struct node* temp = head;  
    while (temp != NULL) {  
        if (temp->data == data) {  
            return true; 
        }  
        temp = temp->next;  
    }  
    return false; 
}  

struct node* unionList(struct node* list1, struct node* list2) {  
    struct node* result = NULL;  

    struct node* temp = list1;  
    while (temp != NULL) {  
        insert(&result, temp->data);  
        temp = temp->next;  
    }  

    temp = list2;  
    while (temp != NULL) {  
        if (!contains(result, temp->data)) {  
            insert(&result, temp->data);  
        }  
        temp = temp->next;  
    }  

    return result;  
}  
void freeList(struct node* head) {  
    struct node* temp;  
    while (head != NULL) {  
        temp = head;  
        head = head->next;  
        free(temp);  
    }  
}  

int main() {  
    struct node* list1 = NULL;  
    struct node* list2 = NULL;  
    struct node* unionResult = NULL;  
    int choice, data;  

    while (1) {  
        printf("\n1. Insert into List 1\n");  
        printf("2. Insert into List 2\n");  
        printf("3. Print List 1\n");  
        printf("4. Print List 2\n");  
        printf("5. Perform Union and Print Result\n");  
        printf("6. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  

        switch (choice) {  
            case 1:  
                printf("Enter data to insert into List 1: ");  
                scanf("%d", &data);  
                insert(&list1, data);  
                break;  
            case 2:  
                printf("Enter data to insert into List 2: ");  
                scanf("%d", &data);  
                insert(&list2, data);  
                break;  
            case 3:  
                printf("List 1: ");  
                printList(list1);  
                break;  
            case 4:  
                printf("List 2: ");  
                printList(list2);  
                break;  
            case 5:  
                unionResult = unionList(list1, list2);  
                printf("Union of List 1 and List 2: ");  
                printList(unionResult);  
                freeList(unionResult);
                break;  
            case 6:  
                printf("Exiting program.\n");  
                freeList(list1); 
                freeList(list2); 
                freeList(unionResult); 
                return 0; 
            default:  
                printf("Invalid choice. Please try again.\n");  
        }  
    }  

    return 0;
} 