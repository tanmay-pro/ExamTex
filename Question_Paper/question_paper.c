#include "../function_def.h"
typedef int diff_type;
int question_counter;

void tostring(char str[], int num) //converts integer index to string, used for file name generation
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
/*
char **shuffle(char **a, int N) //returns a pseudo-randomly shuffled list
{
    srand(time(0) + rand());
    int curr;
    char *temp = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < N; i++)
    {
        curr = (i + rand()) % N;
        strcpy(temp, a[i]);
        strcpy(a[i], a[curr]);
        strcpy(a[curr], temp);
    }
        free(temp);
    return a;
}*/

void printer_mcq(FILE *file, mcq *q) //to print a formatted mcq into a file
{
    fprintf(file, "_Question %d)_\t", question_counter);
    fprintf(file, "%s\n\n", q->text);
    /*
    char **to_print = (char **)calloc(4, sizeof(char *));
    fo(i, 4)
    {
        to_print[i] = (char *)calloc(100, sizeof(char));
    }
    int *correct_arr = generate_randoms(q->no_of_correct, 1);
    int *wrong_arr = generate_randoms(q->no_of_wrong, 3);
    fo(i, q->no_of_correct)
    {
        if (correct_arr[i])
        {
            strcpy(to_print[0], q->correct[i]);
            break;
        }
    }

    int t = 1;
    fo(i, q->no_of_wrong)
    {
        if (correct_arr[i])
        {
            strcpy(to_print[t++], q->correct[i]);
        }
    }
    fo(i, 4)
    {
        printf("%s\n", to_print[i]);
    }
    to_print = shuffle(to_print, 4);
    printf("Hello\n");
    fo(i, 4)
    {
        printf("%s\n", to_print[i]);
    }
    */
    int correct_optionID = (rand()) % 4;
    int m = q->no_of_correct;
    int n = q->no_of_wrong;
    int correct_option_to_print = rand() % m;
    int option_selected[n];
    fo(i, n)
    {
        option_selected[i] = 0;
    }
    char to_print[4][100];
    strcpy(to_print[correct_optionID], q->correct[correct_option_to_print]);
    fo(i, 4)
    {
        if (i != correct_optionID)
        {
            int p = (rand()) % n;
            while (option_selected[p] != 0)
            {
                p = (rand()) % n;
            }
            strcpy(to_print[i], q->wrong[p]);
            option_selected[p] = 1;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        fprintf(file, "1.\t%s\n\n", to_print[i]);
    }
    fprintf(file, "\n\n\n");
}

void printer_fill_up(FILE *file, fill_up *q) //to print a formatted fill up question into a file
{
    fprintf(file, "_Question %d)_\t", question_counter);
    fprintf(file, "%s\n\n", q->text);
    fprintf(file, "\tAns:\n\n");
    fprintf(file, "\n\n\n");
}

void printer_true_false(FILE *file, true_false *q) //to print a formatted true - false question into a file
{
    fprintf(file, "_Question %d)_\t", question_counter);
    fprintf(file, "%s\n\n", q->text);
    fprintf(file, "*\tTrue\n\n*\tFalse\n\n");
    fprintf(file, "\n\n\n");
}

void printer_short_answer(FILE *file, short_answer *q) //to print a formatted short answer question into a file
{
    fprintf(file, "_Question %d)_\t", question_counter);
    fprintf(file, "%s\n\n", q->text);
    fprintf(file, "\tAns:\n\n");
    fprintf(file, "\n\n\n");
}

int *generate_randoms(int avail, int n) //returns an array of lenth avail, with n indices randomly labelled 1 and rest 0
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

question add_question_type() //parses 1 /sample statement from the input file and returns a question struct of details read
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
        //Reading the type of the questions
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
        //Reading the difficulty of the questions
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

void read_question_paper(int bank_id, ptrnode qb, int number_of_files) //reads the 'sample.txt' input file and invokes add_question_type() for every '/sample' statement
{
    char ch;
    question questions_in_paper[4]; //will later parse this array that stores the details read in question structs
    int i = 0;
    char str[1000];
    printf("Please Enter the name of the Input file.");
    br;
    printf("Note: In case You are running the program on terminal, the file should be present inside Project Directory Folder");
    br;
    printf("Note: In case You are running the program on Clion, etc IDE, the file should be present inside Debug Folder");
    br;
    char file_[50];
    strcpy(file_, "00PAPER/");
    scanf("%s", str);
    strcat(file_, str);
    fp2 = fopen(file_, "r");
    if (fp2 == NULL)
    {
        perror("Error While opening the file");
        exit(EXIT_FAILURE);
    }
    fscanf(fp2, "%c", &ch);
    while (ch != EOF) //eof here!!!
    {
        while (ch != 92)
        {
            fscanf(fp2, "%c", &ch);
        }
        questions_in_paper[i] = add_question_type();
        i++;
        ch = getc(fp2);
    }
    fclose(fp2);

    char file_name[20];
    FILE *paper_ptr;
    fo(k, number_of_files)
    {
        //generation of a fresh file pointer
        strcpy(file_name, "00CURRENT/");
        question_counter = 0;
        char index[5];
        tostring(index, k + 1);
        strcat(file_name, index);
        strcat(file_name, ".md");

        paper_ptr = fopen(file_name, "a");
        fprintf(paper_ptr, "#\tSet %d\n\n", k + 1);
        //parsing the array of question structs
        for (int j = 0; j < i; j++)
        {
            sampler(bank_id, qb, questions_in_paper[j], paper_ptr);
        }
        fclose(paper_ptr);
    }
    for (int j = 0; j < i; j++)
    {
        free(questions_in_paper[j]);
    }
}

void sampler(int bank_id, ptrnode qb, question Q, FILE *paper_ptr) //samples out questions based on details in question Q by invoking respective printer functions through a cohesive random algorithm
{
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
    int avail = available[bank_id][Q->type][Q->difficulty]; //this is the number of questions available for a given type and difficulty
    int i = 0;
    if (avail >= num)
    {
        qb = qb->firstchild;
        int *arr = generate_randoms(avail, num); //use this to randomly label questions that are to be printed
        while (avail--)
        {
            if (arr[i] == true) //if labelled, invoke the respective printer
            {
                question_counter++;
                if (Q->type == 0)
                {
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
            //notice that nodes of the linked list on the last level have been labelled 0-1 using an array of same number of elements, hence increment the array index and the traverse to the next node simultaneously
        }
        free(arr);
    }
    else //in case of no. of questions available < demanded, print an error alert
    {
        fprintf(stderr, "could not generate %d questions of type %d and difficulty %d, available = %d\n", num, Q->type, Q->difficulty, avail);
    }
}
