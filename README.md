# quizGame
### Intro
quizGame is a simple quiz simulator coded in C++. The User is asked a question and he must provide the correct answer. Beside playing the game the user can choose one of the options in the menu to do different things.

### Options
1. Start the quiz
2. Add their own question via a guided process
3. Display all questions currently loaded in the question pool
4. Import questions from a file
5. Export questions to a file
6. Clear the question pool
7. Exit the game

### Extra info
By default the program expects 4-5 alternative answers per question and displays 3 of them including the correct answer during the quiz. Those values can be modified in the Quiz.cpp via macros.

Additionally when an error is encountered during the reading of a file the program will stop any further reading but will save the correct input previously read. It will also inform the user about the location of the error in the file.

### Input file format
The file used to import questions has to be formatted in a certain way for the program to import the questions correctly. The format is as follows: 
* The question prompt.
* Number of alternative answers
* Answer alternatives (one alter native per line)
* Index of the correct answer \[0,alternative number\)

### Question file example
This sets the question prompt to "Who is the current president of the united states ?" and sets the correct answer to be Joe Biden while providing 3 other alternative answers.
* Who is the current president of the united states ?
* 4
* George Bush
* Donald Trump
* Joe Biden
* Richard Nixon
* 2
