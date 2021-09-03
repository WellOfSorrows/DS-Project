
#ifndef DS_PROJECT_AVL_TREE_H
#define DS_PROJECT_AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DataStructures.h"

int maxNum(int a, int b) { return (a > b) ? a : b; }

EntityT *rootHM = NULL;
EntityT *rootID = NULL;
int height(EntityT *node);
int getBalance(EntityT *N);
EntityT* rightRotate(EntityT *y);
EntityT* leftRotate(EntityT *x);
EntityT* insertTreeNode(EntityT *root, EntityT *new_node);
EntityT* insertTreeNodeID(EntityT *root, EntityT *new_node);
EntityT* minValueNode(EntityT *node);
EntityT* deleteTreeNode(EntityT *root, EntityT *node);
EntityT* deleteTreeNodeID(EntityT *root, EntityT *node);
EntityT* findTreeNodeID(EntityT *root, unsigned int ID);

int height(EntityT *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

EntityT* rightRotate(EntityT *y)
{
    EntityT *x = y->leftChild;
    EntityT *T2 = y->leftChild->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    y->height = maxNum(height(y->leftChild), height(y->rightChild)) + 1;
    x->height = maxNum(height(x->leftChild), height(x->rightChild)) + 1;

    return x;
}

EntityT* leftRotate(EntityT *x)
{
    EntityT *y = x->rightChild;
    EntityT *T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    x->height = maxNum(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = maxNum(height(y->leftChild), height(y->rightChild)) + 1;

    return y;
}

int getBalance(EntityT *N)
{
    if (N == NULL)
        return 0;
    return height(N->leftChild) - height(N->rightChild);
}

EntityT* insertTreeNode(EntityT *root, EntityT *new_node)
{
    //	Time complexity:    O(log(n))

    if (root == NULL) {
        root = new_node;
        return root;
    }

    if (new_node->cmpst->value < root->cmpst->value)
        root->leftChild = insertTreeNode(root->leftChild, new_node);

    else if ((new_node->cmpst->value >= root->cmpst->value) && (new_node->cmpst->ID != root->cmpst->ID))
        root->rightChild = insertTreeNode(root->rightChild, new_node);


    root->height = 1 + maxNum(height(root->leftChild), height(root->rightChild));
    int balance = getBalance(root);

    if (balance > 1 && root->leftChild != NULL && new_node->cmpst->value < root->leftChild->cmpst->value)
        return rightRotate(root);

    if (balance < -1 && root->rightChild != NULL && new_node->cmpst->value > root->rightChild->cmpst->value)
        return leftRotate(root);

    if (balance > 1 && root->leftChild != NULL && new_node->cmpst->value > root->leftChild->cmpst->value) {
        if (root->leftChild->rightChild != NULL && root->leftChild->rightChild->leftChild != NULL)
            root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && root->rightChild != NULL && new_node->cmpst->value < root->rightChild->cmpst->value) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root;
}

EntityT* insertTreeNodeID(EntityT *root, EntityT *new_node)
{
    //	Time complexity:    O(log(n))
    if (root == NULL) {
        root = new_node;
        return root;
    }

    if (new_node->cmpst->ID < root->cmpst->ID) {
        root->leftChild = insertTreeNodeID(root->leftChild, new_node);
    }

    else if (new_node->cmpst->ID > root->cmpst->ID) {
        root->rightChild = insertTreeNodeID(root->rightChild, new_node);
    }


    root->height = 1 + maxNum(height(root->leftChild), height(root->rightChild));
    int balance = getBalance(root);

    if (balance > 1 && new_node->cmpst->ID < root->leftChild->cmpst->ID)
        return rightRotate(root);

    if (balance < -1 && new_node->cmpst->ID > root->rightChild->cmpst->ID)
        return leftRotate(root);

    if (balance > 1 && new_node->cmpst->ID > root->leftChild->cmpst->ID) {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && new_node->cmpst->ID < root->rightChild->cmpst->ID) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }
    return root;
}

EntityT* minValueNode(EntityT *node)
{
    //	Time complexity:    O(log(n))
    EntityT *current = node;

    while (current->leftChild != NULL)
        current = current->leftChild;

    return current;
}

EntityT* deleteTreeNode(EntityT *root, EntityT *node)
{
    //	Time complexity:    O(log(n))
    if (root == NULL)
        return root;

    if ((node != NULL) && (node->cmpst->value < root->cmpst->value)) {
        root->leftChild = deleteTreeNode(root->leftChild, node);
    }
    else if ((node != NULL) && (node->cmpst->value >= root->cmpst->value && (node->cmpst->ID != root->cmpst->ID))) {
        root->rightChild = deleteTreeNode(root->rightChild, node);
    }
    else {
        if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
            EntityT *temp = root->leftChild ? root->leftChild : root->rightChild;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            EntityT *temp = minValueNode(root->rightChild);
            root->cmpst->value = temp->cmpst->value;
            root->rightChild = deleteTreeNode(root->rightChild, temp);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maxNum(height(root->leftChild), height(root->rightChild));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->leftChild) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->leftChild) < 0) {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->rightChild) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->rightChild) > 0) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root;
}

EntityT* deleteTreeNodeID(EntityT *root, EntityT *node)
{
    //	Time complexity:    O(log(n))
    if (root == NULL)
        return root;

    if (node->cmpst->ID < root->cmpst->ID) {
        root->leftChild = deleteTreeNodeID(root->leftChild, node);
    }
    else if (node->cmpst->ID > root->cmpst->ID) {
        root->rightChild = deleteTreeNodeID(root->rightChild, node);
    }
    else {
        if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
            EntityT *temp = root->leftChild ? root->leftChild : root->rightChild;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = (*temp);
            }

            free(temp);
        }
        else {
            EntityT *temp = minValueNode(root->rightChild);
            root->cmpst->ID = temp->cmpst->ID;
            root->rightChild = deleteTreeNodeID(root->rightChild, temp);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maxNum(height(root->leftChild), height(root->rightChild));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->leftChild) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->leftChild) < 0) {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->rightChild) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->rightChild) > 0) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root;
}

EntityT* findTreeNodeID(EntityT *root, unsigned int ID)
{
    //	Time complexity:    O(log(n))
    EntityT *current = root;

    while (current != NULL) {
        if (ID == current->cmpst->ID) {
            return current;
        }
        else if (ID < current->cmpst->ID) {
            current = current->leftChild;
        }
        else {
            current = current->rightChild;
        }
    }

    return current;
}

#endif //DS_PROJECT_AVL_TREE_H
