#include <catch.hpp>
#include <string>

class StringCalculator
{
    public:
        int
        AddString( const std::string& numbers )
        {
            return 0;
        }


};

TEST_CASE( "AddString", "StringCalculator" )
{
    StringCalculator calc;

    SECTION( "An empty string argument should return 0" )
    {
        REQUIRE( calc.AddString( "" ) == 0 );
    }

}
