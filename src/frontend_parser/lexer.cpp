// lexer.cpp

#include <iostream>
#include "lexer.hpp"

// DEFINING THE LEXER CONSTRUCTOR //
Lexer::Lexer() {}

// ------------------------------------------------------------------------- //

char Lexer::advance()
{
    // IF WE ARE AT THE END OF THE INPUT //
    if (cursor == length - 1)
    {
        // RETURNING THE NULL CHARACTER FOR END-OF-FILE //
        current = '\0';

        return current;
    }
    else
    {
        current = localInputBuffer[++cursor];

        return current;
    }
}

void Lexer::skipWhitespaces()
{
    while (current == ' ' && current != '\0')
    {
        advance();
    }
}

bool Lexer::isAlpha(char current)
{
    return (current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z');
}

TOKEN Lexer::tokenizeAlpha()
{
    TOKEN newToken;
    std::string tempBuffer = "";

    while (isAlpha(current))
    {
        tempBuffer.push_back(current);

        advance();
    }

    newToken.TOKEN_TYPE = TOKEN_SET::TOKEN_STRING;
    newToken.VALUE = tempBuffer;

    return newToken;
}

void Lexer::displayAllTokens()
{
    std::cout << "Tokens found: " << TOKEN_LIST.size() << std::endl;
    for (size_t i = 0; i < TOKEN_LIST.size(); i++)
    {
        std::cout << "Token " << i << ": " << TOKEN_LIST[i].VALUE << std::endl;
    }
}

// ------------------------------------------------------------------------- //

// INITIALIZING //
void Lexer::initialize(const std::string &inputBuffer)
{
    localInputBuffer = inputBuffer;
    cursor = 0;
    current = localInputBuffer[cursor];
    length = inputBuffer.size();
}

void Lexer::tokenize()
{
    skipWhitespaces(); // SPACE, TAB, NEWLINE → WHITESPACE CHARACTERS //

    while (current != '\0')
    {
        if (isAlpha(current))
        {
            TOKEN_LIST.push_back(tokenizeAlpha());
        }
        else
        {
            advance(); // Move to next character if not alpha
        }
    }

    displayAllTokens();
}