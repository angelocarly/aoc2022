#include <spdlog/spdlog.h>

#include <iostream>
#include <fstream>
#include <sstream>

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

    std::vector< std::string > theOutput;
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string token;
    while (( pos = theString.find( delimiter )) != std::string::npos )
    {
        token = theString.substr( 0, pos );
        theOutput.push_back( token );
        theString.erase(0, pos + delimiter.length());
    }
    return theOutput;
}

std::vector< int > CalculateSums( std::vector< std::string > inInputStrings )
{
    std::vector< int > theSums;

    int sum = 0;
    for( std::string theString : inInputStrings )
    {
        if( theString.compare( "" ) == 0 )
        {
            theSums.push_back( sum );
            sum = 0;
        }
        else
        {
            sum += std::stoi( theString );
        }
    }

    return theSums;
}

int main()
{
    auto theInput = ReadFile( "input" );

    std::vector< int > theSums = CalculateSums( theInput );
    std::sort( theSums.begin(), theSums.end(), std::greater< int >() );

    spdlog::info( "Output 1, max: {}", theSums.front() );

    int sum = 0;
    for( int i = 0; i < 3; i++ )
    {
        sum += theSums.at( i );
    }
    spdlog::info( "Output 2, max three: {}", sum );
}
