#include "../function_def.h"
typedef int diff_type;

void printer_mcq(FILE *file, mcq *q)
{
    fprintf(file, "%s\n", q->text);
    char options_to_print[4][100];
    int correct_optionID = (rand()) % 4;
    int n = q->no_of_options;
    int option_selected[n];
    fo(i, n)
    {
        option_selected[i] = 0;
    }
    strcpy(options_to_print[correct_optionID], *q->correct);
    fo(i, 4)
    {
        if (i != correct_optionID)
        {
            int p = (rand()) % n;
            if (!strcmp(q->options[p], options_to_print[correct_optionID]))
            {
                option_selected[p] = 1;
            }
            while (option_selected[p] != 0)
            {
                p = (rand()) % n;
            }
            strcpy(options_to_print[i], q->options[p]);
            option_selected[p] = 1;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        fprintf(file, "%c)%s\t", 65 + i, options_to_print[i]);
    }
    fprintf(file, "\n\n");
}

void printer_fill_up(FILE *file, fill_up *q)
{
    fprintf(file, "%s\n", q->text);
    fprintf(file, "Ans:\n\n");
}

void printer_true_false(FILE *file, true_false *q)
{
    fprintf(file, "%s\n", q->text);
    fprintf(file, "A)True\tB)False\n\n");
}

void printer_short_answer(FILE *file, struct short_answer *q)
{
    fprintf(file, "%s\n", q->text);
    fprintf(file, "Ans:\n\n");
}

int *generate_randoms(int avail, int n)
{
    srand(time(0) + rand());
    int *arr = (int *)calloc(avail, sizeof(int));
    fo(i, n) arr[i] = 1;
    int curr, temp;
    fo(i, n)
    {
        curr = (i + rand()) % avail;
        temp = arr[i];
        arr[i] = arr[curr];
        arr[curr] = temp;
    }
    return arr;
}

question add_question_type()
{
    char ch, buffer[100];
    question que = (question)malloc(sizeof(struct questions));
    fscanf(fp2, "%c", &ch);
    while (ch == ' ')
    {
        fscanf(fp2, "%c", &ch);
    }
    int j = 0;
    while ((ch != ' ') && (ch != '{'))
    {
        buffer[j] = ch;
        j++;
        fscanf(fp2, "%c", &ch);
    }
    buffer[j] = '\0';
    while (ch != '{')
    {
        fscanf(fp2, "%c", &ch);
    }
    if (!strcmp(buffer, "sample"))
    {
        while (ch != '{')
        {
            fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%[^=]s", buffer);
        while (ch != '=')
        {
            fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%c", &ch);
        while (ch == ' ')
        {
            fscanf(fp2, "%c", &ch);
        }
        int i = 0;
        while ((ch != ' ') && (ch != '}'))
        {
            buffer[i] = ch;
            i++;
            fscanf(fp2, "%c", &ch);
        }
        buffer[i] = '\0';
        while (ch != '}')
        {
            fscanf(fp2, "%c", &ch);
        }
        //Add the different question types here
        if (!strcmp(buffer, "mcq"))
        {
            que->type = 0;
        }
        else if (!strcmp(buffer, "short_answer"))
        {
            que->type = 3;
        }
        else if (!strcmp(buffer, "fill_up"))
        {
            que->type = 1;
        }
        else if (!strcmp(buffer, "true_false"))
        {
            que->type = 2;
        }
        while (ch != '}')
        {
            fscanf(fp2, "%c", &ch);
        }
        //Reading the difficulty of the questions
        while (ch != '{')
        {
            fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%[^=]s", buffer);
        while (ch != '=')
        {
            fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%d", &que->difficulty);
        while (ch != '}')
        {
            fscanf(fp2, "%c", &ch);
        }
        while (ch != '{')
        {
            fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%[^=]s", buffer);
        while (ch != '=')
        {
            fscanf(fp2, "%c", &ch);
        }
        int temp;
        fscanf(fp2, " %d", &temp);
        que->no_of_questions = temp;
        while (ch != '}')
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

void read_question_paper(ptrnode qb, int number_of_files)
{
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
   
    char file_name[] = "Current/x.md";
    fo(k, number_of_files)
    {
        file_name[sizeof(file_name) - 5] = k + '1';
        for (int j = 0; j < i; j++)
        {
            sampler(qb, questions_in_paper[j], file_name);
        }
    }
}

void sampler(ptrnode qb, question Q, char file_name[])
{

    FILE *paper_ptr;
    printf("ooooooooooooooooo-%s\n", file_name);
    paper_ptr = fopen(file_name, "a");
    //paper_ptr = stdout;
    int type = Q->type;
    qb = qb->firstchild;
    while (type--)
    {
        qb = qb->nextsibling;
    }
    diff_type diff = Q->difficulty;
    qb = qb->firstchild;
    while (diff--)
    {
        qb = qb->nextsibling;
    }
    int num = Q->no_of_questions;
    int avail = available[Q->type][Q->difficulty];
    int i = 0;
    if (avail >= num)
    {
        qb = qb->firstchild;
        int *arr = generate_randoms(avail, num);
        while (avail--)
        {
            if (arr[i] == true)
            {
                if (Q->type == 0)
                {
                    printf("ooooooooooooooo-qb->element = %d\n", qb->element);
                    br;
                    printer_mcq(paper_ptr, mcq_arr[qb->element]);
                }
                else if (Q->type == 2)
                {
                    printer_true_false(paper_ptr, true_false_arr[qb->element]);
                }
                else if (Q->type == 3)
                {
                    printer_short_answer(paper_ptr, short_answer_arr[qb->element]);
                }
                else if (Q->type == 1)
                {
                    printer_fill_up(paper_ptr, fill_up_arr[qb->element]);
                }
            }
            i++;
            qb = qb->nextsibling;
        }
    }
    else
    {
        fprintf(stderr, "could not generate %d questions of type %d and difficulty %d, avail = %d\n", num, Q->type, Q->difficulty, avail);
    }
    fclose(paper_ptr);
}
