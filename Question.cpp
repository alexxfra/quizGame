#include "headers/Question.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Question::Question(const std::string testPrompt, const std::vector<std::string>& ans, const int index) : prompt(testPrompt), answers(ans), correctIndex(index){}

void Question::toString(){
    cout << prompt << endl;
    for (int i = 0; i < answers.size(); i++){
        cout << "#" << i+1 << " " << answers[i] << endl;
    }
}

void Question::setPrompt(const std::string newPrompt){
    prompt = newPrompt;
}

void Question::setAnswers(const std::vector<std::string>& newAnswers){
    answers = newAnswers;
}

void Question::setIndex(const int newIndex){
    correctIndex = newIndex;
}