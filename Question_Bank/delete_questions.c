#include "../function_def.h"

void functionToDeleteQuestionBank(ptrnode qb[])
{
	int input_id = 0;
	printf("Please Enter the id of the Question bank you want to Delete");
	br;
	scanf("%d", &input_id);
	ptrnode temp = qb[input_id];
	free(temp);
	qb[input_id] = NULL;
}