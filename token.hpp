// HEADER/INCLUDE GUARD //
#ifndef __TOKEN_HPP
#define __TOKEN_HPP

#include <string>

/*
REQUIRE WORKING SYNTAX: CRUD
*CREATE:
- CREATE NEW DATABASE <DB_NAME>
- CREATE NEW TABLE <TABLE_NAME>

*USE:
- USE DATABASE

*INSERTION:
- INSERT INTO <TABLE_NAME> VALUE (<ELEMENT_1>, ..., <ELEMENT_N>)

*READING
- SEARCH IN <TABLE_NAME> VALUE()

*UPDATE:
- UPDATE <TABLE_NAME> WHERE (<CONDITIONS>) WITH
                               == < > =

*DELETION:
- DELETE FROM <TABLE_NAME> VALUE()


*EXIT

*/

enum class LEXER_STATUS
{
    LEXER_SUCCESS,
    LEXER_ERROR
};

enum class TOKEN_SET
{
    // TOKEN KEYWORDS //

    TOKEN_CREATE,
    TOKEN_NEW,
    TOKEN_DATABASE,
    TOKEN_TABLE,

    TOKEN_USE,

    TOKEN_INSERT,
    TOKEN_INTO,
    TOKEN_VALUE, // may also create 'TOKEN_VALUES' - leave it of no use

    TOKEN_DELETE,
    TOKEN_FROM,

    TOKEN_SEARCH,
    TOKEN_IN,

    TOKEN_UPDATE,
    TOKEN_WHERE,
    TOKEN_WITH,

    // TOKEN DATA-TYPES //
    TOKEN_INTEGER,
    TOKEN_STRING,

    // TOKEN SYMBOLS //
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_COMMA,
    TOKEN_ASSIGN,
    TOKEN_EQUALS,
    TOKEN_LESS_THAN,
    TOKEN_GREATER_THAN,

    // TOKEN MISCELLNEOUSE //
    TOKEN_UNKNOWN,
    TOKEN_EXIT,
    TOKEN_EOF // May remove it later as of now not of any use //
};

struct TOKEN
{
    TOKEN_SET TOKEN_TYPE;
    std::string VALUE;

    TOKEN(TOKEN_SET tokenType = TOKEN_SET::TOKEN_UNKNOWN, const std::string &value = "")
        : TOKEN_TYPE(tokenType), VALUE(value) {}
};

class TokenUtils
{
public:
    static std::string tokenTypeToString(TOKEN_SET tokenType);

    static void displayToken(const TOKEN &token, int index);
};

#endif