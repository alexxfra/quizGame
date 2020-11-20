#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Question
{
    private:
        std::string prompt;
        std::vector<std::string> answers;
        int correctIndex;
    public:
        Question(const std::string prompt, const std::vector<std::string>& ans, const int index);
        void setPrompt(const std::string newPrompt);
        void setAnswers(const std::vector<std::string>& newAnswers);
        void setIndex(const int newIndex);
        void toString();
};