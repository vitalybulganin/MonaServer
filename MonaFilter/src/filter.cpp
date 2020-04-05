#include "../filter.h"
//-------------------------------------------------------------------------//
#include <iostream>
//-------------------------------------------------------------------------//
auto accept(const char * url) -> bool
{
    std::clog << "accept: " << url << ": [true]" << std::endl;
    return true;
}
//-------------------------------------------------------------------------//
auto notify(const char * url, short type) -> void
{
    std::clog << (type == 1 ? "start: " : "stop: ") << url << std::endl;
}
