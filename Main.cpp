#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "headers/Quiz.hpp"
#include "headers/Question.hpp"

using namespace std;

void printInfo();

int main(int argc, char** argv){
    Quiz q;
    fstream file;
    string filename;
    int userInput;

    cout << "**************************************************" << endl;
    cout << "Welcome to Alex's \"great\" quiz!" << endl;
    cout << "**************************************************" << endl;

    // Open file with argument as path.
    if(argc == 2){
        file.open(argv[1], ios::in);
        if(!file.is_open()){
            cout << "File does not exist or there was an error while opening it." << endl;
            cout << "Creating empty file" << endl;
            file.open(argv[1], ios::out);
            if(!file.is_open()){
                cout << "Error creating file.\n" << endl;
            }
            else{
                file.close();
            }
        }
        else{
            q.readQs(file);
            file.close();
        }
    }

    // Simple game loop.
    while(true){
        printInfo();
        Quiz::readUserInt(cin, userInput, 1, 7);
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
            // File name and input validation.
            cout << "Please enter file path: ";
            if(!(cin >> filename)){
                cout << "Error reading filename.\n" << endl;
                break;
            }

            // If the file does not exist ask the user if he still wants to create it.
            // If he does create an empty file.
            file.open(filename, ios::in);
            if(!file.is_open()){
                cout << "File does not exist." << endl;
                cout << "Do you want to create a new file? (1/0):";
                Quiz::readUserInt(cin, userInput, 0, 1);
                if(!userInput){
                    cout << "No questions were added to the pool.\n" << endl;
                    break;
                }
                else{
                    file.open(filename, ios::out);
                    if(!file.is_open()){
                        cout << "Error creating file.\n" << endl;
                        break;
                    }
                    else{
                        cout << "File was created. Add questions by modifying the file yourself, " << endl;
                        cout << "or use the second option in the menu and save to file afterwards.\n" << endl;
                        file.close();
                        break;
                    }
                }
            }
            
            q.readQs(file);
            file.close();
            break;

        case 5:
            // Writing to file.
            cout << "Please enter file path: ";
            if(!(cin >> filename)){
                cout << "Error reading filename.\n" << endl;
                break;
            }

            file.open(filename, ios::out);
            if(!file.is_open()){
                cout << "Error opening file.\n" << endl;
                break;
            }
            q.writeQs(file);
            file.close();
            break;

        case 6:
            // Clearing the question pool.
            q.clear();
            break;
        
        case 7:
            cout << "Exitting program." << endl;
            exit(0);
            break;

        default:
            cout << "Error in the game loop." << endl;
            exit(1);
            break;
        }
    }

    

    return 0;
}

/**
 * Information that is printed with every game loop iteration
 */
void printInfo(){
    cout << "**************************************************" << endl;
    cout << "1.) Start the quiz." << endl;
    cout << "2.) Add a question." << endl;
    cout << "3.) Print current question pool." << endl;
    cout << "4.) Import questions from a file." << endl;
    cout << "5.) Save questions to a file." << endl;
    cout << "6.) Erase question pool." << endl;
    cout << "7.) Exit." << endl;
    cout << "**************************************************" << endl;
    cout << "Choose (1-7): ";
}