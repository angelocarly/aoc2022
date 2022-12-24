### Project

# Project definition
cmake_minimum_required( VERSION 3.1 )
project( dayX VERSION 0.1.0 )

include_directories( core )

add_subdirectory( core )
add_subdirectory( test )
