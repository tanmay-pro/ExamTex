#include "../function_def.h"

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

//ptrnode delete_mcq_from_question_bank(ptrnode tree_base, mcq* question, int index)
//{
//	ptrnode tree = tree_base;
//	tree = tree->firstchild;
//	int diff = question->difficulty;
//	if(diff == 0)
//	{
//		tree = tree->firstchild;
//	}
//	else if(diff == 1)
//	{
//		tree = tree->firstchild->nextsibling;
//	}
//	else if(diff == 2)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling;
//	}
//	else if(diff == 3)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling->nextsibling;
//	}
//	if(tree->firstchild != NULL)
//	{
//		if(tree->firstchild->element == index)
//		{
//			ptrnode temp = tree->firstchild;
//			tree->firstchild = tree->firstchild->nextsibling;
//			free(temp);
//		}
//		else
//		{
//			tree = tree->firstchild;
//			while(true)
//			{
//				if(tree->nextsibling == NULL)
//				{
//					printf("Not Found");
//					br;
//					break;
//				}
//				if(tree->nextsibling->element == index)
//				{
//					ptrnode temp = tree->nextsibling;
//					tree->nextsibling = tree->nextsibling->nextsibling;
//					free(temp);
//					break;
//				}
//				tree = tree->nextsibling;
//			}
//
//		}
//	}
//	else
//	{
//		printf("Such a question does not exist");
//		br;
//	}
//	return tree_base;
//}
//
//ptrnode delete_fill_up_from_question_bank(ptrnode tree_base, fill_up* question, int index)
//{
//	ptrnode tree = tree_base;
//	tree = tree->firstchild->nextsibling;
//	int diff = question->difficulty;
//	if(diff == 0)
//	{
//		tree = tree->firstchild;
//	}
//	else if(diff == 1)
//	{
//		tree = tree->firstchild->nextsibling;
//	}
//	else if(diff == 2)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling;
//	}
//	else if(diff == 3)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling->nextsibling;
//	}
//	if(tree->firstchild != NULL)
//	{
//		if(tree->firstchild->element == index)
//		{
//			ptrnode temp = tree->firstchild;
//			tree->firstchild = tree->firstchild->nextsibling;
//			free(temp);
//		}
//		else
//		{
//			tree = tree->firstchild;
//			while(true)
//			{
//				if(tree->nextsibling == NULL)
//				{
//					printf("Not Found");
//					br;
//					break;
//				}
//				if(tree->nextsibling->element == index)
//				{
//					ptrnode temp = tree->nextsibling;
//					tree->nextsibling = tree->nextsibling->nextsibling;
//					free(temp);
//					break;
//				}
//				tree = tree->nextsibling;
//			}
//
//		}
//	}
//	else
//	{
//		printf("Such a question does not exist");
//		br;
//	}
//	return tree_base;
//}
//
//ptrnode delete_true_false_from_question_bank(ptrnode tree_base, true_false* question, int index)
//{
//	ptrnode tree = tree_base;
//	tree = tree->firstchild->nextsibling->nextsibling;
//	int diff = question->difficulty;
//	if(diff == 0)
//	{
//		tree = tree->firstchild;
//	}
//	else if(diff == 1)
//	{
//		tree = tree->firstchild->nextsibling;
//	}
//	else if(diff == 2)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling;
//	}
//	else if(diff == 3)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling->nextsibling;
//	}
//	if(tree->firstchild != NULL)
//	{
//		if(tree->firstchild->element == index)
//		{
//			ptrnode temp = tree->firstchild;
//			tree->firstchild = tree->firstchild->nextsibling;
//			free(temp);
//		}
//		else
//		{
//			tree = tree->firstchild;
//			while(true)
//			{
//				if(tree->nextsibling == NULL)
//				{
//					printf("Not Found");
//					br;
//					break;
//				}
//				if(tree->nextsibling->element == index)
//				{
//					ptrnode temp = tree->nextsibling;
//					tree->nextsibling = tree->nextsibling->nextsibling;
//					free(temp);
//					break;
//				}
//				tree = tree->nextsibling;
//			}
//
//		}
//	}
//	else
//	{
//		printf("Such a question does not exist");
//		br;
//	}
//	return tree_base;
//}
//
//ptrnode delete_short_answer_from_question_bank(ptrnode tree_base, short_answer* question, int index)
//{
//	ptrnode tree = tree_base;
//	tree = tree->firstchild->nextsibling->nextsibling->nextsibling;
//	int diff = question->difficulty;
//	if(diff == 0)
//	{
//		tree = tree->firstchild;
//	}
//	else if(diff == 1)
//	{
//		tree = tree->firstchild->nextsibling;
//	}
//	else if(diff == 2)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling;
//	}
//	else if(diff == 3)
//	{
//		tree = tree->firstchild->nextsibling->nextsibling->nextsibling;
//	}
//	if(tree->firstchild != NULL)
//	{
//		if(tree->firstchild->element == index)
//		{
//			ptrnode temp = tree->firstchild;
//			tree->firstchild = tree->firstchild->nextsibling;
//			free(temp);
//		}
//		else
//		{
//			tree = tree->firstchild;
//			while(true)
//			{
//				if(tree->nextsibling == NULL)
//				{
//					printf("Not Found");
//					br;
//					break;
//				}
//				if(tree->nextsibling->element == index)
//				{
//					ptrnode temp = tree->nextsibling;
//					tree->nextsibling = tree->nextsibling->nextsibling;
//					free(temp);
//					break;
//				}
//				tree = tree->nextsibling;
//			}
//
//		}
//	}
//	else
//	{
//		printf("Such a question does not exist");
//		br;
//	}
//	return tree_base;
//}
