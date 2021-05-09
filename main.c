#include"function_def.h"

int main()
{
	ptrnode qb[100] = {NULL}; // Pointers to header nodes of trees rendering Question banks
	mcq_arr = (mcq **)malloc(10*sizeof(mcq *));
	fill_up_arr = (fill_up **)malloc(10*sizeof(fill_up *));
	true_false_arr = (true_false **)malloc(10*sizeof(true_false *));
	short_answer_arr = (short_answer **)malloc(10*sizeof(short_answer *));
	// Above are the "question type" arrays which store the pointers to the memory assigned to the questions of given datatype
	int realloc_ct[4]={0}; // A cumulative count for performing Reallocation of Memory
	int count = -1;
	int n;
	int filled_val[4] = {0}; // This maintains the size of the "question type" arrays
	printf("Welcome to ExamTex");
	while(true) // Menu Driven programme
	{
		br;
		br;
		printf("Select the option number:\n1.Add a new Question Bank\n2.Delete Existing Question Bank\n");
		printf("3.Add Questions to Existing Question Bank\n");
		printf("4.Print Existing Question Bank\n5.Generate Question Paper\n6.Exit\n");
		br;
		scanf("%d", &n);
		if(n == 6) // Exiting Condition
		{
			printf("Thank You!!\n");
			br;
			int i=0;
			while(qb[i]!=NULL) // Freeing the memory since no use after this
			{
				free_bank(qb[i]);
				i++;
			}
			break;
		}
		else if(n == 1) // Generate New Question bank
		{
			count++;
			qb[count] = functionToCreateQuestionBank(qb[count]); // This makes the default nodes of the question bank
			printf("The Unique Question Bank id is = %d.", count);
			br;
			printf("Please remember this id for future use.");
			br;
			int type_number[4] = {0}; // 4 is number of types of Questions
			question_bank(type_number, filled_val,realloc_ct); // This takes input file from user and converts the input to store questions in form of structs
			insert_questions(qb[count], type_number, filled_val); // This is for inserting indexes of the "question type" array in the tree
		}
		else if(n == 2)
		{
			functionToDeleteQuestionBank(qb); // This erases the memory associated with a particular bank
		}
		else if(n == 3) // This basically appends one input bank file to another. Its working is very similar to generating a new question bank. Except that now changes are made to an already existing bank
		{
			int input_id = 0;
			printf("Please enter the id of the Question Bank you want to Add Questions to");
			br;
			scanf("%d", &input_id);
			if(input_id > count) // Error handling
			{
				printf("Such a question bank does not exist\n");
				br;
				continue;
			}
			else
			{
				int type_number[4] = {0}; // 4 is number of types of Questions
				question_bank(type_number, filled_val,realloc_ct); // same as for n==1
				insert_questions(qb[input_id], type_number, filled_val); // same as for n==1
			}
		}
		else if(n == 4) // This prints an already existing question bank
		{
			int input_id = 0;
			printf("Please enter the id of the Question Bank you want to print");
			br;
			scanf("%d", &input_id);
			if(input_id > count) // Error handling
			{
				printf("Such a question bank does not exist\n");
				br;
				continue;
			}
			else
			{
				print_bank(qb[input_id]); // This line calls printer bank function
			}
		}
		else if(n == 5)
		{
			int input_id = 0;
			printf("Please enter the id of the Question Bank you want to generate the Question Paper from");
			br;
			scanf("%d", &input_id);
			int number_of_files;
			printf("Please Enter the number of files you want to Generate");
			br;
			scanf("%d", &number_of_files);
			if(input_id > count) // Error handling
			{
				printf("Such a question bank does not exist\n");
				br;
				continue;
			}
			else
			{
				if(number_of_files > 0) // Error Handling
				{
					read_question_paper(qb[input_id], number_of_files); // This line calls the function which reads the question paper input
				}
				else
				{
					printf("You cannot Generate the number of files = %d", number_of_files);
				}
			}
		}
		else
		{
			printf("Invalid Input. Please Enter Again!!"); // Error Handling
			br;
		}
	}
  	return 0;
}