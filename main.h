#ifndef MAIN_H_
#define MAIN_H_

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

#define TYPES 4
#define DIFFICULTY_LEVELS 4
#define MAX 100 

extern int available[MAX][TYPES][DIFFICULTY_LEVELS];
extern FILE *fp, *fp2;
extern mcq **mcq_arr;
extern fill_up **fill_up_arr;
extern true_false **true_false_arr;
extern short_answer **short_answer_arr;

#endif