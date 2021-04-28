#include"function_def.h"
#include"Question_Bank/question.h"

int main()
{
	ptrnode qb1 = NULL;
	functionToCreateQuestionBank(qb1);
	question_bank();
	//Call function that inserts index of questions in tree
	read_question_paper(qb1);
  	return 0;
}