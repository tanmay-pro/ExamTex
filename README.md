# DSA-Miniproject-(Examtex)

## Introduction
This is a project to create multiple random question papers from large question banks. <br> <br>

## About the program
This is a menu-driven program. Select the option number for performing that function:-

1. Add a new Question Bank 
1. Delete Existing Question Bank
3. Add Questions to Existing Question Bank
4. Print Existing Question Bank
5. Generate Question Paper
6. Exit
<br><br>

## How to run the program
Run this for compiling the program-
```
gcc main.c Question_Bank/question_bank_tree.c Question_Bank/create_question_bank.c Question_Bank/reading_input_bank.c Question_Paper/question_paper.c Question_Bank/insert_questions.c Question_Bank/delete_questions.c Question_Bank/print_question_bank.c Question_Bank/free.c
```
<br>

### Add a new Question Bank
* We get an unique ID for the question bank which we need to remember for further use.
* Then we must input the name of the file(In case you are running the program on terminal, the file should be present inside Project Directory Folder or if you are running the program on Clion, etc IDE, the file should be present inside Debug Folder).
* A new question bank is added to the tree with unique ID.
* Sample Input files have been uploaded with names 1.txt, 2.txt and so on.
* Format of input file: Each question is started by the command \question, followed by its type, ts difficulty, and its content depending on the type of question. Checkout the sample input files for getting a better understanding of how the input file is supposed to be given.

<br>

### Delete Existing Question Bank
* We can delete an existing question bank by entering the ID of the question bank to delete.

<br>

### Add Questions to Existing Question Bank
* We can add questions to an existing question bank by entering the ID of the question bank.
* Then we must input the name of the file(In case you are running the program on terminal, the file should be present inside Project Directory Folder or if you are running the program on Clion, etc IDE, the file should be present inside Debug Folder).

<br>

### Print Existing Question Bank
* Enter the ID of the Question Bank to print.

<br>

### Generate Question Paper
* Enter the ID of the Question Bank to from which question paper is to be generated.
* Then Enter the number of files to be Generated.
* Further we must input the name of the file(In case you are running the program on terminal, the file should be present inside Project Directory Folder or if you are running the program on Clion, etc IDE, the file should be present inside Debug Folder).
* Sample input files have been uploaded with names sample1.txt, sample2.txt and so on. 
* Format of input file: Each question bundle is started by the command \sample, followed by the type, the difficulty, and the number of questions in the bundle. Checkout the sample input files for getting a better understanding of how the input file is supposed to be given.
* The required question papers will be generated in current folder.

<br>

### Exit
* Frees all the memory and exits the program.

<br>

## Credits
This project was made by-
* Tanmay Goyal
* Laksh Balani
* Siddh  Jain
* Pratham Gupta
