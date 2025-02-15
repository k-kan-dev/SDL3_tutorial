all:
	g++ -I src/include -L src/lib -o output/tutorial tutorial.cpp -lmingw32 -lSDL3 