#include "../function_def.h"
#include "question_paper.h"
#include "../question_bank/tree_struct.h"
#include <time.h>

//T.B.D=>
mcq **mcq_struct_array;        //the array of mcqs made while reading question_bank.txt
fill_up **fillup_struct_array; //the array of fill_ups made while reading question_bank.txt
//^

void printer_mcq(FILE *file, mcq *q)
{
    fprintf(file, "%s\n", q->text);
    int len = sizeof(q->options) / sizeof(q->correct);
    fo(i, len) fprintf(file, "%s\n", q->options[i]);
    //yet to be modulated to facilitate random generation
}

void printer_fillup(FILE *file, fill_up *q)
{
    fprintf(file, "%s\n", q->text);
}

int number_of_children(ptrnode tree);
//T.B.D =>needed to check if the number of questions sought are available (during sampling)

int *generate_randoms(int available, int n)
{
    int *arr = (int *)calloc(available, sizeof(int));
    fo(i, n) arr[i] = 1;
    int curr, temp;
    fo(i, n)
    {
        curr = (i + rand()) % available;
        temp = arr[i];
        arr[i] = arr[curr];
        arr[curr] = temp;
    }
    return arr;
}

struct questions add_question_type()
{
    char ch, buffer[100];
    float difficulty;
    struct questions que;
// Start Pratham Part here
//     while (ch == ' ')
//         ch = getchar();
//     scanf("%[^{]s", buffer);
//     // printf("%s",buffer);

//     if (!strcmp(buffer, "sample"))
//     {
//         //printf("yes\n");
//         while (ch != '{')
//             ch = getchar();
//         scanf("%[^=]s", buffer);
//         while (ch != '=')
//             ch = getchar();
//         scanf("%[^}]s", buffer);
//         if (!strcmp(buffer, "mcq")) ///add the different question types
//             que.type = 0;
//         if (!strcmp(buffer, "scq"))
//             que.type = 1;
//         while (ch != '}')
//             ch = getchar();

//         //printf("%d\n",que.type);

//         while (ch != '{')
//             ch = getchar();
//         scanf("%[^=]s", buffer);
//         while (ch != '=')
//             ch = getchar();
//         scanf("%f", &que.diff);
//         while (ch != '}')
//             ch = getchar();

//         //printf("%f\n",que.diff);

//         while (ch != '{')
//             ch = getchar();
//         scanf("%[^=]s", buffer);
//         while (ch != '=')
//             ch = getchar();
//         scanf(" %d", &que.no_of_questions);
//         while (ch != '}')
//             ch = getchar();

//         //printf("%d\n",que.no_of_questions);
//     }
// End Pratham part here
    ///////Checking if command is sample//////////
    ch=getchar();
    while(ch == ' ')
        ch=getchar();
    int j=0;
    while( (ch != ' ') && (ch != '{') )
    {
        buffer[j]=ch;
        j++;
        ch=getchar();
    }       
    buffer[j]='\0';
    while(ch != '{')
        ch=getchar();
    /////////////////////
    if(!strcmp(buffer,"sample"))
    {   
        ///////Checking the type of question////////////
        while(ch != '{')
            ch=getchar();        
        scanf("%[^=]s",buffer);
        while(ch != '=')
            ch=getchar();
        ch=getchar();
        while(ch == ' ')
            ch=getchar();
        int i=0;
        while( (ch != ' ') && (ch != '}') )
        {
            buffer[i]=ch;
            i++;
            ch=getchar();
        }
        buffer[i]='\0';
        while(ch != '}')
            ch=getchar();    
        //!!!!!!!!!!!!!!!!add the different question types here!!!!!!!!!!!!!!!!!
        if(!strcmp(buffer,"mcq"))   
            que.type=44;
        if(!strcmp(buffer,"scq"))
            que.type=55;
        while(ch != '}')
            ch=getchar();
        //printf("%d\n",que.type);
        //////////reading the difficulty of the questions///////////////
        while(ch != '{')
            ch=getchar();
        scanf("%[^=]s",buffer);
        while(ch != '=')
            ch=getchar();
        scanf("%f",&que.diff);
        while(ch != '}')
            ch=getchar();
        //printf("%f\n",que.diff);
        while(ch != '{')
            ch=getchar();
        scanf("%[^=]s",buffer);
        while(ch != '=')
            ch=getchar();
        scanf(" %d",&que.no_of_questions);
        while(ch != '}')
            ch=getchar();   
        //printf("%d\n",que.no_of_questions);
    }

    return que;
}

void read_question_paper(ptrnode qb)
{
    srand(time(0));
    char ch, buffer[100];
    struct questions questions_in_paper[5];
    int i = 0;
    ch = getchar();

    while (ch != '.') //eof here!!!

    {
        while (ch != 92)
            ch = getchar();
        questions_in_paper[i] = add_question_type();

        i++;
        ch = getchar();
    }
    for (int j = 0; j < i; j++)
        sampler(qb, questions_in_paper[j]);

    return;

    //for(int j=0;j<i;j++)
    //   printf("%d %.2f %d\n",questions_in_paper[j].type,questions_in_paper[j].diff,questions_in_paper[j].no_of_questions);

}
typedef int difftype;

void sampler(ptrnode qb, question Q)
{
    FILE *paper_ptr;
    paper_ptr = fopen("QP.txt", "a");

    int type = Q.type;

    qb = qb->firstchild;
    while (type--)
    {
        qb = qb->nextsibling;
    }

    difftype diff = Q.diff;

    qb = qb->firstchild;
    while (diff--)
    {
        qb = qb->nextsibling;
    }

    int num = Q.no_of_questions;
    int available = number_of_children(qb);

    int i = 0;
    if (available >= num)
    {
        qb = qb->firstchild;
        int *arr = generate_randoms(available, num);
        while (available--)
        {
            if (arr[i])
            {
                if (Q.type == 0)
                    printer_mcq(paper_ptr, mcq_struct_array[qb->element]);
                else if (Q.type == 1)
                    printer_fillup(paper_ptr, fillup_struct_array[qb->element]);

                //add more
            }
            i++;
            qb = qb->nextsibling;
        }
    }
    else
    {
        fprintf(stderr, "could not generate %d questions of type %d and difficulty %lf, available = %d\n", num, Q.type, Q.diff, available);
        //T.B.D =>here you'd like to print type_string (instead of index) which needs some type_index <-> type_string referencing
    }
}