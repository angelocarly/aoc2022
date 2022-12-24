#include "../../core/Reorganizer.h"

#include <gtest/gtest.h>

TEST( Reorganizer, Case1 )
{
    char theCommonItem = Reorganizer::FindCommonItem( "vJrwpWtwJgWrhcsFMMfFFhFp" );
    EXPECT_EQ( theCommonItem, 'p' );
}

TEST( Reorganizer, Case2 )
{
    char theCommonItem = Reorganizer::FindCommonItem( "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL" );
    EXPECT_EQ( theCommonItem, 'L' );
}

TEST( Reorganizer, Case3 )
{
    char theCommonItem = Reorganizer::FindCommonItem( "PmmdzqPrVvPwwTWBwg" );
    EXPECT_EQ( theCommonItem, 'P' );
}

TEST( Reorganizer, Case4 )
{
    char theCommonItem = Reorganizer::FindCommonItem( "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn" );
    EXPECT_EQ( theCommonItem, 'v' );
}

TEST( Reorganizer, CheckPriorities )
{
    int thePriority = Reorganizer::GetPriority( 'a' );
    EXPECT_EQ( thePriority, 1 );
    thePriority = Reorganizer::GetPriority( 'z' );
    EXPECT_EQ( thePriority, 26 );
    thePriority = Reorganizer::GetPriority( 'A' );
    EXPECT_EQ( thePriority, 27 );
    thePriority = Reorganizer::GetPriority( 'Z' );
    EXPECT_EQ( thePriority, 52 );
}

TEST( Reorganizer, CheckPrioritySum )
{
    std::vector< std::string > theBackpacks =
    {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg",
        "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
        "ttgJtRGJQctTZtZT",
        "CrZsJsPPZsGzwwsLwLmpwMDw"
    };
    int thePrioritySum = Reorganizer::CalculatePrioritySums( theBackpacks );
    EXPECT_EQ( thePrioritySum, 157 );
}
