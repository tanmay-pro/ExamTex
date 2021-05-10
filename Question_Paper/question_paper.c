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

void printer_mcq(FILE *file, mcq *q) //to print a formatted mcq into a file
{
    fprintf(file, "_Question %d)_\t", question_counter);
    fprintf(file, "%s\n\n", q->text);
   
    int correct_optionID = (rand()) % 4; //Selects option ID for right answer
    int m = q->no_of_correct;
    int n = q->no_of_wrong;
    int correct_option_to_print = rand() % m;  // Selects the right option to print
    int option_selected[n];               // array to check if wrong ans is already added
    fo(i, n)                            
    {
        option_selected[i] = 0;
    }
    char to_print[4][100];
    strcpy(to_print[correct_optionID], q->correct[correct_option_to_print]); // Fill right option 
    fo(i, 4)          /// fills wrong options in the remaining to_print array.
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
    for (int i = 0; i < 4; i++)       // prints the To_print array. 
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

int *generate_randoms(int avail, int n) //returns an array of length avail, with n indices randomly labelled 1 and rest 0
{
    srand(time(0) + rand());
    int *arr = (int *)calloc(avail, sizeof(int));
    fo(i, n)
    {
	    arr[i] = 1;
    }
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
    while (ch == ' ')  /// For white-space  traversal
    {
        fscanf(fp2, "%c", &ch);
    }
    int j = 0;
    while ((ch != ' ') && (ch != '{'))  //// adding the command to char array buffer[]   
    {
        buffer[j] = ch;
        j++;
        fscanf(fp2, "%c", &ch);
    }
    buffer[j] = '\0';
    while (ch != '{')       /// For white-space  traversal
    {
        fscanf(fp2, "%c", &ch);
    }
    if (!strcmp(buffer, "sample"))        /// For checking if command is 'sample' 
    {
        while (ch != '{')                 /// For white-space  traversal
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
        while ((ch != ' ') && (ch != '}'))         ////adding type of question to buffer array
        {
            buffer[i] = ch;
            i++;
            fscanf(fp2, "%c", &ch);
        }
        buffer[i] = '\0';
        while (ch != '}')             /// For white-space  traversal
        {
            fscanf(fp2, "%c", &ch);
        }
        //Checking  the type of the questions
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
        while (ch != '{')               /// For white-space  traversal
        {
            fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%[^=]s", buffer);
        while (ch != '=')               
        {
            fscanf(fp2, "%c", &ch);
        }
        fscanf(fp2, "%d", &que->difficulty);
        while (ch != '}')               /// For white-space  traversal
        {
            fscanf(fp2, "%c", &ch);
        }

        //Reading the number of the questions
        while (ch != '{')       /// For white-space  traversal
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
        while (ch != '}')               /// For white-space  traversal
        {
            fscanf(fp2, "%c", &ch);
        }
        return que;
    }
    else
    {
        printf("Input Invalid\n");
        exit(0);
    }
}

void read_question_paper(int bank_id, ptrnode qb, int number_of_files) //reads the 'sample.txt' input file and invokes add_question_type() for every '/sample' statement
{
    char ch;
    question questions_in_paper[20];
    int i = 0;
    char str[1000];
    printf("Please Enter the name of the Input file.");
    br;
    printf("In case you are running the program on terminal, the file should be present inside 00PAPER Folder or if you are running the program on Clion, etc IDE, the file should be present inside the 00PAPER folder in the Debug Folder");
    br;
    char file_name1[50];                   /// for opening file using name
    strcpy(file_name1, "00PAPER/");
    scanf("%s", str);
    strcat(file_name1, str);
    fp2 = fopen(file_name1, "r");
    if (fp2 == NULL)
    {
        perror("Error While opening the file");
        exit(EXIT_FAILURE);
    }
    fscanf(fp2, "%c", &ch);
    while (ch != EOF) 
    {
        while (ch != 92)  ///checks for "\" character
        {
            fscanf(fp2, "%c", &ch);
        }
        questions_in_paper[i] = add_question_type();  ///ads input from add_question_type() in questions_in_paper struct array.
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
    	if(Q->type == 0)
            fprintf(stderr, "Could not generate %d questions of type MCQ and difficulty %d. Available number of questions = %d\n", num, Q->difficulty, avail);
	    else if(Q->type == 1)
		    fprintf(stderr, "Could not generate %d questions of type Fill in the Blanks and difficulty %d. Available number of questions = %d\n", num, Q->difficulty, avail);
	    else if(Q->type == 2)
		    fprintf(stderr, "Could not generate %d questions of type True-False and difficulty %d. Available number of questions = %d\n", num, Q->difficulty, avail);
	    else if(Q->type == 3)
		    fprintf(stderr, "Could not generate %d questions of type Short Answer and difficulty %d. Available number of questions = %d\n", num, Q->difficulty, avail);
    }
}
