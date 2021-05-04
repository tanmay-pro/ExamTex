#include "tree_node_struct.h"
#include "../function_def.h"

void add_mcq_question_to_bank(ptrnode tree, mcq* question, int index)
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
}

void add_fill_up_question_to_bank(ptrnode tree, fill_up* question, int index)
{
	tree = tree->firstchild;
	tree = tree->nextsibling;
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
}

void add_true_false_question_to_bank(ptrnode tree, true_false* question, int index)
{
	tree = tree->firstchild;
	tree = tree->nextsibling;
	tree = tree->nextsibling;
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
}

void add_short_answer_question_to_bank(ptrnode tree, short_answer* question, int index)
{
	tree = tree->firstchild;
	tree = tree->nextsibling;
	tree = tree->nextsibling;
	tree = tree->nextsibling;
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
}
