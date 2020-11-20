#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Question
{
    friend std::ostream &operator<<(std::ostream& os, const Question &q);
    private:
        std::string prompt;
        std::vector<std::string> answers;
        int correctIndex;
    public:
        Question(const std::string prompt = "testPrompt", const std::vector<std::string>& ans = std::vector<std::string>(4), const int index = 0);
        void setPrompt(const std::string newPrompt);
        void setAnswers(const std::vector<std::string>& newAnswers);
        void setIndex(const int newIndex);
        void toString();
};