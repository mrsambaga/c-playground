#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct test_struct
{
    int val;
    struct test_struct *next;
};

typedef struct test_struct Node;

Node* createAndPrintList();
Node* searchNode(Node *head, int value_to_find);
void deleteNode(Node **head_ref, int key);
void printList(Node *head);

int main()
{
    printf("--- 1. Creating and printing the initial list ---\n");
    Node *head = createAndPrintList();
    printf("\n");

    printf("--- 2. Searching for nodes ---\n");
    int value_to_search = 3;
    Node *found_node = searchNode(head, value_to_search);
    if (found_node != NULL) {
        printf("Node with value %d was found at memory address %p\n", value_to_search, found_node);
    } else {
        printf("Node with value %d was NOT found.\n", value_to_search);
    }

    value_to_search = 99;
    found_node = searchNode(head, value_to_search);
     if (found_node != NULL) {
        printf("Node with value %d was found at memory address %p\n", value_to_search, found_node);
    } else {
        printf("Node with value %d was NOT found.\n", value_to_search);
    }
    printf("\n");

    printf("--- 3. Deleting nodes ---\n");
    printf("List before deletion: ");
    printList(head);

    printf("Deleting node with value 3...\n");
    deleteNode(&head, 3);
    printf("List after deleting 3:  ");
    printList(head);

    printf("Deleting node with value 1 (the head)...\n");
    deleteNode(&head, 1);
    printf("List after deleting 1:  ");
    printList(head);

    free(head);

    return 0;
}

Node* createAndPrintList()
{
    Node *head   = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    Node *third  = (Node*)malloc(sizeof(Node));

    head->val = 1;       
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = NULL;

    printf("Created List: ");
    printList(head);

    return head;
}

Node* searchNode(Node *head, int value_to_find)
{
    Node *current = head; 

    while(current != NULL)
    {
        if(current->val == value_to_find)
        {
            return current; 
        }
        current = current->next;
    }
    return NULL;
}

void deleteNode(Node **head_ref, int key)
{
    Node *temp = *head_ref;
    Node *prev = NULL;

    if (temp != NULL && temp->val == key)
    {
        *head_ref = temp->next; 
        free(temp);
        return;
    }

    while (temp != NULL && temp->val != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

void printList(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->val);
        ptr = ptr->next;
    }
    printf("NULL\n");
}