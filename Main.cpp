#include <iostream>
#include "headers/Quiz.hpp"
#include "headers/Question.hpp"


int main(){
    //testing push
    Quiz q;
    q.addQuestion();
    q.addQuestion();
    q.printQs();
    q.clear();
    q.printQs();

    return 0;
}