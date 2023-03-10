#include <spdlog/spdlog.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/algorithm/string.hpp>

std::vector< std::string > ReadFile( std::string path )
{
    std::fstream theStream( path );
    if( !theStream.is_open() )
    {
        throw std::runtime_error( "Failed to read file: " + path );
    }

    std::stringstream theBuffer;
    theBuffer << theStream.rdbuf();
    std::string theString = theBuffer.str();

    // Split on newlines
    std::vector< std::string > theOutput;
    boost::split( theOutput, theString, boost::is_any_of( "\n" ) );
    return theOutput;
}

int CalculateScoreA( std::vector< std::string > inInputStrings )
{
    int theTotalScore = 0;

    for( std::string theString : inInputStrings )
    {
        std::vector< std::string > theResult;

        int theOpponent = theString[0] - 'A';
        int theYou = theString[2] - 'X';

        int theScore = theYou + 1;
        if( theYou == theOpponent ) theScore += 3;
        if( theYou == ( theOpponent + 1 ) % 3 ) theScore += 6;
//        spdlog::info( "{} {} {}", theString[0], theString[2], theScore );

        theTotalScore += theScore;
    }

    return theTotalScore;
}

int CalculateScoreB( std::vector< std::string > inInputStrings )
{
    int theTotalScore = 0;

    for( std::string theString : inInputStrings )
    {
        std::vector< std::string > theResult;

        int theOpponent = theString[0] - 'A';
        int theYou;
        if( theString[2] == 'X' ) theYou = ( theOpponent + 2 ) % 3;
        if( theString[2] == 'Y' ) theYou = theOpponent;
        if( theString[2] == 'Z' ) theYou = ( theOpponent + 1 ) % 3;

        int theScore = theYou + 1;
        if( theYou == theOpponent ) theScore += 3;
        if( theYou == ( theOpponent + 1 ) % 3 ) theScore += 6;
        spdlog::info( "{} {}, {} {}, {}", theString[0], theString[2], theOpponent, theYou, theScore );

        theTotalScore += theScore;
    }

    return theTotalScore;
}

int main()
{
    auto theInput = ReadFile( "input" );

    int totalScoreA = CalculateScoreA( theInput );
    spdlog::info( "score A: {}", totalScoreA );

    int totalScoreB = CalculateScoreB( theInput );
    spdlog::info( "score B: {}", totalScoreB );
}
