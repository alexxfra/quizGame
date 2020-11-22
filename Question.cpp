#include "headers/Question.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Question::Question(const std::string testPrompt, const std::vector<std::string>& ans, const int index) : prompt(testPrompt), answers(ans), correctIndex(index), ansCount(ans.size()){}

/**
 * Prints question ans answers
 * DONT FORGET TO REMOVE PRITING OF ANSWER. SHOULD NOT BE INCLUDED IN FINAL VERSION.
 */
void Question::toString(ostream &os){
    os << prompt << endl;
    for (int i = 0; i < answers.size(); i++){
        os << setw(2) << i+1;
        os << ") " << answers[i] << endl;
    }
    //os << "Correct answer is: " << answers[correctIndex] << endl;
}

bool Question::checkAns(const int index){
    return index == correctIndex;
}

ostream &operator<<(std::ostream& os, const Question &q){
    os << q.prompt << endl;
    os << q.ansCount << endl;
    for (int i = 0; i < q.answers.size(); i++){
        os << q.answers[i] << endl;
    }
    os << q.correctIndex;
    return os;
}

int Question::getAnsCount(){
    return ansCount;
}


/**
 * JUST SETTERS
 */
// void Question::setPrompt(const std::string newPrompt){
//     prompt = newPrompt;
// }

// void Question::setAnswers(const std::vector<std::string>& newAnswers){
//     answers = newAnswers;
// }

// void Question::setIndex(const int newIndex){
//     correctIndex = newIndex;
// }