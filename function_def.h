#ifndef FUNC_H_
#define FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include"question_bank/question.h"
#include"question_bank/tree_struct.h"

#define ll long long
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

ptrnode functionToCreateQuestionBank(ptrnode qb1);
ptrnode make_node(elementType e);
ptrnode insert_below(ptrnode tree, elementType e);
ptrnode insert_horizontally(ptrnode tree, elementType e);


void push(stack *ps, char x);
void pop(stack *ps);
bool isEmpty(stack *ps);
double input_difficulty(stack s1,char *pre);
char* input_text(stack s1,char *pre,char *post_line,char *buffer);
mcq* insert_mcq(stack s1);
void question_bank( );

//
void read_question_paper(qb1);

#endif
