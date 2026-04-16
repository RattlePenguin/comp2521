#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"

static int hash(int value) {
    return value % SIZE;
}

// Create and initialize HashTable 
HashTable HashTableNew() {
	HashTable ht = calloc(1, sizeof(struct hashTable));
    for (int i = 0; i < SIZE; i++) {
        ht->table[i] = NULL;
    }
	return ht;
}

// Free HashTable 
void HashTableFree(HashTable ht) {
    for (int i = 0; i < SIZE; i++) {
        Node current = ht->table[i];
        while (current != NULL) {
			Node toDelete = current;
			current = current->next;
			free(toDelete);
        }
    }
	free(ht);
}

// Add an element to the HashTable 
void HashTableInsert(HashTable ht, int key, int value) {
    int index = hash(key);
    Node newNode = malloc(sizeof(struct node));
	newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // Check if the key-value pair already exists
    Node current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            free(newNode); // Avoid duplication
            return;
        }
        current = current->next;
    }

    // Insert the new node at the beginning of the chain
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Check if an element exists in the HashTable
bool HashTableContains(HashTable ht, int key) {
    int index = hash(key);
    Node current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int HashTableGet(HashTable ht, int key) {
    int index = hash(key);
    Node current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// Remove an element from the HashTable
void HashTableRemove(HashTable ht, int key) {
    int index = hash(key);
    Node current = ht->table[index];
    Node prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                ht->table[index] = current->next;
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

// Print the elements of the HashTable
void HashTablePrint(HashTable ht) {
    for (int i = 0; i < SIZE; i++) {
        Node current = ht->table[i];
        if (current != NULL) {
            printf("Bucket %d: ", i);
            while (current != NULL) {
                printf("%d -> ", current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}
