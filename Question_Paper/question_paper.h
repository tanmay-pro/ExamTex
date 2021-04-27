#ifndef QUESTION_PAPER_H
#define QUESTION_PAPER_H

typedef struct questions question; 

struct questions
{
    int type;
    float diff;
    int no_of_questions;
};

#endif