#include"function_def.h"

int main()
{
	ptrnode qb[100] = {NULL};
	mcq_arr = (mcq **)malloc(10*sizeof(mcq *));
	fill_up_arr = (fill_up **)malloc(10*sizeof(fill_up *));
	true_false_arr = (true_false **)malloc(10*sizeof(true_false *));
	short_answer_arr = (short_answer **)malloc(10*sizeof(short_answer *));
	int count = -1;
	int n;
	int filled_val[4] = {0};
	printf("Welcome to ExamTex");
	while(true)
	{
		br;
		br;
		printf("Select the option number:\n1.Add a new Question Bank\n2.Delete Existing Question Bank\n");
		printf("3.Add Questions to Existing Question Bank\n4.Delete Question from existing Question Bank\n");
		printf("5.Print Existing Question Bank\n6.Generate Question Paper\n7.Exit\n");
		br;
		scanf("%d", &n);
		if(n == 7)
		{
			printf("Thank You!!\n");
			br;
			break;
		}
		else if(n == 1)
		{
			count++;
			qb[count] = functionToCreateQuestionBank(qb[count]);
			printf("The Unique Question Bank id is = %d.", count);
			br;
			printf("Please remember this id for future use.");
			br;
			int type_number[4] = {0}; // 4 is number of types of Questions
			question_bank(type_number, filled_val);
			insert_questions(qb[count], type_number, filled_val);
		}
		else if(n == 2)
		{
			functionToDeleteQuestionBank(qb);
		}
		else if(n == 3)
		{
			int input_id = 0;
			printf("Please enter the id of the Question Bank you want to Add Questions to");
			br;
			scanf("%d", &input_id);
			int type_number[4] = {0}; // 4 is number of types of Questions
			question_bank(type_number, filled_val);
			insert_questions(qb[input_id], type_number, filled_val); 
		}
		else if(n == 4)
		{
			printf("Sorry but this feature has not yet been implemented");
			br;
		}
		else if(n == 5)
		{
			int input_id = 0;
			printf("Please enter the id of the Question Bank you want to print");
			br;
			scanf("%d", &input_id);
			print_bank(qb[input_id]);
		}
		else if(n == 6)
		{
			int input_id = 0;
			printf("Please enter the id of the Question Bank you want to generate the Question Paper from");
			br;
			scanf("%d", &input_id);
			int number_of_files;
			printf("Please Enter the number of files you want to Generate");
			br;
			scanf("%d", &number_of_files);
			read_question_paper(qb[input_id], number_of_files);
		}
	}
  	return 0;
}