#include "../function_def.h"

ptrnode functionToCreateQuestionBank(ptrnode qb1) // This function creates the default nodes of tree (of difficulty levels and type of question levels)
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
	qb1 = insert_below(qb1, 0);
	qb1 = qb1->firstchild;
	qb1 = insert_below(qb1, 0);
	fo(i, number_of_types - 1)
	{
		qb1 = insert_horizontally(qb1, type_of_question[i + 1]);
	}   // Inserting type of Question
	ptrnode temp = qb1;
	fo(i, number_of_types - 1)
	{
		temp = temp->nextsibling;
		temp = insert_below(temp, 0);
	}
	ptrnode for_inserting_diff[number_of_types - 1]; //Creating pointers to handle difficulty level nodes
	fo(i, number_of_types - 1)
	{
		for_inserting_diff[i] = qb1;
		fo(j, i + 1)
		{
			for_inserting_diff[i] = for_inserting_diff[i]->nextsibling;
		}
	}
	qb1 = qb1->firstchild; // Going to the next level of tree to implement diff levels
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
	} // Inserting the types of difficulties (0,1,2,3)  for each type of question
	return base;
}

void insert_questions(ptrnode tree, int type_number[], const int filled_val[])
{
	int i = filled_val[0] - 1; // Filled value[0] contains the (final index + 1) to which the mcq array has been filled
	while (true)
	{
		if (type_number[0] == 0) // Type number[0] contains the number of mcq questions to be added in mcq_arr
		{
			break;
		}
		tree = add_mcq_question_to_bank(tree, mcq_arr[i], i);
		i--;
		type_number[0]--; // Decrementing Counter
	}
	i = filled_val[1] - 1; // Filled value[1] contains the (final index + 1) to which the Fill in the blanks array has been filled
	while (true)
	{
		if (type_number[1] == 0) // Type number[1] contains the number of Fill in the blanks questions to be added in fill_up_arr
		{
			break;
		}
		tree = add_fill_up_question_to_bank(tree, fill_up_arr[i], i);
		i--;
		type_number[1]--; // Decrementing Counter
	}
	i = filled_val[2] - 1; // Filled value[2] contains the (final index + 1) to which the True/False array has been filled
	while (true)
	{
		if (type_number[2] == 0) // Type number[2] contains the number of True/False questions to be added in true_false_arr
		{
			break;
		}
		tree = add_true_false_question_to_bank(tree, true_false_arr[i], i);
		i--;
		type_number[2]--; // Decrementing Counter
	}
	i = filled_val[3] - 1; // Filled value[3] contains the (final index + 1) to which the Short Answer array has been filled
	while (true)
	{
		if (type_number[3] == 0) // Type number[0] contains the number of Short Answer questions to be added in short_answer_arr
		{
			break;
		}
		tree = add_short_answer_question_to_bank(tree, short_answer_arr[i], i);
		i--;
		type_number[3]--; // Decrementing Counter
	}
}
