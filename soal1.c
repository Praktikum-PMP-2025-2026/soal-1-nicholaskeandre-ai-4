#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void menuChoice();
void pushFront();
void pushBack();
void delete();
void find();
void displayAll();

int main() {
    menuChoice();

    return 0;
}

void menuChoice() {
    int Q, choice;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        scanf("%d", &choice);

        switch (choice) {
            case 1: pushFront(); break;
            case 2: pushBack(); break;
            case 3: delete(); break;
            case 4: find(); break;
            default: break;
        }
    }

    displayAll();
}

void pushFront() {
    int x;
    scanf("%d", &x);

    Node *newData = (Node*) malloc(sizeof(Node));

    newData->data = x;
    newData->next = NULL;

    if (head == NULL) {
        head = newData;
    } else {
        newData->next = head;
        head = newData;
    }
}

void pushBack() {
    int x;
    scanf("%d", &x);

    Node *newData = (Node*) malloc(sizeof(Node));

    newData->data = x;
    newData->next = NULL;

    if (head == NULL) {
        head = newData;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newData;
    }
}

void delete() {
    int x;
    scanf("%d", &x);

    Node *next = head;
    Node *prev = NULL;

    while (next != NULL && next->data != x) {
        prev = next;
        next = next->next;  
    }

    if (next == NULL) {
        return;
    }

    if (prev == NULL) {
        head = next->next;
    } else {
        prev->next = next->next;
    }

    free(next);
}

void find() {
    int x;
    scanf("%d", &x);

    int idx = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            printf("FOUND %d\n", idx);
            return;
        }
        temp = temp->next;
        idx++;
    }
    printf("NOT FOUND\n");
}

void displayAll() {
    if (head == NULL) {
        printf("LIST EMPTY\n");
        return; 
    }

    Node *temp = head;
    printf("LIST");
    while (temp != NULL) {
        printf(" %d", temp->data); 
        temp = temp->next; 
    }
    printf("\n");
}
