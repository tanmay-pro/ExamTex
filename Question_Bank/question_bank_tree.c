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

ptrnode add_mcq_question_to_bank(ptrnode tree, mcq* question, int index)
{
	tree = tree->firstchild;
	double diff = question->difficulty;
	// Difficulty < 1 => Easy; Difficulty < 2 => Medium; Difficulty < 3 => Hard
	if(diff <= 1)
	{
		tree = tree->firstchild;
	}
	else if(diff > 1 && diff <= 2)
	{
		tree = tree->firstchild->nextsibling;
	}
	else if(diff > 2 && diff <= 3)
	{
		tree = tree->firstchild->nextsibling->nextsibling;
	}
	if(tree->firstchild == NULL)
	{
		tree = insert_below(tree, index);
	}
	else
	{
		tree = tree->firstchild;
		tree = insert_horizontally(tree, index);
	}
	return tree;
}

ptrnode delete_mcq_from_question_bank(ptrnode tree, mcq* question, int index)
{
	tree = tree->firstchild;
	double diff = question->difficulty;
	// Difficulty < 1 => Easy; Difficulty < 2 => Medium; Difficulty < 3 => Hard
	if(diff <= 1)
	{
		tree = tree->firstchild;
	}
	else if(diff > 1 && diff <= 2)
	{
		tree = tree->firstchild->nextsibling;
	}
	else if(diff > 2 && diff <= 3)
	{
		tree = tree->firstchild->nextsibling->nextsibling;
	}
	if(tree->firstchild != NULL)
	{
		if(tree->firstchild->element == index)
		{
			ptrnode temp = tree->firstchild;
			tree->firstchild = tree->firstchild->nextsibling;
			free(temp);
		}
		else
		{
			tree = tree->firstchild;
			while(true)
			{
				if(tree->nextsibling == NULL)
				{
					printf("Not Found");
					br;
					break;
				}
				if(tree->nextsibling->element == index)
				{
					ptrnode temp = tree->nextsibling;
					tree->nextsibling = tree->nextsibling->nextsibling;
					free(temp);
					break;
				}
				tree = tree->nextsibling;
			}
			
		}
	}
	else
	{
		printf("Such a question does not exist");
		br;
	}
	return tree;
}

