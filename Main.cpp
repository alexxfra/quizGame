#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "headers/Quiz.hpp"
#include "headers/Question.hpp"

using namespace std;

void printInfo();

int main(){
    Quiz q;
    fstream file;
    int userInput;
    string filename = "output.txt";
    cout << "**************************************************" << endl;
    cout << "Welcome to Alex's \"great\" quiz!" << endl;
    cout << "**************************************************" << endl;

    while(true){
        printInfo();
        cin >> userInput;
        while(!cin || userInput < 1 || userInput > 6){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "please enter a valid number: ";
                cin >> userInput;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        switch (userInput)
        {
        case 1:
            q.play();
            break;
        
        case 2:
            q.addQuestion();
            break;
        
        case 3:
            q.printQs();
            break;
        
        case 4:
            file.open(filename, ios::in);
            q.readQs(file);
            file.close();
            break;

        case 5:
            file.open(filename, ios::out);
            q.writeQs(file);
            file.close();
            break;

        case 6:
            q.clear();
            cout << "Wiped the question pool \n" << endl;
            break;

        default:
            break;
        }
    }

    

    return 0;
}

void printInfo(){
    cout << "**************************************************" << endl;
    cout << "1.) Start the quiz." << endl;
    cout << "2.) Add a question." << endl;
    cout << "3.) Print current question pool." << endl;
    cout << "4.) Import questions from a file." << endl;
    cout << "5.) Save questions to a file." << endl;
    cout << "6.) Erase question pool." << endl;
    cout << "**************************************************" << endl;
    cout << "Choose (1-6): ";
}