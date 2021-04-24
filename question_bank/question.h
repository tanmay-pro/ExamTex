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
    char text[1000];
    double difficulty;
    char options[4][20];
    char correct[20];
} mcq;

typedef struct fill_up
{
    char text[1000];
    double difficulty;
    char correct[20];
} fill_up;