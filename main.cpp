#include <iostream>
#include "lexer.hpp"
#include "token.hpp"
#include "char_utils.hpp"

class EvaluationWrapper
{
private:
    Lexer mainLexer;

public:
    void processInput(const std::string &InputBuffer)
    {
        mainLexer.initialize(InputBuffer);
        
        mainLexer.tokenize();
    }

    // TODO: CHECK
    const std::vector<TOKEN> &getTokens() const
    {
        return mainLexer.getTokens();
    }
};

// MAIN FUNCTION - ENTRY POINT //
int main()
{
    std::string InputBuffer;

    // CREATING AN INSTANCE OF THE EvaluationWrapper CLASS //
    EvaluationWrapper processor;

    std::cout << "ClangDB Lexer - Type ':qw' to quit\n"
              << std::endl;

    while (true)
    {
        std::cout << "ClangDB: ";

        std::getline(std::cin, InputBuffer);

        if (InputBuffer == ":qw")
            break;

        processor.processInput(InputBuffer);
    }

    return 0;
}

// Command For Compiling and Running The Code:=>
// cls && g++ main.cpp lexer.cpp token.cpp char_utils.cpp -o main && main
