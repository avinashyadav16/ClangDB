#include <iostream>
#include "./frontend_parser/lexer.hpp"


// MAIN FUNCTION - PROGRAM ENTRY POINT //
int main()
{
    std::cout << ">> THIS MESSAGE IS FROM MAIN FILE <<" << std::endl;

    // CREATING AN INSTANCE OF THE LEXER CLASS //
    Lexer mainLexer;

    return 0;
}


// Command For Compiling and Running The Code:=>
// cls && g++ main.cpp frontend_parser/lexer.cpp -Ifrontend_parser -o main && main