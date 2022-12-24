#include <spdlog/spdlog.h>

#include <iostream>
#include <fstream>
#include <sstream>

std::string ReadFile( std::string path )
{
    std::fstream theStream( path );
    if( !theStream.is_open() )
    {
        throw std::runtime_error( "Failed to read file: " + path );
    }

    std::stringstream theBuffer;
    theBuffer << theStream.rdbuf();

    return theBuffer.str();
}

int main()
{
    std::cout << ReadFile( "input" ) << "\n";
}
