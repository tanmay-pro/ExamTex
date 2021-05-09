# ExamTex

## Introduction:
This is a project to create multiple random question papers from large question banks. <br> <br>

## About the program:
This is a menu-driven program. Select the option number for performing that function:-

1. Add a new Question Bank 
1. Delete Existing Question Bank
3. Add Questions to Existing Question Bank
4. Print Existing Question Bank
5. Generate Question Paper
6. Exit
<br><br>

## How to run the program:
Run this for compiling the program-
```
gcc main.c Question_Bank/question_bank_tree.c Question_Bank/create_question_bank.c Question_Bank/reading_input_bank.c Question_Paper/question_paper.c Question_Bank/insert_questions.c Question_Bank/delete_questions.c Question_Bank/print_question_bank.c Question_Bank/free.c
```
<br>

### Add a new Question Bank
* We get an unique ID for the question bank which we need to remember for further use.
* Then we must input the name of the file(In case you are running the program on terminal, the file should be present inside 00BANK Folder or if you are running the program on Clion, etc IDE, the file should be present inside the 00BANK folder in the Debug Folder).
* A new question bank is added to the tree with unique ID.
* Sample Input files have been uploaded with names 1.txt, 2.txt and so on.
* Format of input file: Each question is started by the command \question, followed by its type, its difficulty, and its content depending on the type of question. Checkout the sample inputs given below for getting a better understanding of how the input file is supposed to be given.

<br>

### Delete Existing Question Bank
* We can delete an existing question bank by entering the ID of the question bank to delete.

<br>

### Add Questions to Existing Question Bank
* We can add questions to an existing question bank by entering the ID of the question bank.
* Then we must input the name of the file(In case you are running the program on terminal, the file should be present inside 00BANK Folder or if you are running the program on Clion, etc IDE, the file should be present inside the 00BANK folder in the Debug Folder).

<br>

### Print Existing Question Bank
* Enter the ID of the Question Bank to print all the questions in the bank.

<br>

### Generate Question Paper
* Enter the ID of the Question Bank to from which question paper is to be generated.
* Then Enter the number of files to be Generated.
* Further we must input the name of the file(In case you are running the program on terminal, the file should be present inside 00PAPER Folder or if you are running the program on Clion, etc IDE, the file should be present inside the 00PAPER folder in the Debug Folder).
* Sample input files have been uploaded with names sample1.txt, sample2.txt and so on. 
* Format of input file: Each question bundle is started by the command \sample, followed by the type, the difficulty, and the number of questions of that bundle. Checkout the sample inputs given below for getting a better understanding of how the input file is supposed to be given.
* The required question papers will be generated in 00CURRENT folder.

<br>

### Exit
* Frees all the memory and exits the program.

<br>

## About the question types:
### There are 4 Types of questions-
* MCQ: Here we can give multiple wrong answers in 'wrong' and and multiple right answers in 'ans'. One of the right answer is selected and three of the wrong answers is selected.
* Fill In the blanks: We can give fill in the blanks or answer in few words.
* True-False: We can give a statement which is True(T) or False(F).
* Short Answer: Short answer can have questions with answers with a bit of explaination.

### There are 4 types of difficulty under each type of question-
* Easy   (with index=0)
* Medium (with index=1)
* Hard   (with index=2)
* Dhasu  (with index=3)

## Sample Inputs:
For the Question Bank-
```
\question{type=mcq}{difficulty =0}
{text= How was your DSA course?}
{wrong =Okay-ish, bad,horrible}
{ans =very good,excellent}

\question{type =fill_up}{difficulty =3}
{text =What is the sum of the first four odd natural numbers?}
{ans =16 }

\question{type = true_false}{difficulty =0}
{text ='A' is the most common letter used in the English language }
{ans =F}

\question{type= short_answer}{difficulty = 0}
{text = Define Acceleration}
{ans = The rate of change of velocity of an object with respect to time.}
```
For the Question Paper-
```
\sample{type=mcq}
{difficulty = 2}
{number=2}
```
* The input files can have any number of white-spaces in between the commands.
* Please make sure that all your input files end at the bracket. No charcater/ whitespace or newline should exist after the last bracket.

<br>

## Credits:
This project was made by-
* Tanmay Goyal
* Laksh Balani
* Siddh  Jain
* Pratham Gupta
