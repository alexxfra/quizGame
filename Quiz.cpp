#include <iostream>
#include <limits>
#include "headers/Quiz.hpp"

#define QSIZE 2

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
    int ansIndex;

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
        if (answers.size() < QSIZE)
        {
            cout << "You need to enter at least " << QSIZE << " alternatives" << endl;
            answers.erase(answers.begin(), answers.end());
        }
    }while(answers.size() < QSIZE);

    cout << "Your answers are :" << endl;
    for (int i = 0; i < answers.size(); i++){
        cout << i+1 << ") " << answers[i] << endl;
    }
    cout << "Enter number of the correct answer. (1-" << answers.size() << ")" << endl;
    cin >> ansIndex;
    if(!cin || ansIndex > answers.size() || ansIndex < 1){
        do{
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "please enter a valid number" << endl;
            cin >> ansIndex;
        }while(!cin || ansIndex > answers.size() || ansIndex < 1);
    }

    cout << endl;
    questionnaire.push_back(Question(prompt, answers, ansIndex-1));
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void Quiz::start(){

}

void Quiz::printQs(){
    if(questionnaire.empty()){
        cout << "The questionnaire is empty, thus no questions can be displayed.\n" << endl;
    }
    else{   
        for (int i = 0; i < questionnaire.size(); i++){
            cout << questionnaire[i] << "\n" << endl;
        }
    }
}
