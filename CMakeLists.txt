cmake_minimum_required(VERSION 3.13)
project(ExamTex)
set(CMAKE_C_STANDARD 11)
add_executable(ExamTex main.c Question_Bank/question_bank_tree.c Question_Bank/create_question_bank.c Question_Bank/reading_input_bank.c Question_Paper/question_paper.c Question_Bank/insert_questions.c Question_Bank/delete_questions.c Question_Bank/print_question_bank.c Question_Bank/free.c)
