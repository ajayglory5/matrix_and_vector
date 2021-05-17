/// \file test_utils.cpp

#include "test_utils.h"

std::string convertToLower(std::string const& instring)
{
    std::string outstring{instring};
    std::for_each(outstring.begin(), outstring.end(),
                  [](char& c) { c = ::tolower(c); });

    return outstring;
}
