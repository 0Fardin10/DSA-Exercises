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

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty, new node becomes head
    if (*head == NULL) {
        *head = newNode;
        printf("   %d inserted as first node (head)\n", data);
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    // Link new node at the end
    temp->next = newNode;
    printf("   %d inserted at end\n", data);
}

// Display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("  List is empty!\n");
        return;
    }
    printf("\n  HEAD → ");
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

// Free entire list
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("╔════════════════════════════════════╗\n");
    printf("║  INSERT NODE AT END - LINKED LIST  ║\n");
    printf("╚════════════════════════════════════╝\n");

    printf("\nHow many nodes to insert? ");
    scanf("%d", &n);

    printf("\n--- Inserting %d Nodes at End ---\n", n);
    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        insertAtEnd(&head, data);
        display(head);
    }

    printf("\n╔════════════════════════════════════╗\n");
    printf("║           FINAL LIST               ║\n");
    printf("╚════════════════════════════════════╝\n");
    display(head);
    printf("\n  Total Nodes: %d\n", countNodes(head));

    freeList(&head);
    return 0;
}