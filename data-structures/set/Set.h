#include <stdbool.h>

#define SIZE 64 

typedef struct node {
    int data;
    struct node *next;
} *Node;

typedef struct set {
    Node table[SIZE];
} *Set;

Set SetNew();
void SetFree(Set s);
void SetAdd(Set s, int value);
bool SetContains(Set s, int value);
void SetRemove(Set s, int value);
void SetPrint(Set s);
