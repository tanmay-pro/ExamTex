#ifndef FUNC_H_
#define FUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>

#include"Question_Bank/question_structs.h"
#include"Question_Bank/tree_node_struct.h"
#include"Question_Paper/question_paper.h"

#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define TYPES 4
#define DIFFICULTY_LEVELS 4
#define MAX 100

int available[MAX][TYPES][DIFFICULTY_LEVELS];

ptrnode make_node(elementType e);
ptrnode insert_below(ptrnode tree, elementType e);
ptrnode insert_horizontally(ptrnode tree, elementType e);

ptrnode add_mcq_question_to_bank(ptrnode tree, mcq* question, int index);
ptrnode add_fill_up_question_to_bank(ptrnode tree, fill_up* question, int index);
ptrnode add_true_false_question_to_bank(ptrnode tree, true_false* question, int index);
ptrnode add_short_answer_question_to_bank(ptrnode tree, short_answer* question, int index);

question add_question_type();

void push(stack *ps, char x);
void pop(stack *ps);

int input_difficulty(stack s1,char *pre);
char* input_text(stack s1,char *pre,char *post_line,char *buffer);
void question_bank(int bank_id, int type_number[], int filled_val[], int realloc_ct[]);

mcq* insert_mcq(stack s1);
fill_up *insert_fill_up(stack s1);
true_false *insert_true_false(stack s1);
short_answer *insert_short_answer(stack s1);

void read_question_paper(int bank_id, ptrnode qb1, int number_of_files);
void sampler(int bank_id, ptrnode qb, question Q, FILE* paper_ptr);

void printer_mcq(FILE *file, mcq *q);
void printer_fill_up(FILE *file, fill_up *q);
void printer_true_false(FILE *file, true_false *q);
void printer_short_answer(FILE *file, short_answer *q);
int *generate_randoms(int available, int n);

mcq **mcq_arr;
fill_up **fill_up_arr;
true_false **true_false_arr;
short_answer **short_answer_arr;

void insert_questions(ptrnode tree, int type_number[], const int filled_val[]);
ptrnode functionToCreateQuestionBank(ptrnode qb1);
void functionToDeleteQuestionBank(ptrnode qb[]);

void print_bank(ptrnode tree);
void print_a(int index, int count);
void print_b(int index, int count);
void print_c(int index, int count);
void print_d(int index, int count);

void free_bank(ptrnode tree);
void free_a(int index, int count);
void free_b(int index, int count);
void free_c(int index, int count);
void free_d(int index, int count);

FILE *fp, *fp2;
#endif
