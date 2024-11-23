//
// Created by linho on 2024-11-23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_node.h"

struct Node* createNode(const char* signal, int duration) {
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->signal, signal);
    newNode->duration = duration;
    newNode->next = newNode;

    return newNode;
}

// Insert a node at the end of the list
void insertAtEnd(struct Node** head, const char* signal, int duration) {
    struct Node* newNode;
    struct Node* temp;

    newNode = createNode(signal, duration);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while(temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;   // Set the last node's next pointer to the new node
    newNode->next = *head;  // Set the new node's next pointer to the head
}

// Delete a node with a given signal color
void deleteNode(struct Node** head, const char* signal) {
    if(*head == NULL) {
        return;
    }

    struct Node* temp;
    struct Node* prev;

    temp = *head;
    prev = NULL;

    // If the head node itself holds the signal to be deleted
    if(strcmp(temp->signal, signal) == 0 && temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    // If the head node itself holds the signal to be deleted and there are more nodes
    if(strcmp(temp->signal, signal) == 0) {
        while(temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }

    // Search for the signal to be deleted, keeping track of the previous node
    while(temp->next != *head && strcmp(temp->signal, signal) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the signal was not present in the list
    if(strcmp(temp->signal, signal) != 0) {
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

// Display the list
void displayList(struct Node* head) {
    if(head == NULL) {
        return;
    }

    struct Node* temp;

    temp = head;

    do {
        printf("%s (%d seconds) ->", temp->signal, temp->duration);
        temp = temp->next;
    } while(temp != head);

    printf("%s (head)\n", head->signal);     // Indicate teh circular nature of the list
}

// Simulate traffic signal
void simulateTraffic(struct Node* head, int cycles) {
    if(head == NULL) {
        return;
    }

    struct Node* temp;

    temp = head;

    for(int i = 0; i < cycles; i++) {
        printf("Cycle %d\n", i + 1);
        do {
            printf("Signal: %s, Duration: %d seconds\n", temp->signal, temp->duration);
            temp = temp->next;
        } while(temp != head);
    }

    printf("Complete!\n\n");
}

