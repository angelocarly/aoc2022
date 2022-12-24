### Project

# Project definition
cmake_minimum_required( VERSION 3.1 )
project( day2 VERSION 0.1.0 )

# Source files
set( SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}" )
set( LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib" )
set( SOURCES main.cpp )

# Executable definition and properties
add_executable( ${PROJECT_NAME} ${SOURCES} )
target_include_directories( ${PROJECT_NAME} PUBLIC "${SRC_DIR}" )
set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17 )

# Copy input files
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/input
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/input
)
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/testinput
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/testinput
)

# glm
find_package( glm REQUIRED )
include_directories( ${GLM_INCLUDE_DIRS} )
link_directories( ${GLM_LIBRARY_DIRS} )
add_definitions( ${GLM_DEFINITIONS} )

# spdlog
find_package( spdlog REQUIRED )
target_link_libraries( ${PROJECT_NAME} PUBLIC spdlog::spdlog )

# Boost
find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
target_link_libraries( ${PROJECT_NAME} PUBLIC Boost::program_options )