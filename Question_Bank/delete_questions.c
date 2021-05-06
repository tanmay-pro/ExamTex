#include"../function_def.h"


void functionToDeleteQuestionBank(ptrnode qb[])
{
	int input_id = 0;
	printf("Please Enter the id of the Question bank you want to Delete");
	br;
	scanf("%d", &input_id);
	ptrnode temp = qb[input_id];
	free(temp);
	qb[input_id] = NULL;
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
	else if(diff > 2)
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

