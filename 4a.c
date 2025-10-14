#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *getNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = data;
    temp->next = NULL;
    return temp;
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void insertBeg(struct Node **head, int info) {
    struct Node *newNode = getNode(info);
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at beginning\n", info);
}

void insertLast(struct Node **head, int info) {
    struct Node *newNode = getNode(info);
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at last\n", info);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    printf("%d inserted at last\n", info);
}

struct Node *search(struct Node *head, int data) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->info == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void insertAfter(struct Node **head, int data, int info) {
    struct Node *loc = search(*head, data);
    if (loc == NULL) {
        printf("%d not found in list!\n", data);
        return;
    }
    struct Node *newNode = getNode(info);
    newNode->next = loc->next;
    loc->next = newNode;
    printf("%d inserted after %d\n", info, data);
}

void removeBeg(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("%d removed from beginning\n", temp->info);
    free(temp);
}

void removeLast(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("%d removed from last\n", (*head)->info);
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("%d removed from last\n", temp->next->info);
    free(temp->next);
    temp->next = NULL;
}

void removeAfter(struct Node **head, int data) {
    struct Node *loc = search(*head, data);
    if (loc == NULL || loc->next == NULL) {
        printf("No node exists after %d\n", data);
        return;
    }
    struct Node *temp = loc->next;
    loc->next = temp->next;
    printf("%d removed after %d\n", temp->info, data);
    free(temp);
}

int main() {
    struct Node *head = NULL;
    int ch, info, data;

    do {
        printf("\n1. Add Beginning\n");
        printf("2. Add Last\n");
        printf("3. Add After a Node\n");
        printf("4. Remove Beginning\n");
        printf("5. Remove Last\n");
        printf("6. Remove After a Node\n");
        printf("7. Search\n");
        printf("8. Show\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter info: ");
                scanf("%d", &info);
                insertBeg(&head, info);
                break;
            case 2:
                printf("Enter info: ");
                scanf("%d", &info);
                insertLast(&head, info);
                break;
            case 3:
                printf("Insert after which node? ");
                scanf("%d", &data);
                printf("Enter info: ");
                scanf("%d", &info);
                insertAfter(&head, data, info);
                break;
            case 4:
                removeBeg(&head);
                break;
            case 5:
                removeLast(&head);
                break;
            case 6:
                printf("Remove after which node? ");
                scanf("%d", &data);
                removeAfter(&head, data);
                break;
            case 7: {
                printf("Enter value to search: ");
                scanf("%d", &info);
                struct Node *found = search(head, info);
                if (found != NULL)
                    printf("%d found in list\n", info);
                else
                    printf("%d not found\n", info);
                break;
            }
            case 8:
                traverse(head);
                break;
            case 9:
                printf("See you later\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 9);

    printf("\nThis code is executed by Shreyash Srivastava with Roll no 2400320101077\n");
    return 0;
}
