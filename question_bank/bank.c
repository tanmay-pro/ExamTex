#include "question.h"
#include "../function_def.h"

void push(struct stack *ps, char x)
{
    if (ps->top == 100001 - 1)
    {
        printf("Error: stack overflown");
        getchar();
        exit(0);
    }
    else
    {
        ps->top += 1;
        char top = ps->top;
        ps->items[top] = x;
    }
}

void pop(struct stack *ps)
{
    char temp;
    if (ps->top == -1)
    {
        printf("Error: stack underflow n");
        getchar();
        exit(0);
    }
    else
    {
        char top = ps->top;
        temp = ps->items[top];
        ps->top -= 1;
    }
}

bool isEmpty(struct stack *ps)
{
    return (ps->top == -1) ? true : false;
}

mcq insert_question(stack s1, char pre[], char post[], double post_num, char post_line[])
{
    mcq question;
    char post_options[4][20];
    char post_correct[20];
    char x, y, z;
    y = getchar();
    while (y != '{')
        y = getchar();
    push(&s1, y);
    scanf("%s", pre);
    getchar();
    getchar();
    scanf("%[^}]s", post);
    z = getchar();
    if (z == '}')
    {
	    pop(&s1);
    }
    y = getchar();
    while (y != '{')
        y = getchar();
    push(&s1, y);
    scanf("%s", pre);
    getchar();
    getchar();
    scanf("%lf", &post_num);
    z = getchar();
    if (z == '}')
    {
	    pop(&s1);
    }
    question.difficulty = post_num;
    y = getchar();
    while (y != '{')
    {
	    y = getchar();
    }
    push(&s1, y);
    scanf("%s", pre);
    getchar();
    getchar();
    scanf("%[^}]s", post_line);
    scanf("%c", &z);
    if (z == '}')
    {
	    pop(&s1);
    }
    strcpy(question.text, post_line);
	y = getchar();
    while (y != '{')
    {
	    y = getchar();
    }
    push(&s1, y);
    scanf("%s", pre);
    getchar();
    getchar();
    scanf("%[^,]s", post_options[0]);
    getchar();
    scanf("%[^,]s", post_options[1]);
    getchar();
    scanf("%[^,]s", post_options[2]);
    getchar();
    scanf("%[^}]s", post_options[3]);
    scanf("%c", &z);
    if (z == '}')
    {
	    pop(&s1);
    }
    for (int i = 0; i < 4; i++)
    {
	    strcpy(question.options[i], post_options[i]);
    }
    y = getchar();
    while (y != '{')
    {
	    y = getchar();
    }
    push(&s1, y);
    scanf("%s", pre);
    getchar();
    getchar();
    scanf("%[^}]s", post_correct);
    z = getchar();
    z = getchar();
    if (z == '}')
    {
	    pop(&s1);
    }
    strcpy(question.correct, post_correct);
    return question;
}

void function_for_inserting_question(mcq* arr[])
{
    char x, y, z;
    x = getchar();
    char pre[10], post[10];
    double post_num;
    char post_line[100];
    struct stack s1;
    int i = 0;
    s1.top = -1;
    mcq questions[10];
    while (x != EOF)
    {
        questions[i] = insert_question(s1, pre, post, post_num, post_line);
        arr[i] = &questions[i];
        i++;
        x = getchar();
    }
    for (i = 0; i < 4; i++)
    {
        printf("%d %s\n", i, arr[i]->options[3]);
    }
}