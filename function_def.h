#ifndef FUNC_H_
#define FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include<stdio_ext.h>
#include <time.h>

#include"Question_Bank/question_structs.h"
#include"Question_Bank/tree_node_struct.h"
#include"Question_Paper/question_paper.h"

#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

ptrnode make_node(elementType e);
ptrnode insert_below(ptrnode tree, elementType e);
ptrnode insert_horizontally(ptrnode tree, elementType e);

ptrnode add_mcq_question_to_bank(ptrnode tree, mcq* question, int index);
ptrnode add_fill_up_question_to_bank(ptrnode tree, fill_up* question, int index);
ptrnode add_true_false_question_to_bank(ptrnode tree, true_false* question, int index);
ptrnode add_short_answer_question_to_bank(ptrnode tree, short_answer* question, int index);

ptrnode delete_mcq_from_question_bank(ptrnode tree, mcq* question, int index);

struct questions add_question_type();

void push(stack *ps, char x);
void pop(stack *ps);

double input_difficulty(stack s1,char *pre);
char* input_text(stack s1,char *pre,char *post_line,char *buffer);
void question_bank(int type_number[]);

mcq* insert_mcq(stack s1);
fill_up *insert_fill_up(stack s1);

void read_question_paper(ptrnode qb1);
void sampler(ptrnode qb, question Q);

void printer_mcq(FILE *file, mcq *q);
void printer_fill_up(FILE *file, fill_up *q);
int *generate_randoms(int available, int n);

mcq *mcq_arr[10];
fill_up *fill_up_arr[10];
true_false *true_false_arr[10];
short_answer *short_answer_arr[10];

void insert_questions(ptrnode tree, int type_number[]);
ptrnode functionToCreateQuestionBank(ptrnode qb1);
void functionToDeleteQuestionBank(ptrnode qb[]);
FILE *fp, *fp2;
#endif
