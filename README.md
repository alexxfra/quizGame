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

### Input File format
The file used to import questions has to be formatted in a certain way for the program to import the questions correctly. The format is as follows: 
* The question prompt.
* Number of alternative answers
* Answer alternatives (one alter native per line)
* Index of the correct answer \[0,alternative number\)
