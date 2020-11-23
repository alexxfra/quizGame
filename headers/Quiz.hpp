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
        void play();
        void printQs();
        bool writeQs(std::ostream &ofs);
        bool readQs(std::istream &ifs);
        static void readUserInt(std::istream& is, int& dest, int rangeMin = 0, int rangeMax = 0);
};