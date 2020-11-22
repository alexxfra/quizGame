#include <iostream>
#include <limits>
#include "headers/Quiz.hpp"

//Maybe change to console arguments !!!!  
#define MINANS 2
#define MAXANS 5
#define QUIZLEN 1

using namespace std;

Quiz::Quiz() : questionnaire(){}

void Quiz::clear(){
    questionnaire.erase(questionnaire.begin(),questionnaire.end());
}

/**
 * Add a question to the questionnaire with prompts for the user.
 */
void Quiz::addQuestion(){
    string prompt;
    string buff;
    vector<string> answers;
    int correctAns;

    cout << "**************************************************" << endl;
    cout << "Please enter the prompt from the question:" << endl;
    getline(cin, prompt);
    
    cout << "\n" << "Enter alternative questions, enter \".\" to finish" << endl;
    do{
        getline(cin, buff);
        while(buff.compare(".") != 0){
            answers.push_back(buff);
            getline(cin, buff);
        }
        if (answers.size() < MINANS || answers.size() > MAXANS){
            cout << "You need to enter " << MINANS <<" to " << MAXANS << " alternatives" << endl;
            answers.erase(answers.begin(), answers.end());
        }
    }while(answers.size() < MINANS || answers.size() > MAXANS);

    cout << "Your answers are :" << endl;
    for (int i = 0; i < answers.size(); i++){
        cout << i+1 << ") " << answers[i] << endl;
    }
    cout << "Enter number of the correct answer. (1-" << answers.size() << ")" << endl;
    cin >> correctAns;
    while(!cin || correctAns > answers.size() || correctAns < 1){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "please enter a valid number." << endl;
            cin >> correctAns;
    }

    cout << endl;
    questionnaire.push_back(Question(prompt, answers, correctAns-1));
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void Quiz::play(){
    if(questionnaire.size() < QUIZLEN){
        cout << "There are not enough questions in the question pool. Please add more to play." << endl;
    }
    else{
        int userAns;
        int correctCount = 0;

        for (int i = 1; i <= QUIZLEN; i++){
            questionnaire[i-1].toString(cout);
            cout << "Enter yout answer: ";
            cin >> userAns;
            while(!cin || userAns <= 0 || userAns > questionnaire[i-1].getAnsCount()){
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    cout << "please enter a valid option." << endl;
                    cin >> userAns;
            }
            if(questionnaire[i-1].checkAns(userAns)){
                correctCount++;
            }
            cout << endl;
        }
        cout << "Your score is " << correctCount << "/" << QUIZLEN << " points" << endl;
    }
}

void Quiz::printQs(){
    if(questionnaire.empty()){
        cout << "The questionnaire is empty, thus no questions can be displayed.\n" << endl;
    }
    else{   
        for (int i = 0; i < questionnaire.size(); i++){
            questionnaire[i].toString(cout);
            cout << endl;
        }
    }
}

void Quiz::writeQs(ostream &ofs){
    if(questionnaire.empty()){
        cout << "The questionnaire is empty, thus no questions are written.\n" << endl;
    }
    else{   
        for (int i = 0; i < questionnaire.size(); i++){
            ofs << questionnaire[i];
            if(i != questionnaire.size()-1){
                ofs << endl;
            }
        }
    }
}

bool Quiz::readQs(std::istream &ifs){
    string prompt;
    string buff;
    vector<string> answers;
    int correctAns;
    int ansCount;

    while(!ifs.eof()){
        if(!getline(ifs, prompt)){
            cout << "Error reading question prompt at question " << questionnaire.size()+1 << endl;
            return false;
        }

        if(!(ifs >> ansCount)){
            cout << "Error reading answer count at question " << questionnaire.size()+1 << endl;
            return false;
        }
        ifs.clear();
        ifs.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        for(int i = 0; i < ansCount; i++){
            if(!getline(ifs, buff)){
                cout << "Error reading answer " << i+1 <<" at question " << questionnaire.size()+1 << endl;
                return false;
            }
            answers.push_back(buff);
        }

        if(!(ifs >> correctAns)){
            cout << "Error reading correct answer index at question " << questionnaire.size()+1 << endl;
            return false;
        }
        ifs.clear();
        ifs.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        questionnaire.push_back(Question(prompt, answers, correctAns));
        answers.erase(answers.begin(), answers.end());
    }
    return true;
}

