#include "char_utils.hpp"

bool CharUtils::isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool CharUtils::isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool CharUtils::isWhitespace(char c)
{
    // SPACE, TAB, NEWLINE, CARRIGE RETURN → WHITESPACE CHARACTERS //
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

bool CharUtils::isAlphaNumeric(char c)
{
    return isAlpha(c) || isDigit(c);
}