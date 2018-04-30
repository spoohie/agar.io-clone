#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <iostream>

#include "Game.cpp"

//#include <boost/test/unit_test_log.hpp>

using namespace boost::unit_test;
using namespace boost::unit_test_framework;



BOOST_AUTO_TEST_SUITE( main_test_tools )


BOOST_AUTO_TEST_CASE( RandomGenerators ) {
    std::cout << velocity_factor << std::endl;
    int a = 2;
    BOOST_WARN( sizeof(int) < sizeof(long) );
    BOOST_CHECK( a == 1 );
    BOOST_REQUIRE( a > 3 );
    BOOST_CHECK( a == 2 );
}

BOOST_AUTO_TEST_CASE( ComparisonTestTools ) {
    double x = 1.0;
    double y = 1.001;
    BOOST_CHECK_BITWISE_EQUAL(0x27,0x17);
    BOOST_REQUIRE_CLOSE(x,y,0.1);
    BOOST_CHECK_CLOSE(x,y,0.09996);
    BOOST_WARN_CLOSE(x,y,0.09991);
    BOOST_CHECK_SMALL( x - y, 0.001 );
}

struct MyException : public std::exception {
    int i_;
    MyException(int i) : i_(i) {}
};

void f() { throw MyException(1); }

bool isCritical(const MyException& ex) { return ex.i_ == 2; }

BOOST_AUTO_TEST_CASE( ExceptionTestTools ) {

    BOOST_CHECK_NO_THROW( f() );
    BOOST_REQUIRE_THROW( f(), std::exception );
    BOOST_CHECK_EXCEPTION( f(), MyException, isCritical );
}

BOOST_AUTO_TEST_CASE( MessageTestTools ) {
    int i = 1;
	BOOST_CHECK_MESSAGE( i == 2, "mialo byc i == 2, a jest i == " << i );
}

BOOST_AUTO_TEST_SUITE_END()

