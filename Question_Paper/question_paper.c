#include "../function_def.h"
typedef int diff_type;

void printer_mcq(FILE *file, mcq *q)
{
    fprintf(file, "%s\n", q->text);
    int len = sizeof(q->options) / sizeof(q->correct);
    fo(i, len)
    {
    	fprintf(file, "%s\n", q->options[i]);
        //yet to be modulated to facilitate random generation
	}
}

void printer_fill_up(FILE *file, fill_up *q)
{
    fprintf(file, "%s\n", q->text);
}

// int number_of_children(ptrnode tree);
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

question add_question_type()
{
    char ch, buffer[100];
    question que;
	fscanf(fp2, "%c", &ch);
	while(ch == ' ')
    {
	    fscanf(fp2, "%c", &ch);
    }
    int j=0;
    while( (ch != ' ') && (ch != '{') )
    {
        buffer[j]=ch;
        j++;
	    fscanf(fp2, "%c", &ch);
    }       
    buffer[j]='\0';
    while(ch != '{')
    {
	    fscanf(fp2, "%c", &ch);
    }
    if(!strcmp(buffer,"sample"))
    {
    	while(ch != '{')
    	{
		    fscanf(fp2, "%c", &ch);
	    }
        fscanf(fp2, "%[^=]s",buffer);
        while(ch != '=')
        {
	        fscanf(fp2, "%c", &ch);
        }
	    fscanf(fp2, "%c", &ch);
	    while(ch == ' ')
        {
	        fscanf(fp2, "%c", &ch);
        }
        int i=0;
        while((ch != ' ') && (ch != '}'))
        {
            buffer[i]=ch;
            i++;
	        fscanf(fp2, "%c", &ch);
        }
        buffer[i]='\0';
        while(ch != '}')
        {
	        fscanf(fp2, "%c", &ch);
        }
        //Add the different question types here
        if(!strcmp(buffer,"mcq"))
        {
	        que.type=0;
        }
        else if(!strcmp(buffer,"sa"))
        {
	        que.type=3;
        }
        else if(!strcmp(buffer,"fill_up"))
        {
	        que.type=1;
        }
        else if(!strcmp(buffer,"true_false"))
        {
	        que.type=2;
        }
        while(ch != '}')
        {
	        fscanf(fp2, "%c", &ch);
	    }
        //Reading the difficulty of the questions
        while(ch != '{')
        {
	        fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%[^=]s",buffer);
        while(ch != '=')
        {
	        fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%f",&que.diff);
        while(ch != '}')
        {
	        fscanf(fp2, "%c", &ch);
        }
        while(ch != '{')
        {
	        fscanf(fp2, "%c", &ch);
	    }
        fscanf(fp2, "%[^=]s",buffer);
        while(ch != '=')
        {
	        fscanf(fp2, "%c", &ch);
        }
        int temp;
        fscanf(fp2, " %d",&temp);
        que.no_of_questions = temp;
        while(ch != '}')
        {
	        fscanf(fp2, "%c", &ch);
        }
	    return que;
    }
    else
    {
		printf("Input Invalid");
    }
}

void read_question_paper(ptrnode qb)
{
    srand(time(0));
    char ch;
    question questions_in_paper[4];
    int i = 0;
	char str[1000];
	printf("Please Enter the name of the Input file.");
	br;
	printf("Note: In case You are running the program on terminal, the file should be present inside Project Directory Folder");
	br;
	printf("Note: In case You are running the program on Clion, etc IDE, the file should be present inside Debug Folder");
	br;
	scanf("%s", str);
	fp2 = fopen(str, "r");
	if (fp2 == NULL)
	{
		perror("Error While opening the file");
		exit(EXIT_FAILURE);
	}
	fscanf(fp2, "%c", &ch);
	while (ch != '#') //eof here!!!
	{
		while (ch != 92)
		{
			fscanf(fp2, "%c", &ch);
		}
		questions_in_paper[i] = add_question_type();
		i++;
		fscanf(fp2, "%c", &ch);
	}
	fclose(fp2);
    for (int j = 0; j < i; j++)
    {
	    sampler(qb, questions_in_paper[j]);
    }
}

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
    diff_type diff = Q.diff;
    qb = qb->firstchild;
    while (diff--)
    {
        qb = qb->nextsibling;
    }
    int num = Q.no_of_questions;
	//int available = number_of_children(qb);
	int available = 0;
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
                {
	                printer_mcq(paper_ptr, mcq_arr[qb->element]);
                }
                else if (Q.type == 1)
                {
	                printer_fill_up(paper_ptr, fill_up_arr[qb->element]);
                }
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