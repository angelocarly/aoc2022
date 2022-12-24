#include "Reorganizer.h"

#include <string>
#include <vector>

char
Reorganizer::FindCommonItem( std::string inInput )
{
    for( int i = 0; i < inInput.length() / 2; ++i )
    {
        for( int j = inInput.length() / 2; j < inInput.length(); ++j )
        {
            if( inInput[ i ] == inInput [ j ] )
            {
                return inInput[ i ];
            }
        }
    }
    throw std::runtime_error( "invalid input" );
}

std::vector< char >
Reorganizer::FindCommonItems( std::vector< std::string > inInput )
{
    std::vector< char > theCommonItems;
    for( std::string theLine : inInput )
    {
        theCommonItems.push_back( FindCommonItem( theLine ) );
    }
    return theCommonItems;
}

int
Reorganizer::GetPriority( char inItem )
{
    if ( isupper( inItem ) )
    {
        // Uppercase priorities are after lowercase
        return ( inItem - 'A' ) + 1 + 26;
    }
    return ( inItem - 'a' ) + 1;
}

int
Reorganizer::CalculatePrioritySums( std::vector< std::string > inInputStrings )
{
    int theSum = 0;
    auto theCommonItems = Reorganizer::FindCommonItems( inInputStrings );
    for( char theItem : theCommonItems )
    {
        int priority = GetPriority( theItem );
        theSum += priority;
    }
    return theSum;
}