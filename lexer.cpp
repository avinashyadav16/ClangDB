#include "lexer.hpp"
#include "char_utils.hpp"
#include "token.hpp"
#include <iostream>
#include <unordered_map>

// DEFINING THE LEXER CONSTRUCTOR //
Lexer::Lexer() : cursor(0), current('\0'), length(0) {}

void Lexer::initialize(const std::string &inputBuffer)
{
    localInputBuffer = inputBuffer;
    cursor = 0;
    current = localInputBuffer.empty() ? '\0' : localInputBuffer[0];
    length = inputBuffer.length();

    // to make each of the new command output clean by clearing previous output //
    TOKEN_LIST.clear();
}

char Lexer::advance()
{
    // IF WE ARE AT THE END OF THE INPUT //
    if (isAtEnd())
    {
        // RETURNING THE NULL CHARACTER FOR END-OF-FILE //
        current = '\0';
        return current;
    }

    cursor++;
    current = isAtEnd() ? '\0' : localInputBuffer[cursor];
    return current;
}

char Lexer::peek()
{
    if (cursor + 1 >= localInputBuffer.length())
        return '\0';
    return localInputBuffer[cursor + 1];
}

bool Lexer::isAtEnd()
{
    return cursor >= localInputBuffer.length();
}

void Lexer::skipWhitespaces()
{
    while (CharUtils::isWhitespace(current) && !isAtEnd())
    {
        advance();
    }
}

// Would have been fair enough to implement with `unordered_map` //
// but no issues for as of now
TOKEN_SET Lexer::getKeywordType(const std::string &word)
{
    if (word == "CREATE" || word == "create")
        return TOKEN_SET::TOKEN_CREATE;

    if (word == "NEW" || word == "new")
        return TOKEN_SET::TOKEN_NEW;

    if (word == "DATABASE" || word == "database")
        return TOKEN_SET::TOKEN_DATABASE;

    if (word == "TABLE" || word == "table")
        return TOKEN_SET::TOKEN_TABLE;

    if (word == "USE" || word == "use")
        return TOKEN_SET::TOKEN_USE;

    if (word == "INSERT" || word == "insert")
        return TOKEN_SET::TOKEN_INSERT;

    if (word == "INTO" || word == "into")
        return TOKEN_SET::TOKEN_INTO;

    if (word == "VALUE" || word == "value")
        return TOKEN_SET::TOKEN_VALUE;

    if (word == "DELETE" || word == "delete")
        return TOKEN_SET::TOKEN_DELETE;

    if (word == "FROM" || word == "from")
        return TOKEN_SET::TOKEN_FROM;

    if (word == "SEARCH" || word == "search")
        return TOKEN_SET::TOKEN_SEARCH;

    if (word == "IN" || word == "in")
        return TOKEN_SET::TOKEN_IN;

    if (word == "UPDATE" || word == "update")
        return TOKEN_SET::TOKEN_UPDATE;

    if (word == "WHERE" || word == "where")
        return TOKEN_SET::TOKEN_WHERE;

    if (word == "WITH" || word == "with")
        return TOKEN_SET::TOKEN_WITH;

    if (word == "EXIT" || word == "exit")
        return TOKEN_SET::TOKEN_EXIT;

    return TOKEN_SET::TOKEN_STRING;
}

TOKEN Lexer::createStringToken()
{
    std::string value;

    // First character must be alpha or underscore
    if (CharUtils::isAlpha(current) || current == '_')
    {
        value += current;
        advance();

        // Subsequent characters can be alphanumeric or underscore
        while ((CharUtils::isAlphaNumeric(current) || current == '_') && !isAtEnd())
        {
            value += current;
            advance();
        }
    }

    /*
    Creating a unordered_map of keywords and
    seaching the newToken.value over there
    can be one of the option in `getKeywordType()`
    */
    TOKEN_SET newToken = getKeywordType(value);
    return TOKEN(newToken, value);
}

TOKEN Lexer::createNumberToken()
{
    std::string value;

    while (CharUtils::isDigit(current) && !isAtEnd())
    {
        value += current;
        advance();
    }

    return TOKEN(TOKEN_SET::TOKEN_INTEGER, value);
}

void Lexer::throwLexerError()
{
    std::cout << "[!!!] LEXER ERROR: UNKNOWN_TOKEN_FOUND: TOKEN_UNKNOWN AT INDEX " << cursor << ": " << current << std::endl;

    // exit(0);
}

TOKEN Lexer::createSymbolToken()
{
    switch (current)
    {
    case '(':
        advance();
        return TOKEN(TOKEN_SET::TOKEN_LEFT_PAREN, "(");
    case ',':
        advance();
        return TOKEN(TOKEN_SET::TOKEN_COMMA, ",");
    case ')':
        advance();
        return TOKEN(TOKEN_SET::TOKEN_RIGHT_PAREN, ")");
    case '<':
        advance();
        return TOKEN(TOKEN_SET::TOKEN_LESS_THAN, "<");
    case '=': // CASE FOR double equals to SIGN (==) //
    {
        advance();

        if (current != '=')
        {
            cursor--;
            current = localInputBuffer[cursor];

            throwLexerError();

            advance();

            return TOKEN(TOKEN_SET::TOKEN_UNKNOWN, "=");
        }

        advance();

        return TOKEN(TOKEN_SET::TOKEN_EQUALS, "==");
    }
    case '>':
        advance();
        return TOKEN(TOKEN_SET::TOKEN_GREATER_THAN, ">");
    default:
    {
        char unknownChar = current;

        throwLexerError();
        
        advance();

        return TOKEN(TOKEN_SET::TOKEN_UNKNOWN, std::string(1, unknownChar));
    }
    }
}

void Lexer::tokenize()
{
    while (!isAtEnd()) // that means we are not at the end: current != '\0'
    {
        // SPACE, TAB, NEWLINE → WHITESPACE CHARACTERS //
        skipWhitespaces();

        // TO BE SAFE: After calling skipWhitespaces(), when we might reach the end of the input
        if (isAtEnd())
            break;

        if (CharUtils::isAlpha(current) || current == '_')
        {
            TOKEN_LIST.push_back(createStringToken());
        }
        else if (CharUtils::isDigit(current))
        {
            TOKEN_LIST.push_back(createNumberToken());
        }
        else
        {
            TOKEN_LIST.push_back(createSymbolToken());
        }
    }

    displayAllTokens();
}

// const after the function signature means this function does not modify any member variables of the Lexer object.//
const std::vector<TOKEN> &Lexer::getTokens() const
{
    return TOKEN_LIST;
}

void Lexer::displayAllTokens()
{
    std::cout << "\n========= TOKENS =========" << std::endl;

    // int counter = 0;
    // for (TOKEN CURRENT_TOKEN : TOKEN_LIST)
    // {
    //     std::cout << ++counter << ".) " << CURRENT_TOKEN.VALUE << " ";

    //     std::cout << TokenUtils::tokenTypeToString(CURRENT_TOKEN.TOKEN_TYPE) << std::endl;
    // }

    // DEFINING A SEPARATE FUNCTION IN token.cpp //
    for (size_t i = 0; i < TOKEN_LIST.size(); i++)
    {
        TokenUtils::displayToken(TOKEN_LIST[i], i + 1);
    }

    std::cout << "==========================" << std::endl;

    std::cout << std::endl;
}