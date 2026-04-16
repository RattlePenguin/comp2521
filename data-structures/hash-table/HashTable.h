#include <stdbool.h>

#define SIZE 64 

typedef struct node {
	int key;
	int value;
	struct node *next;
} *Node;

typedef struct hashTable {
    Node table[SIZE];
} *HashTable;

HashTable HashTableNew();
void HashTableFree(HashTable ht);
void HashTableInsert(HashTable ht, int key, int value);
bool HashTableContains(HashTable ht, int key);
int HashTableGet(HashTable ht, int key);
void HashTableDelete(HashTable ht, int value);
void HashTableSize(HashTable ht);
