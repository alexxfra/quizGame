#include "headers/Question.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Question::Question(const std::string testPrompt, const std::vector<std::string>& ans, const int index) : prompt(testPrompt), answers(ans), correctIndex(index), ansCount(ans.size()){}

/**
 * Prints a formatted Question with it's possible answers.
 * @param os Output stream where the question is printed.
 * @param qOffset sets the setw() value of the possible answers to create indentation.
 */
void Question::toString(ostream &os, const int qOffset){
    os << prompt << endl;
    for (int i = 0; i < answers.size(); i++){
        os << setw(qOffset) << i+1;
        os << ") " << answers[i] << endl;
    }
}

/**
 * Checks if the entered index is the index of the correct Answer.
 * @return True if values match, otherwise False.
 */
bool Question::checkAns(const int index){
    return index == correctIndex;
}

/**
 * Overloaded << operator for printing questions to an output stream in a format suitable for reading.
 * @param os Reference to the output stream where the data is printed.
 * @param q Question object from which the data is extracted.
 * @return Reference to the used output stream.
 */
ostream &operator<<(std::ostream& os, const Question &q){
    os << q.prompt << endl;
    os << q.ansCount << endl;
    for (int i = 0; i < q.answers.size(); i++){
        os << q.answers[i] << endl;
    }
    os << q.correctIndex;
    return os;
}
/**
 * Overloaded >> operator for reading formatted Question data from a stream.
 * @param is Reference to the input stream from where the data is read.
 * @param q Question object to which the read data is saved.
 * @return Reference to the used Input stream.
 */
 istream &operator>>(std::istream &is, Question &q){
    string prompt;
    string buff;
    vector<string> answers;
    int correctAns;
    int ansCount;

    getline(is, prompt);    
    is >> ansCount;
    is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    for(int i = 0; i < ansCount; i++){
        getline(is, buff);
        answers.push_back(buff);
    }
    is >> correctAns;
    is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    q = Question(prompt, answers, correctAns);

    return is;
 }

/**
 * AnsCount getter.
 * @return Number of answers to the question.
 */
int Question::getAnsCount(){
    return ansCount;
}