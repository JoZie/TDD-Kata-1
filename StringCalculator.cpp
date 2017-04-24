#include <catch.hpp>
#include <string>

class StringCalculator
{
    public:
        int
        AddString( const std::string& numbers )
        {
            if (numbers == "")
                return 0;

            return std::stoi( numbers );

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

}
