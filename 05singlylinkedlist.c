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

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("   %d inserted at beginning\n", data);
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("   %d inserted at end\n", data);
}

// Insert at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("  ✘ Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("  ✔ %d inserted at position %d\n", data, position);
}

// Delete from the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("  ✘ List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("  ✔ %d deleted from beginning\n", temp->data);
    free(temp);
}

// Delete from the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("  ✘ List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("  ✔ %d deleted from end\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("  ✔ %d deleted from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete by value
void deleteByValue(struct Node** head, int data) {
    if (*head == NULL) {
        printf("  ✘ List is empty!\n");
        return;
    }
    if ((*head)->data == data) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != data)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("   %d not found in list!\n", data);
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("   %d deleted from list\n", data);
    free(toDelete);
}

// Search for an element
void search(struct Node* head, int data) {
    int position = 1;
    while (head != NULL) {
        if (head->data == data) {
            printf("   %d found at position %d\n", data, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("   %d not found in list\n", data);
}

// Display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("  List is empty!\n");
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

// Free entire list
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("   List cleared from memory\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    printf("╔══════════════════════════════╗\n");
    printf("║    SINGLY LINKED LIST MENU   ║\n");
    printf("╚══════════════════════════════╝\n");

    do {
        printf("\n┌──────────────────────────────┐\n");
        printf("│  1. Insert at Beginning      │\n");
        printf("│  2. Insert at End            │\n");
        printf("│  3. Insert at Position       │\n");
        printf("│  4. Delete from Beginning    │\n");
        printf("│  5. Delete from End          │\n");
        printf("│  6. Delete by Value          │\n");
        printf("│  7. Search Element           │\n");
        printf("│  8. Display List             │\n");
        printf("│  9. Count Nodes              │\n");
        printf("│  0. Exit                     │\n");
        printf("└──────────────────────────────┘\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(&head, data);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("  Total Nodes: %d\n", countNodes(head));
                break;
            case 0:
                freeList(&head);
                printf("\n  Exiting... Goodbye!\n");
                break;
            default:
                printf("   Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
