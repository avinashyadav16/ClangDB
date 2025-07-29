// HEADER/INCLUDE GUARD //
#ifndef __TOKEN_HPP
#define __TOKEN_HPP

#include <string>

enum class TOKEN_SET
{
    TOKEN_INSERT,
    TOKEN_INTO,
    TOKEN_STRING, // <TABLE_NAME /or DB_NAME> //
    TOKEN_VALUE,
    TOKEN_LEFT_PAREN,
    TOKEN_INT,
    TOKEN_RIGHT_PAREN,

    // FIXME: If necessary later
    // below 2 thinking of excluding
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