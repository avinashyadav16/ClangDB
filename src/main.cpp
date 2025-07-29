// main.cpp

#include <iostream>
#include "./frontend_parser/lexer.hpp"

class EvaluationWrapper
{
private:
    Lexer mainLexer;

public:
    EvaluationWrapper() {}

    void handle(const std::string &InputBuffer)
    {
        mainLexer.initialize(InputBuffer);

        mainLexer.tokenize();
    }
};

// MAIN FUNCTION - ENTRY POINT //
int main()
{
    // std::cout << ">> THIS MESSAGE IS FROM main FILE <<" << std::endl;

    std::string InputBuffer;

    // CREATING AN INSTANCE OF THE EvaluationWrapper CLASS //
    EvaluationWrapper mainIO;

    while (true)
    {
        std::cout << "ClangDB: ";

        std::getline(std::cin, InputBuffer);

        mainIO.handle(InputBuffer);
    }

    return 0;
}

// Command For Compiling and Running The Code:=>
// cls && g++ main.cpp frontend_parser/lexer.cpp -Ifrontend_parser -o main && main