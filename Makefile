all:
	g++ -I src/include -L src/lib -o main main.cpp cpp/Node.cpp cpp/Graphics.cpp cpp/Map.cpp cpp/Boat.cpp cpp/Stack.cpp cpp/memo.cpp -lmingw32 -lSDL2main -lSDL2