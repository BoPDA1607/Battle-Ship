all:
	g++ -I src/include -L src/lib -o main main.cpp Node.cpp Map.cpp Graphics.cpp Boat.cpp -lmingw32 -lSDL2main -lSDL2