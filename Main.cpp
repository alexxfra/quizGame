#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "headers/Quiz.hpp"
#include "headers/Question.hpp"

using namespace std;


int main(){
    Quiz q;
    vector<string> draft = {"Yes", "No", "Maybe"};
    string prompt = "Am I a baller ?";
    fstream file;

    file.open("output.txt", ios::in);

    q.readQs(file);
    // q.addQuestion();
    // q.addQuestion();
    q.printQs();
    // q.writeQs(file);
    // q.clear();
    // q.printQs();

    // Question ques(prompt, draft, 0);

    // ofstream of;
    // of.open("output.txt");
    // of << ques;
    // of << ques;
    // ques.toString();

    return 0;
}