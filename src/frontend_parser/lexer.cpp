// lexer.cpp

#include <iostream>
#include "lexer.hpp"

// DEFINING THE LEXER CONSTRUCTOR //
Lexer::Lexer() {}

// ------------------------------------------------------------------------- //
// PRIVATE SCOPED METHODS:

std::string Lexer::tokenTypeToString(TOKEN_SET REQUIRED_TOKEN)
{
    switch (REQUIRED_TOKEN)
    {
    case TOKEN_SET::TOKEN_INSERT:
        return "TOKEN_INSERT";

    case TOKEN_SET::TOKEN_INTO:
        return "TOKEN_INTO";

    case TOKEN_SET::TOKEN_STRING:
        return "TOKEN_STRING";

    case TOKEN_SET::TOKEN_VALUE:
        return "TOKEN_VALUE";

    case TOKEN_SET::TOKEN_LEFT_PAREN:
        return "TOKEN_LEFT_PAREN";

    case TOKEN_SET::TOKEN_INT:
        return "TOKEN_INT";

    case TOKEN_SET::TOKEN_RIGHT_PAREN:
        return "TOKEN_RIGHT_PAREN";
    }

    return ">> [!!] WARNING: UNKNOWN_TOKEN_FOUND: " + std::to_string(static_cast<int>(REQUIRED_TOKEN));
}

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

bool Lexer::isDigit(char current)
{
}

TOKEN Lexer::tokenizeDigit()
{
}

void Lexer::displayAllTokens()
{
    int counter = 0;

    for (TOKEN CURRENT_TOKEN : TOKEN_LIST)
    {
        std::cout << ++counter << ".) " << CURRENT_TOKEN.VALUE << " ";

        std::cout << tokenTypeToString(CURRENT_TOKEN.TOKEN_TYPE) << std::endl;
    }
}

// ------------------------------------------------------------------------- //
// PUBLIC SCOPED METHODS:

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

    while (current != '\0')
    {
        skipWhitespaces(); // SPACE, TAB, NEWLINE → WHITESPACE CHARACTERS //

        if (isAlpha(current))
        {
            TOKEN_LIST.push_back(tokenizeAlpha());
        }
        else if (isDigit(current))
        {
            TOKEN_LIST.push_back(tokenizeDigit());
        }
        else
        {
            advance(); // Move to next character if not alpha
        }
    }

    displayAllTokens();
}
