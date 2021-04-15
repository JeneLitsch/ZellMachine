flags = ["-std=c++2a", "-std=gnu++2a"]

Library("sfml", [
	"SFML-Linux/lib/libsfml-graphics.so.2.5.1",
	"SFML-Linux/lib/libsfml-audio.so.2.5.1",
	"SFML-Linux/lib/libsfml-network.so.2.5.1",
	"SFML-Linux/lib/libsfml-system.so.2.5.1",
	"SFML-Linux/lib/libsfml-window.so.2.5.1",
] , CXXFLAGS = flags)

Library("zellMachine", Glob("base/*.cpp") , CXXFLAGS = flags)

libs = ["sfml", "zellMachine"]


env = Environment(CC = "clang++", CXXFLAGS = flags, CPPPATH = '', CPPDEFINES = [], LIBS = libs, LIBPATH = ".", SCONS_CXX_STANDART="c++20")
env.Program('GameOfLife.exec', Glob('GameOfLife/*.cpp'))
env.Program('FallingCell.exec', Glob('Falling/*.cpp'))