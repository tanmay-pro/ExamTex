#ifndef QUESTION_H_
#define QUESTION_H_

typedef struct stack
{
    int top;
    char items[100001];
} stack; // Struct For Creating Stack. Used for inputting data and maintaining parantheses

typedef struct mcq
{
    char text[1000]; // Question itself
    int difficulty;
    char** wrong; // Set of All incorrect options
    char** correct; // Set of All correct options
    int no_of_wrong; // Number of incorrect options
    int no_of_correct; // Number of correct options
} mcq; // Struct For a multiple Choice quesion

typedef struct fill_up
{
    char text[1000]; // Question itself
    int difficulty;
    char correct[100]; //Correct Answer
} fill_up; // Struct for fill in the blanks type questions

typedef struct true_false
{
    char text[1000]; // Question itself
    int difficulty;
    char correct; // Correct answer character (T/F)
} true_false; // Struct for true/false type questions

typedef struct short_answer
{
    char text[1000];// Question itself
    int difficulty;
    char correct[5000]; // Correct Answer
} short_answer; // Struct for Short answer type questions

#endif
