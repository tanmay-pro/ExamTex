#include "../function_def.h"

void print_a(int index, int count)
{
	mcq *q = mcq_arr[index];
	printf("%d) %s\n", count, q->text);
	printf("Options:\n");
	fo(i, q->no_of_options)
	{
		printf("%c)%s\t", 65 + i, q->options[i]);
	}
	br;
	printf("Answers:\n");
	fo(i, q->no_of_correct)
	{
		printf("%c)%s\t", 65 + i, q->correct[i]);
	}
	br;
	br;
}
void print_b(int index, int count)
{
	fill_up *q = fill_up_arr[index];
	printf("%d) %s\n", count, q->text);
	printf("Ans:\n");
	printf("%s\n", q->correct);
	br;
}

void print_c(int index, int count)
{
	true_false *q = true_false_arr[index];
	printf("%d) %s\n", count, q->text);
	printf("Ans:\n");
	printf("%c\n", q->correct);
	br;
}
void print_d(int index, int count)
{
	short_answer *q = short_answer_arr[index];
	printf("%d) %s\n", count, q->text);
	printf("Ans:\n");
	printf("%s\n", q->correct);
	br;
}

void print_bank(ptrnode tree)
{
	tree = tree->firstchild;
	ptrnode temp_arr[4]; // Number of types of ques = 4
	temp_arr[0] = tree;
	temp_arr[1] = tree->nextsibling;
	temp_arr[2] = tree->nextsibling->nextsibling;
	temp_arr[3] = tree->nextsibling->nextsibling->nextsibling;
	fo(i, 4)
	{
		temp_arr[i] = temp_arr[i]->firstchild;
	}
	int question_number_count = 1;
	fo(i, 4)
	{
		ptrnode temporary_again[4]; // Number of diff = 4
		temporary_again[0] = temp_arr[i];
		temporary_again[1] = temp_arr[i]->nextsibling;
		temporary_again[2] = temp_arr[i]->nextsibling->nextsibling;
		temporary_again[3] = temp_arr[i]->nextsibling->nextsibling->nextsibling;
		bool checker[4] = {true}; // Number of diff
		fo(j, 4)
		{
			if (temporary_again[j]->firstchild != NULL)
			{
				temporary_again[j] = temporary_again[j]->firstchild;
				checker[j] = true;
			}
			else
			{
				checker[j] = false;
			}
			if (checker[j] == true)
			{
				while (temporary_again[j] != NULL)
				{
					if (i == 0)
					{
						print_a(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					else if (i == 1)
					{
						print_b(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					else if (i == 2)
					{
						print_c(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					else if (i == 3)
					{
						print_d(temporary_again[j]->element, question_number_count);
						question_number_count++;
					}
					temporary_again[j] = temporary_again[j]->nextsibling;
				}
			}
		}
	}
}