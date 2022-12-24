#ifndef H_MAIN
#define H_MAIN

#include "Reorganizer.h"

#include <spdlog/spdlog.h>
#include <boost/algorithm/string.hpp>
#include <fstream>

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

int CalculateResultA( std::vector< std::string > inInputStrings )
{
    return Reorganizer::CalculatePrioritySums( inInputStrings );
}

int CalculateResultB( std::vector< std::string > inInputStrings )
{
    return Reorganizer::CalculateAuthenticitySums( inInputStrings );
}

int main()
{
    auto theInput = ReadFile( "input" );

    int resultA = CalculateResultA( theInput );
    spdlog::info( "result A: {}", resultA );

    int resultB = CalculateResultB( theInput );
    spdlog::info( "result B: {}", resultB );
}

#endif