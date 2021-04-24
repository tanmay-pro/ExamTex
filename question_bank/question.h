#ifndef QUESTION_H_
#define QUESTION_H_
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
#endif