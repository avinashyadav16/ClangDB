#include <iostream>
#include "lexer.hpp"
#include "token.hpp"
#include "char_utils.hpp"

class EvaluationWrapper
{
private:
    Lexer mainLexer;
    int commandCounter;

public:
    EvaluationWrapper() : commandCounter(0) {}

    LEXER_STATUS processInput(const std::string &InputBuffer)
    {
        mainLexer.initialize(InputBuffer);

        commandCounter++;

        return mainLexer.tokenize();
    }

    // TODO: CHECK
    const std::vector<TOKEN> &getTokens() const
    {
        return mainLexer.getTokens();
    }

    int getCommandCounter() const
    {
        return commandCounter;
    }
};

// MAIN FUNCTION - ENTRY POINT //
int main()
{
    std::string InputBuffer;

    // CREATING AN INSTANCE OF THE EvaluationWrapper CLASS //
    EvaluationWrapper processor;

    std::cout << R"(
                +======================================+
                |         Welcome to ClangDB           |
                |         Type ':qw' to quit           |
                +======================================+
                )"
              << std::endl;

    while (true)
    {
        std::cout << "ClangDB: ";

        std::getline(std::cin, InputBuffer);

        if (InputBuffer == ":qw")
            break;

        LEXER_STATUS status = processor.processInput(InputBuffer);

        // TODO: Add colours to success and fail prompt
        if (status == LEXER_STATUS::LEXER_SUCCESS)
        {
            std::cout << "$ Command ID -> " << processor.getCommandCounter() << " executed in 0.48ms" << std::endl;
        }
        else if (status == LEXER_STATUS::LEXER_ERROR)
        {
            std::cout << "$ Command ID -> " << processor.getCommandCounter() << " failed in 0.2ms" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

// Command For Compiling and Running The Code:=>
// cls && g++ main.cpp lexer.cpp token.cpp char_utils.cpp -o main && main

// 1:50:28