all:
	g++ -I src/include -L src/lib -o outpout/tutorial tutorial.cpp -lmingw32 -lSDL3 