#include "token.hpp"
#include <iostream>

std::string TokenUtils::tokenTypeToString(TOKEN_SET tokenType)
{
    switch (tokenType)
    {
    case TOKEN_SET::TOKEN_CREATE:
        return "TOKEN_CREATE";

    case TOKEN_SET::TOKEN_NEW:
        return "TOKEN_NEW";

    case TOKEN_SET::TOKEN_DATABASE:
        return "TOKEN_DATABASE";

    case TOKEN_SET::TOKEN_TABLE:
        return "TOKEN_TABLE";

    case TOKEN_SET::TOKEN_USE:
        return "TOKEN_USE";

    case TOKEN_SET::TOKEN_INSERT:
        return "TOKEN_INSERT";

    case TOKEN_SET::TOKEN_INTO:
        return "TOKEN_INTO";

    case TOKEN_SET::TOKEN_VALUE:
        return "TOKEN_VALUE";

    case TOKEN_SET::TOKEN_DELETE:
        return "TOKEN_DELETE";

    case TOKEN_SET::TOKEN_FROM:
        return "TOKEN_FROM";

    case TOKEN_SET::TOKEN_SEARCH:
        return "TOKEN_SEARCH";

    case TOKEN_SET::TOKEN_IN:
        return "TOKEN_IN";

    case TOKEN_SET::TOKEN_UPDATE:
        return "TOKEN_UPDATE";

    case TOKEN_SET::TOKEN_WHERE:
        return "TOKEN_WHERE";

    case TOKEN_SET::TOKEN_WITH:
        return "TOKEN_WITH";

    case TOKEN_SET::TOKEN_INTEGER:
        return "TOKEN_INTEGER";

    case TOKEN_SET::TOKEN_STRING:
        return "TOKEN_STRING";

    case TOKEN_SET::TOKEN_LEFT_PAREN:
        return "TOKEN_LEFT_PAREN";

    case TOKEN_SET::TOKEN_COMMA:
        return "TOKEN_COMMA";

    case TOKEN_SET::TOKEN_RIGHT_PAREN:
        return "TOKEN_RIGHT_PAREN";

    case TOKEN_SET::TOKEN_ASSIGN:
        return "TOKEN_ASSIGN";

    case TOKEN_SET::TOKEN_EQUALS:
        return "TOKEN_EQUALS";

    case TOKEN_SET::TOKEN_LESS_THAN:
        return "TOKEN_LESS_THAN";

    case TOKEN_SET::TOKEN_GREATER_THAN:
        return "TOKEN_GREATER_THAN";

    case TOKEN_SET::TOKEN_EXIT:
        return "TOKEN_EXIT";

    case TOKEN_SET::TOKEN_EOF:
        return "TOKEN_EOF";

    case TOKEN_SET::TOKEN_UNKNOWN:
        return ">> [!] ERROR: LEXER_ERROR: TOKEN_UNKNOWN";

        // default:
        //     return "TOKEN_UNKNOWN";
    }

    return ">> [!] ERROR: LEXER_ERROR: TOKEN_UNKNOWN";
}

void TokenUtils::displayToken(const TOKEN &token, int index)
{
    std::cout << index << ".) " << token.VALUE << " "
              << tokenTypeToString(token.TOKEN_TYPE) << std::endl;
}