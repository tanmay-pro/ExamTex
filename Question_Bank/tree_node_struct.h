#ifndef TREE_H_
#define TREE_H_

typedef int elementType;
typedef struct treeNode treeNode;
typedef struct treeNode *ptrnode;

struct treeNode
{
    elementType element; // Data of Node
    ptrnode nextsibling; // Immediate Next Sibling of node
    ptrnode firstchild; // pointer to first child of node
};

#endif