#ifndef ADVENTOFCODE2022_REORGANIZER_H
#define ADVENTOFCODE2022_REORGANIZER_H

#include <string>

class Reorganizer
{
    public:
        static char FindCommonItem( std::string inInput );
        static std::vector< char > FindCommonItems( std::vector< std::string > inInput );
        static int GetPriority( char inItem );
        static int CalculatePrioritySums( std::vector< std::string > inInputStrings );
};


#endif //ADVENTOFCODE2022_REORGANIZER_H
