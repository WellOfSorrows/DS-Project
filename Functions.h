#ifndef DS_PROJECT_FUNCTIONS_H
#define DS_PROJECT_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DataStructures.h"
#include "AVL_Tree.h"
#include "Queue.h"
#include "Utilities.h"

void addNode(unsigned int ID, int value);
void serveSickest();
void serveFirst();
void update(unsigned int ID, int new_value);

void update(unsigned int ID, int new_value)
{
    //	Time complexity:    O(log(n))

    EntityT *tempID = findTreeNodeID(rootID, ID);               //	Time complexity:    O(log(n))

    if (tempID != NULL) {
        EntityC *tempC = tempID->cmpst;
        EntityC *new_var = createEntityC(ID, new_value);
        new_var->queueForm = tempC->queueForm;
        tempC->queueForm->cmpst = new_var;
        new_var->treeFormID = tempC->treeFormID;
        tempC->treeFormID->cmpst = new_var;

        rootHM = deleteTreeNode(rootHM, tempC->treeForm);       //	Time complexity:    O(1)
        queueDeleteComplex(tempC);	                            //	Time complexity:    O(1)
        rootHM = insertTreeNode(rootHM, new_var->treeForm);	    //	Time complexity:    O(log(n))
        queueAddComplex(new_var);								//	Time complexity:    O(1)
    }

    else
        printf("\n   -> ERROR: Given patient does not exist.\n\n");
}

void serveFirst()
{
    //	Time complexity:    O(log(n))

    EntityQ *tmpQ = front;	                                    //	Time complexity:    O(1)
    EntityC *tmpC = tmpQ->cmpst;
    EntityT *tmpT = tmpC->treeForm;
    EntityT *tmpD = tmpC->treeFormID;

    printf("\n   -> OUT: %u %d \n\n", tmpC->ID, tmpC->value);
    rootHM = deleteTreeNode(rootHM, tmpT);					    //	Time complexity:    O(log(n))
    rootID = deleteTreeNodeID(rootID, tmpD);				    //	Time complexity:    O(log(n))
    queueDelete(tmpQ);							                //	Time complexity:    O(1)
    queueDeleteComplex(tmpC);								    //	Time complexity:    O(1)
}

void serveSickest()
{
    //	Time complexity:    O(log(n))

    EntityT *tmpT = minValueNode(rootHM);					    //	Time complexity:    O(log(n))
    EntityC *tmpC = tmpT->cmpst;
    EntityQ *tmpQ = tmpC->queueForm;
    EntityT *tmpD = tmpC->treeFormID;

    printf("\n   -> OUT: %u %d \n\n", tmpC->ID, tmpC->value);
    rootID = deleteTreeNodeID(rootID, tmpD);                    //	Time complexity:    O(log(n))
    rootHM = deleteTreeNode(rootHM, tmpT);	                    //	Time complexity:    O(log(n))
    queueDelete(tmpQ);										    //	Time complexity:    O(1)
    queueDeleteComplex(tmpC);									//	Time complexity:    O(1)
}

void addNode(unsigned int ID, int value)
{
    //	Time complexity:    O(log(n))

    EntityC *master = createEntityC(ID, value);
    queueAdd(master->queueForm);									//	Time complexity:    O(1)
    rootHM = insertTreeNode(rootHM, master->treeForm);			//	Time complexity:    O(log(n))
    rootID = insertTreeNodeID(rootID, master->treeFormID);		//	Time complexity:    O(log(n))
    queueAddComplex(master);						            //	Time complexity:    O(1)
}

#endif //DS_PROJECT_FUNCTIONS_H
