#include "question.h"
#include "../function_def.h"

void push(stack *ps, char x)
{
    if (ps->top == 100001 - 1) // This can never be equal. Needs to be changed.
    {
        printf("Error: stack overflown");
        getchar();
        exit(0);
    } // Check This
    else
    {
        ps->top += 1;
        int top_val = ps->top;
        ps->items[top_val] = x;
    }
}

void pop(stack *ps)
{
    if (ps->top == -1)
    {
        printf("Error: stack underflow n");
        getchar();
        exit(0);
    }
    else
    {
        ps->top -= 1;
    }
}

double input_difficulty(stack s1, char *pre)
{
    char y, z;
    double post_num;
    y = (char)getchar();
    while (y != '{')
    {
        y = (char)getchar();
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
    getchar();
    scanf("%lf", &post_num);
    z = (char)getchar();
    if (z == '}')
    {
        pop(&s1);
    }
    return post_num;
}

char *input_text(stack s1, char *pre, char *post_line, char *buffer)
{
    char y, z;
    y = (char)getchar();
    while (y != '{')
    {
        y = (char)getchar();
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
    getchar();
    post_line[0] = (char)getchar();
    while (post_line[0] == ' ')
    {
        post_line[0] = (char)getchar();
    }
    post_line[1] = '\0';
    scanf("%[^}]s", buffer);
    strcat(post_line, buffer);
    scanf("%c", &z);
    if (z == '}')
    {
        pop(&s1);
    }
    return post_line;
}

mcq *insert_mcq(stack s1)
{
    mcq *question;
    question = (mcq *)malloc(sizeof(mcq));
    char post_options[4][20];
    char post_correct[20], pre[10], post_line[1000];
    char y, z;
    char buffer[1000];

    question->difficulty = input_difficulty(s1, pre);
    strcpy(question->text, input_text(s1, pre, post_line, buffer));

    y = (char)getchar();
    while (y != '{')
    {
        y = (char)getchar();
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
    getchar();
    for (int i = 0; i < 3; i++)
    {
        post_options[i][0] = (char)getchar();
        while (post_options[i][0] == ' ')
        {
            post_options[i][0] = (char)getchar();
        }
        post_options[i][1] = '\0';
        scanf("%[^,]s", buffer);
        strcat(post_options[i], buffer);
        getchar();
    }

    post_options[3][0] = (char)getchar();
    while (post_options[3][0] == ' ')
    {
        post_options[3][0] = (char)getchar();
    }
    post_options[3][1] = '\0';
    scanf("%[^}]s", buffer);
    strcat(post_options[3], buffer);
    scanf("%c", &z);
    if (z == '}')
    {
        pop(&s1);
    }
    for (int i = 0; i < 4; i++)
    {
        strcpy(question->options[i], post_options[i]);
    }
    y = (char)getchar();
    while (y != '{')
    {
        y = (char)getchar();
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
    getchar();
    post_correct[0] = (char)getchar();
    while (post_correct[0] == ' ')
    {
        post_correct[0] = (char)getchar();
    }
    post_correct[1] = '\0';
    scanf("%[^}]s", buffer);
    strcat(post_correct, buffer);
    z = (char)getchar();
    if (z == '}')
    {
        pop(&s1);
    }
    strcpy(question->correct, post_correct);
    return question;
}

fill_up *insert_fill_up(stack s1)
{
    fill_up *question;
    question = (fill_up *)malloc(sizeof(fill_up));
    char post_correct[20], pre[10], post_line[1000];
    char y, z;
    char buffer[1000];
    question->difficulty = input_difficulty(s1, pre);
    strcpy(question->text, input_text(s1, pre, post_line, buffer));
    y = (char)getchar();
    while (y != '{')
    {
        y = (char)getchar();
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
    getchar();
    post_correct[0] = (char)getchar();
    while (post_correct[0] == ' ')
    {
        post_correct[0] = (char)getchar();
    }
    post_correct[1] = '\0';
    scanf("%[^}]s", buffer);
    strcat(post_correct, buffer);
    z = (char)getchar();
    if (z == '}')
    {
        pop(&s1);
    }
    strcpy(question->correct, post_correct);
    return question;
}
void question_bank()
{
    char x, y, z;
    x = (char)getchar();
    char pre[10], post[10];
    struct stack s1;
    int i, mcq_index = 0, fill_up_index = 0;
    s1.top = -1;

    while (x != EOF)
    {
        y = (char)getchar();
        while (y != '{')
        {
            y = (char)getchar();
        }
        push(&s1, y);
        scanf("%[^=]s", pre);
        getchar();
        scanf("%[^}]s", post);
        z = (char)getchar();
        if (z == '}')
        {
            pop(&s1);
        }
        if (post[0] == 'm')
        {
            mcq_arr[mcq_index] = insert_mcq(s1);
            mcq_index++;
        }
        else if (post[0] == 'f')
        {
            fill_up_arr[fill_up_index] = insert_fill_up(s1);
            fill_up_index++;
        }
        x = (char)getchar();
    }
    // Debugging start
//    for (i = 0; i < 4; i++)
//    {
//        printf("%s\n", mcq_arr[i]->text);
//        printf("%lf\n", mcq_arr[i]->difficulty);
//        printf("%s\n", mcq_arr[i]->options[0]);
//        printf("%s\n", mcq_arr[i]->options[1]);
//        printf("%s\n", mcq_arr[i]->options[2]);
//        printf("%s\n", mcq_arr[i]->options[3]);
//        printf("%s\n", mcq_arr[i]->correct);
//    }
//
//    for (i = 0; i < 4; i++)
//    {
//        free(mcq_arr[i]);
//    }
//
//    for (i = 0; i < 1; i++)
//    {
//        printf("%s\n", fill_up_arr[i]->text);
//        printf("%lf\n", fill_up_arr[i]->difficulty);
//        printf("%s\n", fill_up_arr[i]->correct);
//    }
//    for (i = 0; i < 1; i++)
//    {
//        free(fill_up_arr[i]);
//    }
	// Debugging end
}