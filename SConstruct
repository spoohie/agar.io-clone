#skrypt dla SCons wykorzystujacy boost_unit_test_framework linkowana dynamicznie  -*- mode: Python; -*-
import platform, os

env = Environment()
env_test = env.Clone()

if(platform.system() == "Linux"):
    env.Append( CPPFLAGS = '-Wall -pedantic -pthread' )
    env.Append( LINKFLAGS = '-Wall -pthread' )
    env.Append( LIBS = ['sfml-graphics', 'sfml-window', 'sfml-system'] )

env.Program( source = ['main.cpp','Ball.cpp','Const.hpp', 'Player.cpp', 'Food.cpp'], target = 'twojastara')