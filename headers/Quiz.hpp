#pragma once
#include <vector>
#include <iostream>
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
        void writeQs(std::ostream &ofs);
        bool readQs(std::istream &ifs);
};