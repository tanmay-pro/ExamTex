#include"../function_def.h"

ptrnode functionToCreateQuestionBank(ptrnode qb1)
{
	int type_of_question[] = {0, 1, 2, 3};
	// mcq = 0
	// fill in the blanks = 1
	// true/false = 2
	// short Answer = 3
	int number_of_types = 4;
	int range_of_diff[] = {0, 1, 2, 3};
	// Easy = 0
	// Medium = 1
	// Difficult = 2
	// Dhasu = 3
	int number_of_diff = 4;
	qb1 = make_node(-1); // Header Node
	ptrnode base = qb1;
	qb1 = insert_below(qb1, 0); // Inserting type of Question
	qb1 = qb1->firstchild;
	qb1 = insert_below(qb1, 0);
	fo(i, number_of_types - 1)
	{
		qb1 = insert_horizontally(qb1, type_of_question[i + 1]);
	}
	ptrnode temp = qb1;
	fo(i, number_of_types - 1)
	{
		temp = temp->nextsibling;
		temp = insert_below(temp, 0);
	}
	ptrnode for_inserting_diff[number_of_types - 1];
	fo(i, number_of_types - 1)
	{
		for_inserting_diff[i] = qb1;
		fo(j, i + 1)
		{
			for_inserting_diff[i] = for_inserting_diff[i]->nextsibling;
		}
	}
	qb1 = qb1->firstchild;
	fo(k, number_of_diff - 1)
	{
		qb1 = insert_horizontally(qb1, range_of_diff[k + 1]);
	}
	fo(i, number_of_types - 1)
	{
		for_inserting_diff[i] = for_inserting_diff[i]->firstchild;
		fo(k, number_of_diff - 1)
		{
			for_inserting_diff[i] = insert_horizontally(for_inserting_diff[i], range_of_diff[k + 1]);
		}
	}
	return base;
}

void insert_questions(ptrnode tree, int type_number[], const int filled_val[])
{
	int i = filled_val[0] - 1;
	while(true)
	{
		if(type_number[0] == 0)
		{
			break;
		}
		tree = add_mcq_question_to_bank(tree, mcq_arr[i], i);
		i--;
		type_number[0]--;
	}
	i = filled_val[1] - 1;
	while(true)
	{
		if(type_number[1] == 0)
		{
			break;
		}
		tree = add_fill_up_question_to_bank(tree, fill_up_arr[i], i);
		i--;
		type_number[1]--;
	}
	i = filled_val[2] - 1;
	while(true)
	{
		if(type_number[2] == 0)
		{
			break;
		}
		tree = add_true_false_question_to_bank(tree, true_false_arr[i], i);
		i--;
		type_number[2]--;
	}
	i = filled_val[3] - 1;
	while(true)
	{
		if(type_number[3] == 0)
		{
			break;
		}
		tree = add_short_answer_question_to_bank(tree, short_answer_arr[i], i);
		i--;
		type_number[3]--;
	}
}

