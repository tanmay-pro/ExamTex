#include"function_def.h"

int main()
{
	question_bank();
	ptrnode qb1 = NULL;
	functionToCreateQuestionBank(qb1);
	read_question_paper(qb1);
  return 0;
}