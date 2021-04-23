#include "bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char x, y, z;
    x = getchar();
    char pre[10], post[10];
    double post_num;
    char post_line[100];
    struct stack s1;
    int i=0;
    s1.top = -1;
    mcq* arr[10];
    mcq questions[10];
    while (x!=EOF)
    {
        questions[i]=insert_question(s1,pre,post,post_num,post_line);
        arr[i]=&questions[i];
        //printf("%d %lf\n",i,arr[i]->difficulty);
        i++;
        x=getchar();
    }
    for(i=0;i<4;i++)
     printf("%d %s\n",i,arr[i]->options[3]);
    
    
}