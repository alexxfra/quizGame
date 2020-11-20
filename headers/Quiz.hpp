#pragma once
#include <vector>
#include "Question.hpp"

class Quiz
{
    private:
        std::vector<Question> questionnaire;
    public:
        Quiz();
        void clear();
        void addQuestion();
        void start();
        void printQs();
};