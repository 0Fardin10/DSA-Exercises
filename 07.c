#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end (to build the list)
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Delete from the beginning
void deleteAtBeginning(struct Node** head) {

    // Case 1: List is empty
    if (*head == NULL) {
        printf("   List is empty! Nothing to delete.\n");
        return;
    }

    // Case 2: Only one node in the list
    struct Node* temp = *head;
    if ((*head)->next == NULL) {
        printf("   %d deleted — List is now empty.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    // Case 3: Multiple nodes — delete head
    *head = (*head)->next;       // Move head to next node
    printf("   %d deleted from beginning\n", temp->data);
    free(temp);                  // Free old head
}// Display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("  List: EMPTY\n");
        return;
    }
    printf("  HEAD → ");
    while (head != NULL) {
        printf("[%d] → ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
//Free entire list 
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main(){
struct Node* head = NULL;
int n,data,choice;
printf("╔══════════════════════════════════════════╗\n");
printf("║  DELETE NODE FROM BEGINNING - LINKED LIST║\n");
printf("╚══════════════════════════════════════════╝\n");
//Build the linked list
printf("\n How many nodes to create?");
scanf("%d",&n);
printf("\n--Building Linked List--\n");
 for (int i = 1; i <=n; i++)
 {
 printf("Enter data for node %d: ",i);   
 scanf("%d",&data);
 insertAtEnd(&head,data);
 }
  printf("\n--- Initial List ---\n");
    display(head);
    printf("  Total Nodes: %d\n", countNodes(head));

    // Deletion menu
    do {
        printf("\n┌─────────────────────────────┐\n");
        printf("│  1. Delete from Beginning     │\n");
        printf("│  2. Display List              │\n");
        printf("│  3. Count Nodes               │\n");
        printf("│  0. Exit                      │\n");
        printf("└─────────------────────────────┘\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Before Deletion ---\n");
                display(head);
                deleteAtBeginning(&head);
                printf("--- After Deletion  ---\n");
                display(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("  Total Nodes: %d\n", countNodes(head));
                break;
            case 0:
                printf("\n  Exiting... Goodbye!\n");
                break;
            default:
                printf("   Invalid choice!\n");
        }
    } while (choice != 0);

    freeList(&head);
    return 0;
}
