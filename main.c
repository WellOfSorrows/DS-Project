#include <stdio.h>
#include <string.h>
#include "DataStructures.h"
#include "AVL_Tree.h"
#include "Queue.h"
#include "Utilities.h"
#include "Functions.h"

bool driver()
{
    char str[50];
    getWord(str);

    if (strcmp(str, "Add") == 0) {
        int ID, value;
        scanf("%u %d", &ID, &value);
        addNode(ID, value);
    }

    else if (strcmp(str, "Update") == 0) {
        int ID, value;
        scanf("%u %d", &ID, &value);
        update(ID, value);
    }

    else if (strcmp(str, "Serve") == 0) {
        char method[50] = "Undefined";
        getWord(method);
        if (strcmp(method, "First") == 0) { serveFirst(); }
        else if (strcmp(method, "Sickest") == 0) { serveSickest(); }
    }

    else if (strcmp(str, "Exit") == 0) { return 0; }
    else if (strcmp(str, "Show") == 0) { displayQueueComplex();}
    else
        printf("\n   -> ERROR: Unknown command.\n");

    return 1;
}

int main(int argc, char const *argv[])
{
    int status = 1;
    while (status)
        status = driver();
    return 0;
}