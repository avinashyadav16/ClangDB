#include "token.hpp"
#include <iostream>

std::string TokenUtils::tokenTypeToString(TOKEN_SET tokenType)
{
    switch (tokenType)
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

    case TOKEN_SET::TOKEN_INTEGER:
        return "TOKEN_INTEGER";

    case TOKEN_SET::TOKEN_COMMA:
        return "TOKEN_COMMA";

    case TOKEN_SET::TOKEN_RIGHT_PAREN:
        return "TOKEN_RIGHT_PAREN";

    case TOKEN_SET::TOKEN_EOF:
        return "TOKEN_EOF";

    case TOKEN_SET::TOKEN_UNKNOWN:
        return ">> [!!] WARNING: UNKNOWN_TOKEN_FOUND: TOKEN_UNKNOWN";

        // default:
        //     return "TOKEN_UNKNOWN";
    }

    return ">> [!!] WARNING: UNKNOWN_TOKEN_FOUND: TOKEN_UNKNOWN";
}

void TokenUtils::displayToken(const TOKEN &token, int index)
{
    std::cout << index << ".) " << token.VALUE << " "
              << tokenTypeToString(token.TOKEN_TYPE) << std::endl;
}