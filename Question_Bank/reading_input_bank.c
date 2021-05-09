#include "question_structs.h"
#include "../function_def.h"

void push(stack *ps, char x)
{
    ps->top += 1;
    int top_val = ps->top;
    ps->items[top_val] = x;
}

void pop(stack *ps)
{
    ps->top -= 1;
}

void fix(char s[])
{
    int x = strlen(s);
    int i;
    for (i = x - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            s[i + 1] = '\0';
            break;
        }
    }
}

int input_difficulty(stack s1, char *pre)
{
    char y, z, ch;
    int post_num;
    fscanf(fp, "%c", &y);
    while (y != '{')
    {
        fscanf(fp, "%c", &y);
    }
    push(&s1, y);
    fscanf(fp, "%[^=]s", pre);
    fix(pre);
    fscanf(fp, "%c", &ch);
    fscanf(fp, "%d", &post_num);
    fscanf(fp, "%c", &z);
    if (z == '}')
    {
        pop(&s1);
    }
    return post_num;
}

char *input_text(stack s1, char *pre, char *post_line, char *buffer)
{
    char y, z, ch;
    fscanf(fp, "%c", &y);
    while (y != '{')
    {
        fscanf(fp, "%c", &y);
    }
    push(&s1, y);
    fscanf(fp, "%[^=]s", pre);
    fix(pre);
    fscanf(fp, "%c", &ch);
    fscanf(fp, "%c", &post_line[0]);
    while (post_line[0] == ' ')
    {
        fscanf(fp, "%c", &post_line[0]);
    }
    fscanf(fp, "%[^}]s", post_line + 1);
    fix(post_line);
    fscanf(fp, "%c", &z);
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

    char **post_wrong, **post_correct;
    post_wrong=(char**)malloc(4*sizeof(char*));
    post_correct=(char**)malloc(sizeof(char*));

    char pre[20], post_line[1000];

    char y, z,x,p, ch;
    int ct1=0,ct2=0;
    char buffer[1000];

    question->difficulty = input_difficulty(s1, pre);
    strcpy(question->text, input_text(s1, pre, post_line, buffer));

    fscanf(fp, "%c", &y);
    while (y != '{')
    {
        fscanf(fp, "%c", &y);
    }
    push(&s1, y);
    fscanf(fp, "%[^=]s", pre);
    fix(pre);
    fscanf(fp, "%c", &ch);
    int i = 0, j = 0;
    while (true)
    {

        post_wrong[i]=(char*)malloc(100*sizeof(char));
	    fscanf(fp, "%c", &post_wrong[i][0]);
        while (post_wrong[i][0] == ' ')
        {
	        fscanf(fp, "%c", &post_wrong[i][0]);
        }
        j = 1;
        fscanf(fp, "%c", &p);
        while (p != ',' && p != '}')
        {

           post_wrong[i][j]=p;
           j++;
	        fscanf(fp, "%c", &p);
        }
        post_wrong[i][j]='\0';
        fix(post_wrong[i]);

        i++;
        if (p == '}')
        {
            break;
        }
        if (i % 4 == 0)
        {
            ct1++;
	        post_wrong=(char**)realloc(post_wrong,4*(ct1+1)*sizeof(char*));
        }
    }
	for(j=i;j<4*(ct1+1);j++)
	{
		post_wrong[j]=NULL;
	}
	question->wrong=(char**)malloc(i*sizeof(char*));
    for(j=0;j<i;j++)
    {
        question->wrong[j]=(char*)malloc(100*sizeof(char));
        strcpy(question->wrong[j], post_wrong[j]);
    }
    question->no_of_wrong=i;
	for(j=0;j<(ct1+1)*4;j++)
	{
		free(post_wrong[j]);
	}
	free(post_wrong);
	fscanf(fp, "%c", &y);
    while (y != '{')
    {
        fscanf(fp, "%c", &y);
    }
    push(&s1, y);
    fscanf(fp, "%[^=]s", pre);
    fix(pre);
    fscanf(fp, "%c", &ch);
    i = 0;
    j = 0;
    while (1)
    {
        post_correct[i] = (char *)malloc(100 * sizeof(char));
        fscanf(fp, "%c", &post_correct[i][0]);
        while (post_correct[i][0] == ' ')
        {
            fscanf(fp, "%c", &post_correct[i][0]);
        }
        j = 1;
        fscanf(fp, "%c", &p);
        while (p != ',' && p != '}')
        {
            post_correct[i][j] = p;
            j++;
            fscanf(fp, "%c", &p);
        }
        post_correct[i][j] = '\0';
        fix(post_correct[i]);
        i++;
        if (p == '}')
        {
            break;
        }
        ct2++;
	    post_correct=(char**)realloc(post_correct,(ct2+1)*sizeof(char*));
    }
    question->correct = (char **)malloc(i * sizeof(char *));
    for (j = 0; j < i; j++)
    {
        question->correct[j] = (char *)malloc(100 * sizeof(char));
        strcpy(question->correct[j], post_correct[j]);
    }
    question->no_of_correct = i;
	for(j=0;j<i;j++)
	{
		free(post_correct[j]);
	}
	free(post_correct);
    return question;
}

