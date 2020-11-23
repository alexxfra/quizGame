#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Question
{
    friend std::ostream &operator<<(std::ostream &os, const Question &q);
    friend std::istream &operator>>(std::istream &os, Question &q);
    private:
        std::string prompt;
        std::vector<std::string> answers;
        int ansCount;
        int correctIndex;
    public:
        Question(const std::string prompt = "testPrompt", const std::vector<std::string>& ans = std::vector<std::string>(4), const int index = 0);
        void toString(std::ostream &os, const int qOffset);
        void toStringReorder(std::ostream &os, const int qOffset);
        bool ask(const int ansNo);
};