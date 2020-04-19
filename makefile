FLAGS =  -mms-bitfields -ID:/msys2/mingw64/include/glibmm-2.4 -ID:/msys2/mingw64/lib/glibmm-2.4/include -ID:/msys2/mingw64/include -ID:/msys2/mingw64/lib/libffi-3.2.1/include -ID:/msys2/mingw64/include/glib-2.0 -ID:/msys2/mingw64/lib/glib-2.0/include -ID:/msys2/mingw64/include -ID:/msys2/mingw64/include/sigc++-2.0 -ID:/msys2/mingw64/lib/sigc++-2.0/include -LD:/msys2/mingw64/lib -lglibmm-2.4 -lgobject-2.0 -lglib-2.0 -lintl -lsigc-2.0 -std=c++17 -g

flow: flow.o read_cache.o
	g++ -o flow read_cache.o flow.o $(FLAGS)

flow.o: flow.cpp read_cache.hpp
	g++ -c -o  flow.o flow.cpp $(FLAGS)

read_cache.o: read_cache.cpp read_cache.hpp
	g++ -c -o read_cache.o read_cache.cpp $(FLAGS)
