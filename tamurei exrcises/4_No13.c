#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* add(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = sum;
        newNode->next = NULL;
        if (result == NULL) {
            result = newNode;
            tail = result;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return result;
}

int main() {
    // Example usage
    struct Node* l1 = (struct Node*) malloc(sizeof(struct Node));
    l1->data = 2;
    l1->next = (struct Node*) malloc(sizeof(struct Node));
    l1->next->data = 4;
    l1->next->next = (struct Node*) malloc(sizeof(struct Node));
    l1->next->next->data = 3;
    l1->next->next->next = NULL;

    struct Node* l2 = (struct Node*) malloc(sizeof(struct Node));
    l2->data = 5;
    l2->next = (struct Node*) malloc(sizeof(struct Node));
    l2->next->data = 6;
    l2->next->next = (struct Node*) malloc(sizeof(struct Node));
    l2->next->next->data = 4;
    l2->next->next->next = NULL;

    struct Node* result = add(l1, l2);

    printf("Result: ");
    while (result != NULL) {
        printf("%d ", result->data);
        result = result->next;
    }
    printf("\n");

    return 0;
}