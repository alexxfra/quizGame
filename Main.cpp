#include <iostream>
#include "headers/Quiz.hpp"
#include "headers/Question.hpp"


int main(){
    Quiz q;
    q.addQuestion();
    q.addQuestion();
    q.printQs();
    q.clear();
    q.printQs();

    return 0;
}