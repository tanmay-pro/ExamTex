#include "../function_def.h"
#include "../main.h"

ptrnode make_node(elementType e) // Function to create node of tree
{
    ptrnode p_new;
    p_new = (ptrnode)malloc(sizeof(treeNode));
    p_new->element = e; // Assign Element Value/ Node Value
    p_new->nextsibling = NULL;
    p_new->firstchild = NULL; // Initialize all properties after assigning memory
    return p_new; // return pointer
}

ptrnode insert_below(ptrnode tree, elementType e) // Function to insert node as a first child of existing node
{
    if (tree == NULL)
    {
        tree = make_node(e);
    }
    else
    {
        tree->firstchild = insert_below(tree->firstchild, e); // Traverse Vertically
    }
    return tree; // return pointer
}

ptrnode insert_horizontally(ptrnode tree, elementType e) // Function to insert node as last nextsibling of existing nodes
{
    if (tree == NULL)
    {
        tree = make_node(e);
    }
    else
    {
        tree->nextsibling = insert_horizontally(tree->nextsibling, e); // Traverse Horizontally
    }
    return tree; // return pointer
}
