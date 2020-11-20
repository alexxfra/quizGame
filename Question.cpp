#include "headers/Question.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Question::Question(const std::string testPrompt, const std::vector<std::string>& ans, const int index) : prompt(testPrompt), answers(ans), correctIndex(index){}

/**
 * Prints question ans answers
 * DONT FORGET TO REMOVE PRITING OF ANSWER. SHOULD NOT BE INCLUDED IN FINAL VERSION.
 */
void Question::toString(){
    cout << prompt << endl;
    for (int i = 0; i < answers.size(); i++){
        cout << i+1 << ") " << answers[i] << endl;
    }
    cout << "Correct answer is: " << answers[correctIndex] << endl;
}

ostream &operator<<(std::ostream& os, const Question &q){
    os << q.prompt << endl;
    for (int i = 0; i < q.answers.size(); i++){
        os << i+1 << ") " << q.answers[i] << endl;
    }
    os << "Correct answer is: " << q.answers[q.correctIndex];
    return os;
}



/**
 * JUST SETTERS
 */
void Question::setPrompt(const std::string newPrompt){
    prompt = newPrompt;
}

void Question::setAnswers(const std::vector<std::string>& newAnswers){
    answers = newAnswers;
}

void Question::setIndex(const int newIndex){
    correctIndex = newIndex;
}