// lexer.cpp

#include <iostream>
#include "lexer.hpp"

// DEFINING THE LEXER CONSTRUCTOR //
Lexer::Lexer()
{
    // std::cout << ">> Initialising The Lexer..." << std::endl;
}

// DEFINING THE handle METHOD //
// void Lexer::handle(const std::string &InputBuffer)
// {
//     std::cout << ">> INPUTBUFFER INSIDE handle METHOD <<" << std::endl;
// }

void Lexer::initialize(const std::string &InputBuffer)
{
    cursor = 0;
    length = InputBuffer.size();
}

void Lexer::tokenize(const std::string &InputBuffer)
{
    std::cout << length << std::endl;
}