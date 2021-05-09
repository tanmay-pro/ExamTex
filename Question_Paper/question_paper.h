#ifndef QUESTION_PAPER_H
#define QUESTION_PAPER_H

typedef struct questions *question;
struct questions
{
    int type;
    int difficulty;
    int no_of_questions;
};
//use this struct to store details from sample.txt for every '/sample' tag
#endif
