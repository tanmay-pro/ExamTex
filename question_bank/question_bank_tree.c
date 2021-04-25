#include "tree_struct.h"
#include "../function_def.h"

ptrnode make_node(elementType e)
{
    ptrnode pnew;
    pnew = (ptrnode)malloc(sizeof(treeNode));
    pnew->element = e;
    pnew->nextsibling = NULL;
    pnew->firstchild = NULL;
    return pnew;
}

ptrnode insert_below(ptrnode tree, elementType e)
{
    if (tree == NULL)
    {
        tree = make_node(e);
    }
    else
    {
        tree->firstchild = insert_below(tree->firstchild, e);
    }
    return tree;
}

ptrnode insert_horizontally(ptrnode tree, elementType e)
{
    if (tree == NULL)
    {
        tree = make_node(e);
    }
    else
    {
        tree->nextsibling = insert_horizontally(tree->nextsibling, e);
    }
    return tree;
}

ptrnode add_question_to_bank(ptrnode tree, int element)
{

}
