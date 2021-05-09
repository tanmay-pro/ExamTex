#include "../function_def.h"

void functionToDeleteQuestionBank(ptrnode qb[])
{
	int input_id = 0;
	printf("Please Enter the id of the Question bank you want to Delete");
	br;
	scanf("%d", &input_id); // Obtains input id
	ptrnode temp = qb[input_id];
	free_bank(temp); //Frees Memory
	qb[input_id] = NULL; // Makes the array element NULL to indicate deletion of question bank
}