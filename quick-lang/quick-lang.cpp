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

    keywords.push_back(":");
    keywords.push_back(";");
    // Soon going to add more important keywords.

    FormatSource("string kev : persons;"); // this will contain the source code, currently going to have dummy code to debug with.
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
    for (size_t eachLine = 0; eachLine < lineWords.size(); eachLine++) // currently work in progress.
    {
        for (size_t eachLineValue = 0; eachLineValue < lineWords[eachLine].size(); eachLineValue++)
        {
            std::string containVariableDeclaration = CheckIfInVector(lineWords[eachLine][eachLineValue], dataTypes);
            if (containVariableDeclaration != "")
            {
                std::string varName = lineWords[eachLine][eachLineValue + 1];
                std::string containKeyword = CheckIfInVector(lineWords[eachLine][eachLineValue + 1], keywords);
                std::string containKeyword2 = CheckIfInVector(lineWords[eachLine][eachLineValue + 1], dataTypes);
                if (containKeyword2 == "")
                {
                    if (containKeyword == "")
                    {
                        
                    }
                    std::vector<std::string> variableMetaData;
                    variableMetaData.push_back(containVariableDeclaration);
                    variableMetaData.push_back("");
                }
                else {
                    wl("error");
                    return;
                }
                wl(containVariableDeclaration);
            }
        }
    }

}