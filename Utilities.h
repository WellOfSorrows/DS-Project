
#ifndef DS_PROJECT_UTILITIES_H
#define DS_PROJECT_UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DataStructures.h"
#include "AVL_Tree.h"
#include "Queue.h"

void printPreOrder(EntityT *root);
void printPreOrderID(EntityT *rootID);
void displayQueue();
void displayQueueComplex();
void getWord(char str[]);

void printPreOrder(EntityT *root)
{
    if (root != NULL) {
        printf("%d ", root->cmpst->value);
        printPreOrder(root->leftChild);
        printPreOrder(root->rightChild);
    }
}

void printPreOrderID(EntityT *rootID)
{
    if (rootID != NULL) {
        printf("%u ", rootID->cmpst->ID);
        printPreOrderID(rootID->leftChild);
        printPreOrderID(rootID->rightChild);
    }
}

void displayQueue()
{
    if (front == NULL && rear == NULL) {
        printf("The queue is empty");
        return;
    }
    else {
        EntityQ *temp = front;
        while (temp != NULL) {
            printf("%u: %d\n", temp->cmpst->ID, temp->cmpst->value);
            temp = temp->next;
        }
    }
    printf("\n");
}

void displayQueueComplex()
{
    if (head == NULL && tail == NULL) {
        printf("\n   -> OUT: The list is empty.\n\n");
        return;
    }
    else {
        EntityC *temp = head;
        printf("\n   -> OUT: ");
        while (temp != NULL) {
            printf("%u %d\n           ", temp->ID, temp->value);
            temp = temp->next;
        }
    }
    printf("\n");
}

void getWord(char str[])
{
    int i = 0;
    char temp = getchar();
    while (temp == ' ' || temp == '\t' || temp == '\n' || temp == '\v' || temp == '\f' || temp == '\r')
        temp = getchar();

    while (temp != ' ' && temp != '\t' && temp != '\n' && temp != '\v' && temp != '\f' && temp != '\r' && temp != EOF) {
        str[i] = temp;
        i++;
        temp = getchar();
    }
    str[i] = '\0';
}

#endif //DS_PROJECT_UTILITIES_H
