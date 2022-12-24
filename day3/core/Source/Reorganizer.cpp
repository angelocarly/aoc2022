#include "Reorganizer.h"

#include <string>
#include <vector>

namespace
{
    std::vector< char > FindCommonLetters( std::string a, std::string b )
    {
        std::vector< char > commonChars;
        for( int i = 0; i < a.length(); ++i )
        {
            for( int j = 0; j < b.length(); ++j )
            {
                if( a[ i ] != b [ j ] ) continue;

                if( std::count( commonChars.begin(), commonChars.end(), a[ i ]) == 0 )
                {
                    commonChars.push_back( a[ i ] );
                }
            }
        }
        return commonChars;
    }
}

char
Reorganizer::FindCommonItem( std::string inInput )
{
    auto theCommonLetters = FindCommonLetters
    (
        inInput.substr(0, inInput.length() / 2),
        inInput.substr( inInput.length() / 2, inInput.length() )
    );

    if( !theCommonLetters.empty() ) return theCommonLetters.front();

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

int
Reorganizer::CalculateAuthenticitySums( std::vector< std::string > inInputStrings )
{
    int theSum = 0;
    for( int i = 0; i < inInputStrings.size(); i += 3 )
    {
        std::vector< std::string > theRucksacks;
        theRucksacks.push_back( inInputStrings.at( i ) );
        theRucksacks.push_back( inInputStrings.at( i + 1 ) );
        theRucksacks.push_back( inInputStrings.at( i + 2 ) );
        int priority = GetPriority( FindAuthenticityBadge( theRucksacks ) );
        theSum += priority;
    }
    return theSum;
}

char
Reorganizer::FindAuthenticityBadge( std::vector< std::string > inRuckSacks )
{
    std::string theCommonLetters = inRuckSacks.front();
    for( auto theRuckSack : inRuckSacks )
    {
        theCommonLetters = FindCommonLetters( theCommonLetters, theRuckSack ).data();
    }

    if( !theCommonLetters.empty() ) return theCommonLetters[ 0 ];

    throw std::runtime_error( "invalid input" );
}