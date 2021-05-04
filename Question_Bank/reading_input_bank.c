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

double input_difficulty(stack s1, char *pre)
{
    char y, z, ch;
    double post_num;
	scanf("%c", &y);
    while (y != '{')
    {
	    scanf("%c", &y);
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
	scanf("%c", &ch);
    scanf("%lf", &post_num);
	scanf("%c", &z);
    if (z == '}')
    {
        pop(&s1);
    }
    return post_num;
}

char *input_text(stack s1, char *pre, char *post_line, char *buffer)
{
    char y, z, ch;
	scanf("%c", &y);
    while (y != '{')
    {
	    scanf("%c", &y);
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
	scanf("%c", &ch);
	scanf("%c", &post_line[0]);
    while (post_line[0] == ' ')
    {
	    scanf("%c", &post_line[0]);
    }
    //post_line[1] = '\0';
    scanf("%[^}]s", post_line+1);
    //strcat(post_line, buffer);
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
    char** post_options;
    post_options=(char**)malloc(4*sizeof(char*));
    char post_correct[20], pre[10], post_line[1000];
    char y, z,x,p, ch;
    char buffer[1000];

    question->difficulty = input_difficulty(s1, pre);
    strcpy(question->text, input_text(s1, pre, post_line, buffer));
	
	scanf("%c", &y);
    while (y != '{')
    {
	    scanf("%c", &y);
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
	scanf("%c", &ch);
    int i=0,j=0;
    while(1)
    {
        post_options[i]=(char*)malloc(100*sizeof(char));
	    scanf("%c", &post_options[i][0]);
        while (post_options[i][0] == ' ')
        {
	        scanf("%c", &post_options[i][0]);
        }
        //post_options[i][1] = '\0';
        j=1;
	    scanf("%c", &p);
        while(p!=','&&p!='}')
        {
           post_options[i][j]=p;
           j++;
	        scanf("%c", &p);
        }
        post_options[i][j]='\0';
        //strcat(post_options[i], buffer);
        //printf("%c",p);
        i++;
        if(p=='}')
         break;
        if(i%4==1)
         post_options=(char**)realloc(post_options,4*sizeof(char*));
         
    }
    // post_options[3]=(char*)malloc(100*sizeof(char));
    // post_options[3][0] = (char)getchar();
    // while (post_options[3][0] == ' ')
    // {
    //     post_options[3][0] = (char)getchar();
    // }
    // //post_options[3][1] = '\0';
    // scanf("%[^}]s", post_options[3] + 1);
    // //strcat(post_options[3], buffer);
    // scanf("%c", &z);
    // if (z == '}')
    // {
    //     pop(&s1);
    // }
    // for (int i = 0; i < 4; i++)
    // {
    //     strcpy(question->options[i], post_options[i]);
    // }
    question->options=(char**)malloc(i*sizeof(char*));
    for(j=0;j<i;j++)
    {
        question->options[j]=(char*)malloc(100*sizeof(char));
        strcpy(question->options[j], post_options[j]);
    }
    question->no_of_options=i;
	scanf("%c", &y);
    while (y != '{')
    {
	    scanf("%c", &y);
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
    char cra;
	scanf("%c", &cra);
	scanf("%c", &post_correct[0]);
    while (post_correct[0] == ' ')
    {
	    scanf("%c", &post_correct[0]);
    }
    //post_correct[1] = '\0';
    scanf("%[^}]s", post_correct + 1);
    //strcat(post_correct, buffer);
	scanf("%c", &z);
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
	scanf("%c", &y);
    while (y != '{')
    {
	    scanf("%c", &y);
    }
    push(&s1, y);
    scanf("%[^=]s", pre);
    char ch;
	scanf("%c", &ch);
	scanf("%c", &post_correct[0]);
    while (post_correct[0] == ' ')
    {
	    scanf("%c", &post_correct[0]);
    }
    //post_correct[1] = '\0';
    scanf("%[^}]s", post_correct + 1);
    //strcat(post_correct, buffer);
	scanf("%c", &z);
    if (z == '}')
    {
        pop(&s1);
    }
    strcpy(question->correct, post_correct);
    return question;
}
void question_bank()
{
	char str[1000];
	scanf("%s", str);
	FILE *fp;
	fp = freopen(str, "r",stdin);
	if (fp == NULL)
	{
		perror("Error While opening the file");
		exit(EXIT_FAILURE);
	}
	char x, y, z;
	scanf("%c", &x);
    char pre[10], post[10], ch;
    struct stack s1;
    int i, mcq_index = 0, fill_up_index = 0;
    s1.top = -1;
    while (x != -1)
    {
	    scanf("%c", &y);
        while (y != '{')
        {
	        scanf("%c", &y);
        }
        push(&s1, y);
        scanf("%[^=]s", pre);
	    scanf("%c", &ch);
	    scanf("%c", &post[0]);
        while (post[0] == ' ')
        {
	        scanf("%c", &post[0]);
        }
        scanf("%[^}]s", post + 1);
	    scanf("%c", &z);
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
	    printf("i have entered here");
		x = getchar();
	}
	// Debugging start
//     for (i = 0; i < 4; i++)
//     {
//         printf("%s\n", mcq_arr[i]->text);
//         printf("%lf\n", mcq_arr[i]->difficulty);
//         //int p=sizeof(mcq_arr[i]->options)/(sizeof(mcq_arr[i]->options[0]));
//         int p=mcq_arr[i]->no_of_options;
//         //printf("%d\n",p);
//         //printf("%lu\n",sizeof(mcq_arr[i]->options));
//         // printf("%lu\n",sizeof(mcq_arr[i]->options[0]));
//         for(int j=0;j<p;j++)
//          printf("%s\n",mcq_arr[i]->options[j]);
//         printf("%s\n", mcq_arr[i]->correct);
//     }
//     for (i = 0; i < 1; i++)
//     {
//         printf("%s\n", fill_up_arr[i]->text);
//         printf("%lf\n", fill_up_arr[i]->difficulty);
//         printf("%s\n", fill_up_arr[i]->correct);
//     }
    // Debugging end
}