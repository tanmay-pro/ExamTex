#include "../function_def.h"

void free_a(int index, int count)
{
	mcq *q = mcq_arr[index];
	fo(i, q->no_of_wrong)
	{
		free(q->wrong[i]);
	}
	fo(i, q->no_of_correct)
	{
		free(q->correct[i]);
	}
	free(q->correct);
	free(q->wrong);
	free(q);
}
void free_b(int index, int count)
{
	fill_up *q = fill_up_arr[index];
	free(q);
}

void free_c(int index, int count)
{
	true_false *q = true_false_arr[index];
	free(q);
}
void free_d(int index, int count)
{
	short_answer *q = short_answer_arr[index];
	free(q);
}

void free_bank(ptrnode tree)
{
	ptrnode free_at_end=tree;
	tree = tree->firstchild;
	ptrnode temp_arr[4],temp2_arr[4]; // Number of types of ques = 4
	temp_arr[0] = tree;
	temp_arr[1] = tree->nextsibling;
	temp_arr[2] = tree->nextsibling->nextsibling;
	temp_arr[3] = tree->nextsibling->nextsibling->nextsibling;
	temp2_arr[0] = tree;
	temp2_arr[1] = tree->nextsibling;
	temp2_arr[2] = tree->nextsibling->nextsibling;
	temp2_arr[3] = tree->nextsibling->nextsibling->nextsibling;
	fo(i, 4)
	{
		temp_arr[i] = temp_arr[i]->firstchild;
	}
	int question_number_count = 1;
	fo(i, 4)
	{
		ptrnode temporary_again[4],temporary_again2[4],temp1; // Number of diff = 4
		temporary_again[0] = temp_arr[i];
		temporary_again[1] = temp_arr[i]->nextsibling;
		temporary_again[2] = temp_arr[i]->nextsibling->nextsibling;
		temporary_again[3] = temp_arr[i]->nextsibling->nextsibling->nextsibling;
		temporary_again2[0] = temp_arr[i];
		temporary_again2[1] = temp_arr[i]->nextsibling;
		temporary_again2[2] = temp_arr[i]->nextsibling->nextsibling;
		temporary_again2[3] = temp_arr[i]->nextsibling->nextsibling->nextsibling;
		bool checker[4] = {true}; // Number of diff
		fo(j, 4)
		{
			if(temporary_again[j]->firstchild != NULL)
			{
				temporary_again[j] = temporary_again[j]->firstchild;
				checker[j] = true;
			}
			else
			{
				checker[j] = false;
			}
			if(checker[j] == true)
			{
				while(temporary_again[j] != NULL)
				{
					if(i == 0)
					{
						free_a(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					else if(i == 1)
					{
						free_b(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					else if(i == 2)
					{
						free_c(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					else if(i == 3)
					{
						free_d(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					temp1=temporary_again[j];
					temporary_again[j] = temporary_again[j]->nextsibling;
					free(temp1);
				}
			}
			free(temporary_again2[j]);
		}
		free(temp2_arr[i]);
	}
	free(free_at_end);
	free(mcq_arr);
	free(fill_up_arr);
	free(true_false_arr);
	free(short_answer_arr);
}