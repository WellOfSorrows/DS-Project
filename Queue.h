#ifndef DS_PROJECT_QUEUE_H
#define DS_PROJECT_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DataStructures.h"

EntityQ *front = NULL;
EntityQ *rear = NULL;
EntityC *head = NULL;
EntityC *tail = NULL;

void queueAdd(EntityQ *newNode);
void queueAddComplex(EntityC *newNode);
void queueDelete(EntityQ *node);
void queueDeleteComplex(EntityC *node);

void queueAdd(EntityQ *newNode)
{
    //	Time complexity:    O(1)

    if (front == NULL && rear == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        front = newNode;
        rear = newNode;
    }
    else {
        newNode->prev = rear;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }
}

void queueAddComplex(EntityC *newNode)
{
    //	Time complexity:    O(1)
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) tail = newNode;
    else head->prev = newNode;

    head = newNode;
}

void queueDelete(EntityQ *node)
{
    //	Time complexity:    O(1)
    if (front == NULL || node == NULL) return;

    if (front == node) {
        front = node->next;
        if (front == NULL) {
            rear = NULL;
        }
    }

    if (node->next != NULL) node->next->prev = node->prev;

    if (node->prev != NULL) node->prev->next = node->next;

    free(node);
}

void queueDeleteComplex(EntityC *node)
{
    //	Time complexity:    O(1)

    if (head == NULL || node == NULL) return;

    if (head == node) {
        head = node->next;
        if (head == NULL) {
            tail = NULL;
        }
    }

    if (node->next != NULL) node->next->prev = node->prev;

    if (node->prev != NULL) node->prev->next = node->next;

    node->queueForm = NULL;
    node->treeForm = NULL;
    node->treeFormID = NULL;
    node = NULL;
    free(node);
}

#endif //DS_PROJECT_QUEUE_H
