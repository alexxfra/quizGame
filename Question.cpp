#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include "headers/Question.hpp"
#include "headers/Quiz.hpp"


using namespace std;

Question::Question(const std::string testPrompt, const std::vector<std::string>& ans, const int index) : prompt(testPrompt), answers(ans), correctIndex(index), ansCount(ans.size()){}


/**
 * Prints the question prompt followed by all possible answers  
 * in a format suitable for easy reading.
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
 * Prints the question prompt followed by all possible shuffled answers  
 * in a format suitable for easy reading.
 * @param os Output stream where the question is printed.
 * @param qOffset sets the setw() value of the possible answers to create indentation.
 */
void Question::toStringReorder(ostream &os, const int qOffset){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> allAnsRange(0, ansCount-1);
    
    vector<int> usedIs;
    int tempIndex;
    os << prompt << endl;
    for (int i = 0; i < answers.size(); i++){
         do{
            tempIndex = allAnsRange(mt);
        }while(find(usedIs.begin(), usedIs.end(), tempIndex) != usedIs.end());
        usedIs.push_back(tempIndex);
        os << setw(qOffset) << i+1;
        os << ") " << answers[tempIndex] << endl;
    }
}
/**
 * Prints the prompt and asks the user to enter an answer.
 * @param ansNo Number of possible answers which should be displayed.
 * @return True if the question was answered correctly, otherwise false.
 */
bool Question::ask(const int ansNo){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> allAnsRange(0, ansCount-1);
    uniform_int_distribution<int> tempAnsRange(0, ansNo-1);

    int answerIndex = tempAnsRange(mt);
    int tempIndex;
    vector<int> usedIs;

    cout << prompt << endl;
    for(int i = 0; i < ansNo; i++){
        if(i == answerIndex){
            cout << setw(2) << i+1;
            cout << ") " << answers[correctIndex] << endl;
        }
        else{
            do{
                tempIndex = allAnsRange(mt);
            }while(find(usedIs.begin(), usedIs.end(), tempIndex) != usedIs.end() || tempIndex == correctIndex);
            cout << setw(2) << i+1;
            cout << ") " << answers[tempIndex] << endl;
            usedIs.push_back(tempIndex);
        }
    }

    int userAns;
    cout << "Enter yout answer: ";
    Quiz::readUserInt(cin, userAns, 1, ansNo);
    
    // Check if the answer is correct and respond accordingly.
    if(userAns-1 == answerIndex){
        cout << "Correct!" << endl;
        return true;
    }
    else{
        cout << "Incorrect!" << endl;
        return false;
    }

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
    if(is.peek() == '\n')
        is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    q = Question(prompt, answers, correctAns);

    return is;
 }


// reorder();
//     vector<string> tempPool;
//     vector<int> usedIs;
//     int index;
//     int userAns;

//     for(int i = 0; i < ansNo-1; i++){
//         do{
//             index = rand() % answers.size();
//         }while(find(usedIs.begin(), usedIs.end(), index) != usedIs.end() || index == correctIndex);
//         usedIs.push_back(index);
//         tempPool.push_back(answers[index]);
//     }
//     index = rand() % (tempPool.size()+1);
//     tempPool.insert(tempPool.begin() + index, answers[correctIndex]);


//     cout << prompt << endl;
//     for (int i = 0; i < tempPool.size(); i++){
//         cout << setw(2) << i+1;
//         cout << ") " << tempPool[i] << endl;
//     }