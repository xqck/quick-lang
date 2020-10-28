// quick-lang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "common.h"

void InitiateTranslator();
void FormatSource(std::string sourceCode);
void SourceAnalyser(std::vector<std::string> lines, std::vector<std::vector<std::string>> lineWords);
void FinishedTranslation();

int main()
{
    InitiateTranslator();
}

void FinishedTranslation() {
    wl("$$Finished Program Translation \n");
    for (size_t i = 0; i < globalVariables.size(); i++)
    {
        wl("---> var " << i << ":");
        wl("->type  : " << globalVariables[i][0]);
        wl("->name  : " << globalVariables[i][1]);
        wl("->value : " << globalVariables[i][2] << "\n");
    }
    wl("$$Ending Translator.");
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

    FormatSource("int sizeOfUrMum : 100;"); // this will contain the source code, currently going to have dummy code to debug with.
}

void FormatSource(std::string sourceCode) { // Formats the code so that it is easier to process later.
    std::vector<std::string> lines = SplitString(sourceCode, ';');
    std::vector<std::vector<std::string>> wordsEachLine;

    for (size_t i = 0; i < lines.size(); i++)
    {
        std::vector<std::string> words = SplitString(lines[i], ' ');
        std::vector<std::string> wordsa;

        for (size_t i2 = 0; i2 < words.size(); i2++)
        {
            if (words[i2] != "") {
                wordsa.push_back(words[i2]);
            }
        }
        
        wordsEachLine.push_back(wordsa);
    }
    SourceAnalyser(lines, wordsEachLine);
}


// lines = vector with each index being a line
// lineWords = vector with each index being an individual words in a line
void SourceAnalyser(std::vector<std::string> lines, std::vector<std::vector<std::string>> lineWords) {
    for (size_t eachLine = 0; eachLine < lineWords.size(); eachLine++) // currently work in progress.
    {
        for (size_t eachLineValue = 0; eachLineValue < lineWords[eachLine].size(); eachLineValue++)
        {
            std::string containVariableDeclaration = CheckIfInVector(lineWords[eachLine][eachLineValue], dataTypes);  // Checks if any variable declaration is in the line
            if (containVariableDeclaration != "" && eachLineValue == 0) // Checks if there is a variable declaration at the start of the line (my translator only allows start delcaration)
            {       
                std::string varName = lineWords[eachLine][eachLineValue + 1]; // Finds the variable name
                std::string containKeyword = CheckIfInVector(lineWords[eachLine][eachLineValue + 2], keywords); // Sees if it contains any keywords
                std::string containKeyword2 = CheckIfInVector(lineWords[eachLine][eachLineValue + 2], dataTypes); // Sees if it contains any keywords2
                if (containKeyword2 == "") // If there are any datatype declaration
                {
                    if (containKeyword == ":") // Checks for : / the variable setter
                    {
                        if (CharacterCount(lines[eachLine], ':') > 1) { // Checks for the amount of : so it doesnt mess with future variable uses
                            wl("error1"); // throws error with more than one variable declarer
                        }
                        else {
                            int varDev = FindIndexInVector(lineWords[eachLine], containVariableDeclaration); // Finds where the variable declaration is
                            int location = FindIndexInVector(lineWords[eachLine], ":"); // Find the location of the declarer

                            if (lineWords[eachLine][varDev + 1] == lineWords[eachLine][location - 1]) { // Checks if the value in front of the variable declaration and the declarer is the same, if it is then it is the variable name.

                                std::string varName = lineWords[eachLine][varDev + 1]; // If all checks are passed then that variable name must be infront of the variable declarator 

                                std::vector<std::string> variableMetaData; // Sets the metadata for the variable with includes the [datatype, name, and value] in this order.
                                variableMetaData.push_back(containVariableDeclaration); // Passes the variable datatype
                                variableMetaData.push_back(varName); // Passes the variable name
                                // Working on the variable value.

                                if (lineWords[eachLine][location + 1] == lineWords[eachLine][lineWords[eachLine].size() - 1]) { // Checks if the value of the value infront of the declarer is the same as the end of line - 1 is which is how you declare variables.
                                    variableMetaData.push_back(lineWords[eachLine][location + 1]);
                                }
                                else {
                                    wl("error0");
                                }


                                globalVariables.push_back(variableMetaData); // Pushes the metadata into the global variable list
                            }
                            else {
                                wl("error2"); // Throws errors, will add better error handling in the future.
                            }
                        }
                    }
                    else {
                        wl("error3");
                    }
                }
                else {
                    wl("error4");
                }
            }
            else {
                
            }
        }
    }
    FinishedTranslation();
}