fill_up *insert_fill_up(stack s1)
{
    fill_up *question;
    question = (fill_up *)malloc(sizeof(fill_up));
    char post_correct[20], pre[20], post_line[1000];
    char y, z;
    char buffer[1000];
    question->difficulty = input_difficulty(s1, pre);
    strcpy(question->text, input_text(s1, pre, post_line, buffer));
    fscanf(fp, "%c", &y);
    while (y != '{')
    {
        fscanf(fp, "%c", &y);
    }
    push(&s1, y);
    fscanf(fp, "%[^=]s", pre);
    fix(pre);
    char ch;
    fscanf(fp, "%c", &ch);
    fscanf(fp, "%c", &post_correct[0]);
    while (post_correct[0] == ' ')
    {
        fscanf(fp, "%c", &post_correct[0]);
    }
    fscanf(fp, "%[^}]s", post_correct + 1);
    fix(post_correct);
    fscanf(fp, "%c", &z);
    if (z == '}')
    {
        pop(&s1);
    }
    strcpy(question->correct, post_correct);
    return question;
}

true_false *insert_true_false(stack s1)
{
    true_false *question;
    question = (true_false *)malloc(sizeof(true_false));
    char post_correct, pre[20], post_line[1000];
    char y, z;
    char buffer[1000];
    question->difficulty = input_difficulty(s1, pre);
    strcpy(question->text, input_text(s1, pre, post_line, buffer));
    fscanf(fp, "%c", &y);
    while (y != '{')
    {
        fscanf(fp, "%c", &y);
    }
    push(&s1, y);
    fscanf(fp, "%[^=]s", pre);
    fix(pre);
    char ch;
    fscanf(fp, "%c", &ch);
    fscanf(fp, "%c", &post_correct);
    while (post_correct == ' ')
    {
        fscanf(fp, "%c", &post_correct);
    }
    fscanf(fp, "%c", &z);
	while (z != '}')
	{
		fscanf(fp, "%c", &z);
	}
    if (z == '}')
    {
        pop(&s1);
    }
    question->correct = post_correct;
    return question;
}

short_answer *insert_short_answer(stack s1)
{
    short_answer *question;
    question = (short_answer *)malloc(sizeof(short_answer));
    char post_correct[1000], pre[20], post_line[1000];
    char y, z;
    char buffer[1000];
    question->difficulty = input_difficulty(s1, pre);
    strcpy(question->text, input_text(s1, pre, post_line, buffer));
    fscanf(fp, "%c", &y);
    while (y != '{')
    {
        fscanf(fp, "%c", &y);
    }
    push(&s1, y);
    fscanf(fp, "%[^=]s", pre);
    fix(pre);
    char ch;
    fscanf(fp, "%c", &ch);
    fscanf(fp, "%c", &post_correct[0]);
    while (post_correct[0] == ' ')
    {
        fscanf(fp, "%c", &post_correct[0]);
    }
    fscanf(fp, "%[^}]s", post_correct + 1);
    fix(post_correct);
    fscanf(fp, "%c", &z);
    if (z == '}')
    {
        pop(&s1);
    }
    strcpy(question->correct, post_correct);
    return question;
}

