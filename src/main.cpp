// main.cpp

#include <iostream>
#include "./frontend_parser/lexer.hpp"

class EvaluationWrapper
{
private:
    Lexer *MAIN_LEXER;

public:
    EvaluationWrapper()
    {
        MAIN_LEXER = new Lexer();
    }

    void handle(const std::string &InputBuffer)
    {
        // std::cout << ">> INPUTBUFFER INSIDE EvaluationWrapper CLASS <<" << std::endl;

        MAIN_LEXER->initialize(InputBuffer);

        MAIN_LEXER->tokenize(InputBuffer);
    }
};

// MAIN FUNCTION - ENTRY POINT //
int main()
{
    // std::cout << ">> THIS MESSAGE IS FROM main FILE <<" << std::endl;

    std::string InputBuffer;

    // CREATING AN INSTANCE OF THE LEXER CLASS //
    // Lexer mainLexer;
    EvaluationWrapper *mainIO = new EvaluationWrapper();

    while (true)
    {
        std::cout << "ClangDB: ";

        std::getline(std::cin, InputBuffer);

        mainIO->handle(InputBuffer);

        // std::cout << "THIS IS THE INPUT BUFFER: " << InputBuffer << std::endl;
    }

    return 0;
}

// Command For Compiling and Running The Code:=>
// cls && g++ main.cpp frontend_parser/lexer.cpp -Ifrontend_parser -o main && main