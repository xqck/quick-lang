// quick-lang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "common.h"

void InitiateTranslator();
void FormatSource(std::string sourceCode);
void SourceAnalyser(std::vector<std::vector<std::string>> lineWords);

int main()
{
    InitiateTranslator();
}

void InitiateTranslator() {

    // Defines all the datatypes.
    dataTypes.push_back("int");
    dataTypes.push_back("string");
    dataTypes.push_back("bool");
    dataTypes.push_back("float");

    // Soon going to add more important keywords.

    FormatSource("string kev : \" person \";"); // this will contain the source code, currently going to have dummy code to debug with.
}

void FormatSource(std::string sourceCode) { // Formats the code so that it is easier to process later.
    std::vector<std::string> lines = SplitString(sourceCode, ';');
    std::vector<std::vector<std::string>> wordsEachLine;

    for (size_t i = 0; i < lines.size(); i++)
    {
        std::vector<std::string> words = SplitString(lines[i], ' ');
        wordsEachLine.push_back(words);
    }
    SourceAnalyser(wordsEachLine);
}

void SourceAnalyser(std::vector<std::vector<std::string>> lineWords) {

}