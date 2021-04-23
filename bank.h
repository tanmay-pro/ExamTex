#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack
{
    char top;
    char items[100001];
} stack;

typedef struct mcq
{
    char text[100];
    float difficulty;
    char options[4][20];
    char correct[20];
} mcq;
void push(struct stack *ps, char x);

void pop(struct stack *ps);

bool isEmpty(struct stack *ps);

mcq insert_question(stack s1,char pre[],char post[],double post_num,char post_line[]);
