#include "bank.h"

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

mcq insert_question(stack s1,char pre[],char post[],double post_num,char post_line[])
{
    mcq question;
    char post_options[20][4];
    char post_correct[20];
    char x,y,z;
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
            pop(&s1);

        // if (isEmpty(&s1))
        //     printf("vjdb\n");// to check stack empty

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
            pop(&s1);
        //printf("%s %0.1lf\n", pre, post_num);
        question.difficulty=post_num;

        // if (isEmpty(&s1))
        //     printf("vjdb\n");

        y = getchar();
        while (y != '{')
            y = getchar();
        push(&s1, y);
        scanf("%s", pre);
        getchar();
        getchar();
        scanf("%[^}]s", post_line);  
        scanf("%c",&z);
        if (z == '}')
            pop(&s1);
        //printf("%s %s\n", pre, post_line);
        strcpy(question.text,post_line);

        // if (isEmpty(&s1))
        //     printf("vjdb\n");
        y = getchar();
        while (y != '{')
            y = getchar();
        push(&s1, y);
        scanf("%s", pre);
        getchar();
        getchar();
        scanf("%[^,]s", post_options[0]);  
        scanf("%[^,]s", post_options[1]);
        scanf("%[^,]s", post_options[2]);
        scanf("%[^}]s", post_options[3]);
        scanf("%c",&z);
        if (z == '}')
            pop(&s1);
        //printf("%s %s\n", pre, post_line);
        for(int i=0;i<4;i++)
         strcpy(question.options[i],post_options[i]);

        // if (isEmpty(&s1))
        //     printf("vjdb\n");
        y = getchar();
        while (y != '{')
            y = getchar();
        push(&s1, y);
        scanf("%s", pre);
        getchar();
        getchar();
        scanf("%[^}]s", post_correct);  
        z = getchar();
        z = getchar();
        if (z == '}')
            pop(&s1);
        //printf("%s %0.1lf\n", pre, post_num);
        strcpy(question.correct,post_correct);



    return question;
}
