#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <algorithm>
#include "headers/Quiz.hpp"

// Control constants.
#define QUIZLEN 5           // Number of questions asked during the quiz.
#define ANSCOUNT 3          // Number of possible answers displayed.
#define MINANS ANSCOUNT+1   // Minimum number of alternatives.
#define MAXANS ANSCOUNT+3   // Maximum number of alternatives.

using namespace std;

Quiz::Quiz(){}

/**
 * Clears the question pool.
 */
void Quiz::clear(){
    if(questionnaire.empty()){
        cout << "The question pool is empty. There is nothing to erase.\n" << endl;
    }
    else{
        questionnaire.erase(questionnaire.begin(),questionnaire.end());
        cout << "The question pool was cleared.\n" << endl; 
    }
}

/**
 * Add a question to the questionnaire with prompts for the user.
 */
void Quiz::addQuestion(){
    Question temp;
    string prompt;
    string buff;
    vector<string> answers;
    int correctAns;

    cout << "Please enter the prompt from the question:" << endl;
    getline(cin, prompt);
    while(prompt.empty()){
        cout << "You cannot enter an empty prompt." << endl;
        getline(cin, prompt);
    }
    
    cout << "\n" << "Enter " << MINANS << " to " << MAXANS << " alternative questions, enter \".\" to finish" << endl;

    // This loop reads possible answers until "." is entered.
    // If the number of answers is outside of the limits defined by MINANS and MAXANS it asks the user
    // to enter answers again.
    do{
        getline(cin, buff);
        while(buff.compare(".") != 0){
            if (buff.empty()){
                cout << "You cannot enter an empty prompt." << endl;
            }
            else{
                answers.push_back(buff);
            }
            getline(cin, buff);
        }
        if (answers.size() < MINANS || answers.size() > MAXANS){
            cout << "You need to enter " << MINANS <<" to " << MAXANS << " alternatives." << endl;
            answers.erase(answers.begin(), answers.end());
        }
    }while(answers.size() < MINANS || answers.size() > MAXANS);

    // Displays answers enterd by the user and asks him to select the correct one.
    cout << "Your answers are :" << endl;
    for (size_t i = 0; i < answers.size(); i++){
        cout << i+1 << ") " << answers[i] << endl;
    }
    cout << "Enter number of the correct answer. (1-" << answers.size() << ")" << endl;
    readUserInt(cin, correctAns, 1, answers.size());
    cout << endl;

    // Add question to the question pool if it is unique.
    temp = Question(prompt, answers, correctAns-1);
    if(find(questionnaire.begin(), questionnaire.end(), temp) == questionnaire.end()){
            questionnaire.push_back(temp);
        }
    else{
        cout << "Question wasn't added because it is already in the pool." << endl;
    }
}

/**
 * Asks the user QUIZLEN questions in random order without repeating.
 * If there are not enough questions in the pool it displays an error.
 */
void Quiz::play(){
    if(questionnaire.size() < QUIZLEN){
        cout << "There need to be at least " << QUIZLEN << " questions to start the quiz. Please add more to play.\n" << endl;
    }
    else{
        cout << "So you have chosen death.\n" << endl;
        random_device rd;
        mt19937 mt(rd());
        shuffle(questionnaire.begin(), questionnaire.end(), mt);

        int correctCount = 0;

        for (int i = 0; i < QUIZLEN; i++){
            if(questionnaire[i].ask(ANSCOUNT)){
                correctCount++;
            }
            cout << endl;
        }
        cout << "Your score is " << correctCount << "/" << QUIZLEN << " points\n" << endl;
    }
}

/**
 * Prints the whole question pool in a readable format.
 */
void Quiz::printQs(){
    if(questionnaire.empty()){
        cout << "The questionnaire is empty, thus no questions can be displayed.\n" << endl;
    }
    else{ 
        cout << "Questions in the pool:" << endl;
        int i = 1;
        for (auto q : questionnaire){
            cout << setw(2) << i++ << ") ";
            q.toStringReorder(cout, 5);
            cout << endl;
        }
    }
}

/**
 * Writes question to the outputstream in a readable format.
 * @param ofs Output stream to which we write the info.
 * @return bool value depending on if writing was successful.
 */
