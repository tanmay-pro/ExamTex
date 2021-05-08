#include "tree_node_struct.h"
#include "../function_def.h"

ptrnode add_mcq_question_to_bank(ptrnode tree, mcq* question, int index)
{
	ptrnode temp = tree;
	temp = temp->firstchild->firstchild;
	int diff = question->difficulty;
	while (diff--)
    {
        temp = temp->nextsibling;
	}
    //!!!can do this for other types as well to make the code consise especially if u would wanna add more difficulty levels in future
	//
	/*if(diff == 0)
	{
		temp = temp->firstchild;
	}
	else if(diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if(diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if(diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	}*/
	if(temp->firstchild == NULL)
	{
		temp = insert_below(temp, index);
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	}
	return tree;
}

ptrnode add_fill_up_question_to_bank(ptrnode tree, fill_up* question, int index)
{
	ptrnode temp = tree;
	temp = temp->firstchild->nextsibling;
	double diff = question->difficulty;
	if(diff == 0)
	{
		temp = temp->firstchild;
	}
	else if(diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if(diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if(diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	}
	if(temp->firstchild == NULL)
	{
		temp = insert_below(temp, index);
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	}
	return tree;
}

ptrnode add_true_false_question_to_bank(ptrnode tree, true_false* question, int index)
{
	ptrnode temp = tree;
	temp = temp->firstchild->nextsibling->nextsibling;
	double diff = question->difficulty;
	if(diff == 0)
	{
		temp = temp->firstchild;
	}
	else if(diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if(diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if(diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	}
	if(temp->firstchild == NULL)
	{
		temp = insert_below(temp, index);
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	}
	return tree;
}

ptrnode add_short_answer_question_to_bank(ptrnode tree, short_answer* question, int index)
{
	ptrnode temp = tree;
	temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	double diff = question->difficulty;
	if(diff == 0)
	{
		temp = temp->firstchild;
	}
	else if(diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if(diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if(diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	}
	if(temp->firstchild == NULL)
	{
		temp = insert_below(temp, index);
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	}
	return tree;
}
