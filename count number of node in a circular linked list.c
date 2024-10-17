#include <stdio.h>  
#include <stdlib.h>  

struct Node {  
    int data;  
    struct Node* next;  
};  

struct Node* insertNode(struct Node* head, int data);  
int countNodes(struct Node* head);  
void displayList(struct Node* head);  

struct Node* insertNode(struct Node* head, int data) {  
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = data;  
    
    if (head == NULL) {  
        newNode->next = newNode;  
        return newNode;  
    }  
    
    struct Node* temp = head;  
    while (temp->next != head) {  
        temp = temp->next;  
    }  
    
    temp->next = newNode;  
    newNode->next = head;  
    return head;  
}  

int countNodes(struct Node* head) {  
    if (head == NULL) return 0;  

    int count = 1;  
    struct Node* temp = head->next;  
    while (temp != head) {  
        count++;  
        temp = temp->next;  
    }  
    return count;  
}  

void displayList(struct Node* head) {  
    if (head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  

    struct Node* temp = head;  
    do {  
        printf("%d -> ", temp->data);  
        temp = temp->next;  
    } while (temp != head);  
    printf("(back to head)\n");  
}  

int main() {  
    struct Node* head = NULL ;  
    
    head = insertNode(head, 1);  
    head = insertNode(head, 2);  
    head = insertNode(head, 3);  
    head = insertNode(head, 4);  
    
    printf("Circular Singly Linked List:\n");  
    displayList(head);  
    
    int totalNodes = countNodes(head);  
    printf("Total number of nodes: %d\n", totalNodes);  
    
    return 0;  
}   