bool Quiz::writeQs(ostream &ofs){
    if(questionnaire.empty()){
        cout << "The questionnaire is empty, thus no questions are written.\n" << endl;
        return false;
    }
    else{   
        cout << "Writing to file\n" << endl;
        for (size_t i = 0; i < questionnaire.size(); i++){
            ofs << questionnaire[i];
            if(i != questionnaire.size()-1){
                ofs << endl;
            }
        }
        return true;
    }
}

/**
 * Read questions from the input stream and display error information describing where the issue was 
 * encountered so it is easier to locate and correct the incorrect value in the file.
 * @param ifs Input stream from which we are reading the information.
 * @return bool value depending on if reading was successful.
 */
bool Quiz::readQs(std::istream &ifs){
    Question temp;
    string prompt;
    string buff;
    vector<string> answers;
    int correctAns;
    int ansCount;

    int fileQuestionCount = 1;
    while(!ifs.eof()){
        if(!getline(ifs, prompt)){
            cout << "Error reading question prompt at question " << fileQuestionCount << ".\n" << endl;
            return false;
        }

        if(!(ifs >> ansCount)){
            cout << "Error reading answer count at question " << fileQuestionCount << ".\n" << endl;
            return false;
        }
        else {
            if(ansCount > MAXANS){
                cout << "Error reading answer count at question " << fileQuestionCount << endl;
                cout <<"The maximum number of possible answers is " << MAXANS << ".\n" << endl;
                return false;
            }
            else if(ansCount < MINANS){
                cout << "Error reading answer count at question " << fileQuestionCount << endl;
                cout <<"You need to include at least " << MINANS << " possible answers.\n" << endl;
                return false;    
            }
        }
        ifs.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        for(int i = 0; i < ansCount; i++){
            if(!getline(ifs, buff)){
                cout << "Error reading answer " << i+1 <<" at question " << fileQuestionCount << ".\n" << endl;
                return false;
            }
            answers.push_back(buff);
        }

        if(!(ifs >> correctAns)){
            cout << "Error reading correct answer index at question " << fileQuestionCount << ".\n" << endl;
            return false;
        }
        else if(correctAns < 0 || correctAns >= ansCount){
            cout << "Error reading answer count at question " << fileQuestionCount << endl;
            cout <<"The answer index for question " << fileQuestionCount << " has to be in range from 0 to " << ansCount-1 << ".\n" << endl;
            return false;    
        }
        ifs.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        // Check if question is already in the pool.
        temp = Question(prompt, answers, correctAns);
        if(find(questionnaire.begin(), questionnaire.end(), temp) == questionnaire.end()){
            questionnaire.push_back(temp);
        }
        else{
            cout << "Question " << fileQuestionCount << " is already in the pool. Skipping duplicate." << endl;
        }
        answers.erase(answers.begin(), answers.end());
        ++fileQuestionCount;
        ifs.peek();
    }
    cout << "File read successfully!\n" << endl;
    return true;
}

/**
 * Static function I used for reading and validating user Integer input. 
 * Contains optional parameters for setting the range of integers which should be accepted.
 * @param is Input stream from which integers are read.
 * @param dest Reference to where the integer is stored
 * @param rangeMin Optional parameter which sets the lower limit of the range.
 * @param rangeMax Optional parameter which sets the higher limit of the range.
 */ 
void Quiz::readUserInt(istream& is, int& dest, int rangeMin, int rangeMax){
    if(rangeMin == 0 && rangeMax == 0){
        is >> dest;
        while(!is){
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "please enter a valid number: ";
                is >> dest;
        }
    }
    else{
        is >> dest;
        while(!is || dest < rangeMin || dest > rangeMax){
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "please enter a valid number: ";
                is >> dest;
        }
    }
    is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

// If overloading >> is necessary
// /**
//  * Function to read questions until an error occurs during reading. 
//  * Does not print any error information.
//  * @param ifs Input stream from which we are reading the information.
//  * @return bool value depending on if reading was successful.
//  */
// bool Quiz::readQs(std::istream &ifs){
//     Question temp;

//     while(ifs >> temp){
//         questionnaire.push_back(temp);
//     }
//     if(ifs)
//         return true;
//     else
//         return false;
// }