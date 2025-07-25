// lexer.hpp

// HEADER GUARD //
#ifndef __LEXER_HPP
#define __LEXER_HPP

#include <iostream>
#include <string>

// CLASS FOR LEXER //
class Lexer
{
private:
    int cursor;
    int length;

public:
    enum class TOKEN_SET
    {
        TOKEN_INSERT,
        TOKEN_INTO,

        // <TABLE_NAME / DB_NAME> //
        TOKEN_ID,

        TOKEN_VALUE
    };

    // DECLARING THE MAIN LEXER CONSTRUCTOR //
    Lexer();

    // DECLARING THE handle METHOD //
    // void handle(const std::string &InputBuffer);

    void initialize(const std::string &InputBuffer);

    void tokenize(const std::string &InputBuffer);
};

#endif