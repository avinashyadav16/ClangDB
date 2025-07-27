// lexer.hpp

// HEADER GUARD //
#ifndef __LEXER_HPP
#define __LEXER_HPP

#include <iostream>
#include <string>
#include <vector>

enum class TOKEN_SET
{
    TOKEN_INSERT,
    TOKEN_INTO,
    TOKEN_STRING, // <TABLE_NAME /or DB_NAME> //
    TOKEN_VALUE,
    TOKEN_LEFT_PAREN,
    TOKEN_INT,
    TOKEN_RIGHT_PAREN
};

struct TOKEN
{
    TOKEN_SET TOKEN_TYPE;
    std::string VALUE;
};

// CLASS FOR LEXER //
class Lexer
{
private:
    // DATA MEMBERS //
    std::string localInputBuffer;
    int cursor;
    char current;
    int length;
    std::vector<TOKEN> TOKEN_LIST;

    // MEMBER METHOD //
    char advance();

    void skipWhitespaces();

    bool isAlpha(char current);

    TOKEN tokenizeAlpha();

    void displayAllTokens();

public:
    // DECLARING THE MAIN LEXER CONSTRUCTOR //
    Lexer();

    void initialize(const std::string &);

    void tokenize();
};

#endif
