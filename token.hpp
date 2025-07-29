// HEADER/INCLUDE GUARD //
#ifndef __TOKEN_HPP
#define __TOKEN_HPP

#include <string>

enum class TOKEN_SET
{
    TOKEN_INSERT,
    TOKEN_INTO,
    TOKEN_STRING,
    TOKEN_VALUE,
    TOKEN_LEFT_PAREN,
    TOKEN_INTEGER,
    TOKEN_COMMA,
    TOKEN_RIGHT_PAREN,
    TOKEN_EOF,
    TOKEN_UNKNOWN
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