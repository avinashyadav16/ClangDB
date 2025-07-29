// HEADER/INCLUDE GUARD //
#ifndef __TOKEN_HPP
#define __TOKEN_HPP

#include <string>

enum class TOKEN_SET
{
    // TOKEN KEYWORDS //
    TOKEN_INSERT,
    TOKEN_INTO,
    TOKEN_VALUE, // may also create 'TOKEN_VALUES' - leave it of no use

    // TOKEN DATA-TYPES //
    TOKEN_INTEGER,
    TOKEN_STRING,

    // TOKEN SYMBOLS //
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    TOKEN_COMMA,

    // TOKEN MISCELLNEOUSE //
    TOKEN_UNKNOWN,
    TOKEN_EOF // May remove it later as of not of any use //
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