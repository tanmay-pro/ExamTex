#ifndef FUNC_H_
#define FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>


#define ll long long
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

ptrnode functionToCreateQuestionBank(ptrnode qb1);
ptrnode make_node(elementType e);
ptrnode insert_below(ptrnode tree, elementType e);
ptrnode insert_horizontally(ptrnode tree, elementType e);

void push(struct stack *ps, char x);

void pop(struct stack *ps);

bool isEmpty(struct stack *ps);

mcq insert_question(stack s1,char pre[],char post[],double post_num,char post_line[]);
#endif
