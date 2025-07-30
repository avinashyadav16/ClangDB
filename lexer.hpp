// HEADER/INCLUDE GUARD: to prevent the multiple inclusion of a header file within a single compilation unit. //
#ifndef LEXER_HPP
#define LEXER_HPP
// may shift to '#pragma once' later

#include "token.hpp"
#include <string>
#include <vector>

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

    char peek();

    bool isAtEnd();

    void skipWhitespaces();

    TOKEN createStringToken();

    TOKEN createNumberToken();

    LEXER_STATUS throwLexerError();

    TOKEN createSymbolToken();

    TOKEN_SET getKeywordType(const std::string &word);

    void displayAllTokens();

public:
    // DECLARING THE MAIN LEXER CONSTRUCTOR //
    Lexer();

    void initialize(const std::string &inputBuffer);

    LEXER_STATUS tokenize();

    const std::vector<TOKEN> &getTokens() const;
};

#endif