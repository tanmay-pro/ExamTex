#include "tree_node_struct.h"
#include "../function_def.h"

ptrnode add_mcq_question_to_bank(ptrnode tree, mcq *question, int index) // This function adds mcq question to tree
{
	ptrnode temp = tree;
	temp = temp->firstchild; // Goes to MCQ node
	int diff = question->difficulty;
	if (diff == 0)
	{
		temp = temp->firstchild;
	}
	else if (diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if (diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if (diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	}  // This is pushing the control to the correct difficulty level
	if (temp->firstchild == NULL)
	{
		temp = insert_below(temp, index); //Inserting a node below since no child exists
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	} // Inserting a sibling to already existing children
	return tree;
}

ptrnode add_fill_up_question_to_bank(ptrnode tree, fill_up *question, int index)
{
	ptrnode temp = tree;
	temp = temp->firstchild->nextsibling; // Goes to Fill_up node
	double diff = question->difficulty;
	if (diff == 0)
	{
		temp = temp->firstchild;
	}
	else if (diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if (diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if (diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	} // This is pushing the control to the correct difficulty level
	if (temp->firstchild == NULL)
	{
		temp = insert_below(temp, index); //Inserting a node below since no child exists
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	} // Inserting a sibling to already existing children
	return tree;
}

ptrnode add_true_false_question_to_bank(ptrnode tree, true_false *question, int index)
{
	ptrnode temp = tree;
	temp = temp->firstchild->nextsibling->nextsibling; // Goes to true_false node
	double diff = question->difficulty;
	if (diff == 0)
	{
		temp = temp->firstchild;
	}
	else if (diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if (diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if (diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	} // This is pushing the control to the correct difficulty level
	if (temp->firstchild == NULL)
	{
		temp = insert_below(temp, index); //Inserting a node below since no child exists
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	} // Inserting a sibling to already existing children
	return tree;
}

ptrnode add_short_answer_question_to_bank(ptrnode tree, short_answer *question, int index)
{
	ptrnode temp = tree;
	temp = temp->firstchild->nextsibling->nextsibling->nextsibling; // Goes to short_answer node
	double diff = question->difficulty;
	if (diff == 0)
	{
		temp = temp->firstchild;
	}
	else if (diff == 1)
	{
		temp = temp->firstchild->nextsibling;
	}
	else if (diff == 2)
	{
		temp = temp->firstchild->nextsibling->nextsibling;
	}
	else if (diff == 3)
	{
		temp = temp->firstchild->nextsibling->nextsibling->nextsibling;
	} // This is pushing the control to the correct difficulty level
	if (temp->firstchild == NULL)
	{
		temp = insert_below(temp, index); //Inserting a node below since no child exists
	}
	else
	{
		temp = temp->firstchild;
		temp = insert_horizontally(temp, index);
	} // Inserting a sibling to already existing children
	return tree;
}
