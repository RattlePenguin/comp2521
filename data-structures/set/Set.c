#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

static int hash(int value) {
    return value % SIZE;
}

// Create and initialize Set
Set SetNew() {
	Set s = calloc(1, sizeof(struct set));
    for (int i = 0; i < SIZE; i++) {
        s->table[i] = NULL;
    }
	return s;
}

// Free Set
void SetFree(Set s) {
    for (int i = 0; i < SIZE; i++) {
        Node current = s->table[i];
        while (current != NULL) {
			Node toDelete = current;
			current = current->next;
			free(toDelete);
        }
    }
	free(s);
}

// Add an element to the Set
void SetAdd(Set s, int value) {
    int index = hash(value);
    Node newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // Check if the value already exists in the set
    Node current = s->table[index];
    while (current != NULL) {
        if (current->data == value) {
            free(newNode); // Avoid duplication
            return;
        }
        current = current->next;
    }

    // Insert the new node at the beginning of the chain
    newNode->next = s->table[index];
    s->table[index] = newNode;
}

// Check if an element exists in the Set
bool SetContains(Set s, int value) {
    int index = hash(value);
    Node current = s->table[index];
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Remove an element from the Set
void SetRemove(Set s, int value) {
    int index = hash(value);
    Node current = s->table[index];
    Node prev = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                s->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Print the elements of the Set
void SetPrint(Set s) {
    for (int i = 0; i < SIZE; i++) {
        Node current = s->table[i];
        if (current != NULL) {
            printf("Bucket %d: ", i);
            while (current != NULL) {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}
