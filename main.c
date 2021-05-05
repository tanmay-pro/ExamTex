#include"function_def.h"

int main()
{
	ptrnode qb[100] = {NULL};
	int count = 0;
	int n;
	printf("Welcome to ExamTex");
	while(true)
	{
		br;
		br;
		printf("Select the option number:\n1.Add a new Question Bank\n2.Delete Existing Question Bank\n");
		printf("3.Add Question to Existing Question Bank\n4.Delete Question from existing Question Bank\n");
		printf("5.Print Existing Question Bank\n6.Generate Question Paper\n7.Exit\n");
		br;
		scanf("%d", &n);
		if(n == 7)
		{
			printf("Thank You\n");
			br;
			break;
		}
		else if(n == 1)
		{
			qb[count] = functionToCreateQuestionBank(qb[count]);
			printf("The Unique Question Bank id is = %d.", count);
			br;
			printf("Please remember this id for future use.");
			br;
			int type_number[4] = {0}; // 4 is number of types of Questions
			question_bank(type_number);
			insert_questions(qb[count], type_number);
			count++;
		}
		else if(n == 2)
		{
			functionToDeleteQuestionBank(qb);
		}
		else if(n == 3)
		{
			printf("Sorry but this feature has not yet been implemented");
			br;
		}
		else if(n == 4)
		{
			printf("Sorry but this feature has not yet been implemented");
			br;
		}
		else if(n == 5)
		{
			printf("Sorry but this feature has not yet been implemented");
			br;
		}
		else if(n == 6)
		{
			int input_id = 0;
			printf("Please enter the id of the Question Bank you want to generate the Question Paper from");
			br;
			scanf("%d", &input_id);
			read_question_paper(qb[input_id]);
		}
	}
  	return 0;
}