void question_bank(int bank_id, int type_number[], int filled_val[], int realloc_ct[])
{
    char str[1000];
    printf("Please Enter the name of the Input file.");
    br;
    printf("Note: In case You are running the program on terminal, the file should be present inside Project Directory Folder");
    br;
    printf("Note: In case You are running the program on Clion, etc IDE, the file should be present inside Debug Folder");
    br;
    scanf("%s", str);
    fp = fopen(str, "r");
    if (fp == NULL)
    {
        perror("Error While opening the file");
        exit(EXIT_FAILURE);
    }
    char x, y, z;
    fscanf(fp, "%c", &x);
    char pre[20], post[10], ch;
    struct stack s1;
    int mcq_index = filled_val[0], fill_up_index = filled_val[1], true_false_index = filled_val[2], short_answer_index = filled_val[3];
    s1.top = -1;
    while (x != EOF)
    {
        fscanf(fp, "%c", &y);
        while (y != '{')
        {
            fscanf(fp, "%c", &y);
        }
        push(&s1, y);
        fscanf(fp, "%[^=]s", pre);
        fix(pre);
        fscanf(fp, "%c", &ch);
        fscanf(fp, "%c", &post[0]);
        while (post[0] == ' ')
        {
            fscanf(fp, "%c", &post[0]);
        }
        fscanf(fp, "%[^}]s", post + 1);
        fix(post);
        fscanf(fp, "%c", &z);
        if (z == '}')
        {
            pop(&s1);
        }
        if (post[0] == 'm')
        {
            mcq_arr[mcq_index] = insert_mcq(s1);
            available[bank_id][0][(mcq_arr[mcq_index])->difficulty]++;
            mcq_index++;
            type_number[0]++;
            filled_val[0]++;
            if (mcq_index % 10 == 0)
            {
                realloc_ct[0]++;
	            mcq_arr=(mcq **)realloc(mcq_arr ,10*(realloc_ct[0]+1)*sizeof(mcq *));
            }
        }
        else if (post[0] == 'f')
        {
            fill_up_arr[fill_up_index] = insert_fill_up(s1);
            available[bank_id][1][(fill_up_arr[fill_up_index])->difficulty]++;
            fill_up_index++;
            type_number[1]++;
            filled_val[1]++;
            if (fill_up_index % 10 == 0)
            {
                realloc_ct[1]++;
	            fill_up_arr=(fill_up **)realloc(fill_up_arr ,10*(realloc_ct[1]+1)*sizeof(fill_up *));
            }
        }
        else if (post[0] == 't')
        {
            true_false_arr[true_false_index] = insert_true_false(s1);
            available[bank_id][2][(true_false_arr[true_false_index])->difficulty]++;
            true_false_index++;
            type_number[2]++;
            filled_val[2]++;
            if (true_false_index % 10 == 0)
            {
                realloc_ct[2]++;
	            true_false_arr=(true_false **)realloc(true_false_arr ,10*(realloc_ct[2]+1)*sizeof(true_false *));
            }
        }
        else if (post[0] == 's')
        {
            short_answer_arr[short_answer_index] = insert_short_answer(s1);
            available[bank_id][3][(short_answer_arr[short_answer_index])->difficulty]++;
            short_answer_index++;
            type_number[3]++;
            filled_val[3]++;
            if (short_answer_index % 10 == 0)
            {
                realloc_ct[3]++;
	            short_answer_arr=(short_answer **)realloc(short_answer_arr ,10*(realloc_ct[3]+1)*sizeof(short_answer *));
            }
        }
        x = getc(fp);
    }
    fclose(fp);
    //fprintf("i have entered here2\n");

	//Debugging start
//     for (int i = 0; i < 4; i++)
//     {
//         printf("%s2\n", mcq_arr[i]->text);
//         printf("%lf2\n", mcq_arr[i]->difficulty);
//         //int p=sizeof(mcq_arr[i]->wrong)/(sizeof(mcq_arr[i]->wrong[0]));
//         int p=mcq_arr[i]->no_of_wrong;
//         //fprintf("%d\n",p);
//         //fprintf("%lu\n",sizeof(mcq_arr[i]->wrong));
//         // fprintf("%lu\n",sizeof(mcq_arr[i]->wrong[0]));
//         for(int j=0;j<p;j++)
//          printf("%s2\n",mcq_arr[i]->wrong[j]);
//         int q=mcq_arr[i]->no_of_correct;
//         for(int j=0;j<q;j++)
//          printf("%s2\n", mcq_arr[i]->correct[j]);
//     }
//     for (int i = 0; i < 1; i++)
//     {
//         printf("%s2\n", fill_up_arr[i]->text);
//         printf("%lf2\n", fill_up_arr[i]->difficulty);
//         printf("%s2\n", fill_up_arr[i]->correct);
//     }
//     for (int i = 0; i < 1; i++)
//     {
//         printf("%s2\n", true_false_arr[i]->text);
//         printf("%lf2\n", true_false_arr[i]->difficulty);
//         printf("%c2\n", true_false_arr[i]->correct);
//     }
//     for (int i = 0; i < 1; i++)
//     {
//         printf("%s2\n", short_answer_arr[i]->text);
//         printf("%lf2\n", short_answer_arr[i]->difficulty);
//         printf("%s2\n", short_answer_arr[i]->correct);
//     }
//		printf("Location = %p", mcq_arr[0]);
//    Debugging end

}
