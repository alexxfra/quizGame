#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "headers/Quiz.hpp"
#include "headers/Question.hpp"

using namespace std;


int main(){
    Quiz q;
    fstream file;
    file.open("output.txt", ios::in);
    int userInput;

    cout << "**************************************************" << endl;
    cout << "Welcome to Alex's \"great\" quiz!" << endl;

    while(true){
        cin >> userInput;
        while(!cin || userInput < 1 || userInput > 6){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "please enter a valid number." << endl;
                cin >> userInput;
        }
        switch (userInput)
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
    }

    

    return 0;
}