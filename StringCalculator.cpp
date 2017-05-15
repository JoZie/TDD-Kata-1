#include <catch.hpp>
#include <string>
#include <cstring>
#include <vector>

class StringCalculator
{
    public:
        int
        AddString( const std::string& numbers )
        {
            int sum = 0;

            if (numbers == "")
                return sum;

            std::vector<char*> token_comma;
            char* number = std::strtok( const_cast<char*>(numbers.c_str()), "," );
            while (number)
            {
                token_comma.push_back( number );
                number = std::strtok( nullptr, "," );
            }

            for (auto it : token_comma)
            {
                number = std::strtok( it, "\n" );
                while (number)
                {
                    sum += std::stoi( number );
                    number = std::strtok( nullptr, "\n" );
                }
            }

            return sum;
        } // AddString


};

TEST_CASE( "AddString( const std::string& numbers )", "StringCalculator" )
{
    StringCalculator calc;

    SECTION( "An empty string argument should return 0" )
    {
        REQUIRE( calc.AddString( "" ) == 0 );
    }

    SECTION( "A single number string argument should return the number" )
    {
        REQUIRE( calc.AddString( "1" ) == 1 );
        REQUIRE( calc.AddString( "42" ) == 42 );
        REQUIRE( calc.AddString( "-100" ) == -100 );
    }

    SECTION( "Passing 2 comma separated numbers should return their sum" )
    {
        REQUIRE( calc.AddString( "1," ) == 1 );
        REQUIRE( calc.AddString( ",2" ) == 2 );
        REQUIRE( calc.AddString( "1,2" ) == 3 );
        REQUIRE( calc.AddString( "42,-21" ) == 21 );
        REQUIRE( calc.AddString( "-100,-200" ) == -300 );
    }

    SECTION( "Passing multiple comma separated numbers should return their sum" )
    {
        REQUIRE( calc.AddString( ",,,," ) == 0 );
        REQUIRE( calc.AddString( "1,,,," ) == 1 );
        REQUIRE( calc.AddString( ",2,,,,,," ) == 2 );
        REQUIRE( calc.AddString( "1,2,3" ) == 6 );
        REQUIRE( calc.AddString( "42,-21,-21,100" ) == 100 );
    }

    SECTION( "Allow \\n as seperator" )
    {
        REQUIRE( calc.AddString( "\n," ) == 0 );
        REQUIRE( calc.AddString( "1\n2\n3" ) == 6 );
        REQUIRE( calc.AddString( "1\n2,3" ) == 6 );
        REQUIRE( calc.AddString( "42,-21\n-21,100" ) == 100 );
    }

}
