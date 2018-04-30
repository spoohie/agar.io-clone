#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <iostream>

#include "Game.hpp"

//#include <boost/test/unit_test_log.hpp>

using namespace boost::unit_test;
using namespace boost::unit_test_framework;

struct GameFixture
{
    Game game_instance;
    GameFixture() : game_instance() {}
    ~GameFixture() = default;
};

BOOST_FIXTURE_TEST_SUITE( TestGame, GameFixture )

BOOST_AUTO_TEST_CASE( xxx ) 
{
    BOOST_REQUIRE( game_instance.spam.size() <= maxFood );
}

BOOST_AUTO_TEST_SUITE_END()

