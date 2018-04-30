#skrypt dla SCons wykorzystujacy boost_unit_test_framework linkowana dynamicznie  -*- mode: Python; -*-
import platform, os

env = Environment()
env_test = env.Clone()

if(platform.system() == "Linux"):
    env.Append( CPPFLAGS = '-Wall -pedantic' )
    env.Append( LINKFLAGS = '-Wall' )
    env.Append( LIBS = ['sfml-graphics', 'sfml-window', 'sfml-system'] )
    env.Append( CXXFLAGS="-std=c++0x")

    env_test.VariantDir('testdir','.',duplicate=0)
    env_test.Append( CPPFLAGS = '-Wall -pedantic' )
    env_test.Append( LINKFLAGS = '-Wall' )
    env_test.Append( LIBS = ['boost_unit_test_framework','sfml-graphics', 'sfml-window', 'sfml-system'] )
    env.Append( CXXFLAGS="-std=c++0x")

env.Program( source = ['Game.cpp','main.cpp','Ball.cpp','Const.hpp', 'Player.cpp', 'Food.cpp', 'Gamer.cpp'], target = 'agario')
env_test.Program( source = ['GameTest.cpp', 'testdir/Game.cpp', 'testdir/Ball.cpp','testdir/Const.hpp', 'testdir/Player.cpp', 'testdir/Food.cpp', 'testdir/Gamer.cpp'], target = 'agario_game_test')
