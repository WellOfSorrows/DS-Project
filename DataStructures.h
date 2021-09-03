
#ifndef DS_PROJECT_DATASTRUCTURES_H
#define DS_PROJECT_DATASTRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct entity_QueueLinkedList;
struct entity_AVLTree;
struct entity_Composite;
typedef struct entity_QueueLinkedList EntityQ;
typedef struct entity_AVLTree EntityT;
typedef struct entity_Composite EntityC;
EntityQ* createEntityQ();
EntityT* createEntityT();
EntityC* createEntityC(unsigned int, int);

struct entity_QueueLinkedList
        {
    EntityQ* prev;
    EntityQ* next;
    EntityC* cmpst;
        };

struct entity_AVLTree
        {
    int height;
    EntityT* leftChild;
    EntityT* rightChild;
    EntityC* cmpst;
        };

struct entity_Composite
        {
    int value;
    unsigned int ID;
    EntityT* treeForm;
    EntityQ* queueForm;
    EntityT* treeFormID;
    EntityC* prev;
    EntityC* next;
        };

EntityQ* createEntityQ()
{
    EntityQ *root_q = NULL;
    root_q = (EntityQ*) malloc(sizeof(EntityQ));
    root_q->prev = NULL;
    root_q->next = NULL;
    root_q->cmpst = NULL;

    return (root_q);
}

EntityT* createEntityT()
{
    EntityT *root_m = NULL;
    root_m = (EntityT*) malloc(sizeof(EntityT));
    root_m->leftChild = NULL;
    root_m->rightChild = NULL;
    root_m->height = 1;
    root_m->cmpst = NULL;

    return (root_m);
}

EntityC* createEntityC(unsigned int ID, int value)
{
    EntityC *root = NULL;
    root = (EntityC*) malloc(sizeof(EntityC));
    EntityT *rootT = createEntityT();
    EntityQ *rootQ = createEntityQ();
    EntityT *rootD = createEntityT();

    rootT->cmpst = root;
    rootQ->cmpst = root;
    rootD->cmpst = root;

    root->value = value;
    root->ID = ID;
    root->treeForm = rootT;
    root->queueForm = rootQ;
    root->treeFormID = rootD;
    root->prev = NULL;
    root->next = NULL;

    return root;
}

#endif //DS_PROJECT_DATASTRUCTURES_H
