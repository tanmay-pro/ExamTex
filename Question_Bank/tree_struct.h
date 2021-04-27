#ifndef TREE_H_
#define TREE_H_

typedef int elementType;
typedef struct treeNode treeNode;
typedef struct treeNode *ptrnode;

struct treeNode
{
    elementType element;
    ptrnode nextsibling;
    ptrnode firstchild;
    ptrnode parent;
};

#endif