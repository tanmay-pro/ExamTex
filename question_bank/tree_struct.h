#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef int elementType;
typedef struct treeNode treeNode;
typedef struct treeNode *ptrnode;

#define ll long long
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

struct treeNode
{
    elementType element;
    ptrnode nextsibling;
    ptrnode firstchild;
    ptrnode parent;
};

ptrnode make_node(elementType e);
ptrnode insert_below(ptrnode tree, elementType e);
ptrnode insert_horizontally(ptrnode tree, elementType e);
#endif