#include <iostream>
#include "headers/Quiz.hpp"

using namespace std;

Quiz::Quiz() : questionnaire(){}

void Quiz::clear(){
    questionnaire.erase(questionnaire.begin(),questionnaire.end());
}

void Quiz::addQuestion(){
    string prompt;
    string buff;
    vector<string> answers;
    int ansIndex;

    cout << "Please enter the prompt from the question:" << endl;
    getline(cin, prompt);
    
    cout << "\n" << "Enter alternatives, enter . to finish" << endl;
    getline(cin, buff);
    while(buff.compare(".") != 0){
        answers.push_back(buff);
        getline(cin, buff);
    }

    cout << "Your answers are :" << endl;
    for (int i = 0; i < questionnaire.size(); i++){
        cout << "#" << i+1 << answers[i] << endl;
    }
    cout << endl;
    cout << "Enter number of the correct answer:";
    do{
        cin >> ansIndex;
    }while(ansIndex > questionnaire.size() || ansIndex <= 0);

    questionnaire.push_back(Question(prompt, answers, ansIndex-1));
}

void Quiz::start(){

}

void Quiz::printQs(){
    for (int i = 0; i < questionnaire.size(); i++){
        questionnaire[i].toString();
        cout << endl;
    }
    
}
