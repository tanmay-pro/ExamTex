#include "question_bank/tree_struct.h"

int main()
{
    int type_of_question[] = {0, 1, 2, 3, 4};
    int number_of_types = 5;
    int range_of_diff[] = {0, 1, 2};
    int number_of_diff = 3;
    // Creating a new question Bank
    ptrnode qb1;
    qb1 = make_node(-1);
    qb1 = insert_below(qb1, 0); // Inserting type of Question
    qb1 = qb1->firstchild;
    qb1 = insert_below(qb1, 0);
    fo(i, number_of_types - 1)
    {
        qb1 = insert_horizontally(qb1, type_of_question[i + 1]);
    }
    qb1 = qb1->firstchild;
    fo(k, number_of_diff - 1)
    {
        qb1 = insert_horizontally(qb1, range_of_diff[k + 1]);
    } // Inserting All difficulties
    return 0;
}