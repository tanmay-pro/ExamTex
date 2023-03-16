#include "../function_def.h"
#include "../main.h"

void print_a(int index, int count) // Function to print MCQ on terminal
{
	mcq *q = mcq_arr[index]; // Access question using index obtained with the help of array
	printf("%d) %s\n", count, q->text);
	printf("Incorrects:\n");
	fo(i, q->no_of_wrong)
	{
		printf("%c)%s\t", 65 + i, q->wrong[i]);
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
void print_b(int index, int count) // Function to print FIB Questions on terminal
{
	fill_up *q = fill_up_arr[index]; // Access question using index obtained with the help of array
	printf("%d) %s\n", count, q->text);
	printf("Ans:\n");
	printf("%s\n", q->correct);
	br;
}

void print_c(int index, int count) // Function to print True/False on terminal
{
	true_false *q = true_false_arr[index]; // Access question using index obtained with the help of array
	printf("%d) %s\n", count, q->text);
	printf("Ans:\n");
	printf("%c\n", q->correct);
	br;
}
void print_d(int index, int count) // Function to print short Answer on terminal
{
	short_answer *q = short_answer_arr[index]; // Access question using index obtained with the help of array
	printf("%d) %s\n", count, q->text);
	printf("Ans:\n");
	printf("%s\n", q->correct);
	br;
}

void print_bank(ptrnode tree)
{
	if(tree == NULL) // Error Handling
	{
		printf("Sorry but Bank does not exist");
		br;
		return;
	}
	tree = tree->firstchild;
	ptrnode temp_arr[4]; // Number of types of ques = 4
	temp_arr[0] = tree;
	temp_arr[1] = tree->nextsibling;
	temp_arr[2] = tree->nextsibling->nextsibling;
	temp_arr[3] = tree->nextsibling->nextsibling->nextsibling;  // temp array's each element points to a type of question
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
		// temporary again array's each element points to a difficulty level. Each of them are declared for each difficulty level
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
				checker[j] = false; // No node of the particular difficulty and type exists
			}
			if (checker[j] == true) // Is atleast one node of a particular difficulty and type exists, then while loop iterates over all of them
			{
				while (temporary_again[j] != NULL)
				{
					if (i == 0)
					{
						print_a(temporary_again[j]->element, question_number_count); // Calls Function to print MCQ on terminal
						question_number_count++;
					}
					else if (i == 1)
					{
						print_b(temporary_again[j]->element, question_number_count); // Calls Function to print Fill in the blanks on terminal
						question_number_count++;
					}
					else if (i == 2)
					{
						print_c(temporary_again[j]->element, question_number_count); // Calls Function to print True false on terminal
						question_number_count++;
					}
					else if (i == 3)
					{
						print_d(temporary_again[j]->element, question_number_count); // Calls Function to print Short Answer on terminal
						question_number_count++;
					}
					temporary_again[j] = temporary_again[j]->nextsibling;
				}
			}
		}
	}
}