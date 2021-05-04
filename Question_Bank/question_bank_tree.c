#include "../function_def.h"

ptrnode make_node(elementType e)
{
    ptrnode p_new;
	p_new = (ptrnode)malloc(sizeof(treeNode));
	p_new->element = e;
	p_new->nextsibling = NULL;
	p_new->firstchild = NULL;
    return p_new;
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
