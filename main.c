#include <stdio.h>
#include <stdlib.h>
#include "circular_node.h"

int main(void) {
    struct Node* head;
    int c;

    head = NULL;

    insertAtEnd(&head, "Red", 30);
    insertAtEnd(&head, "Green", 45);
    insertAtEnd(&head, "Yellow", 10);

    printf("Circular linked list (traffic signals):\n");
    displayList(head);

    printf("\nHow many traffic cycle simulation would you want to see?\n");
    scanf("%d", &c);
    simulateTraffic(head, c);

    printf("Circular linked list after deletion:\n");
    deleteNode(&head, "Green");
    displayList(head);
}
