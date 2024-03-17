all:
	g++ -std=c++17 pong.cpp -o pong.o -lSDL2 -lSDL2_image -ldl

c:
	gcc -o pongc.o pongc.c -lSDL2 -ldl

clean:
	rm *.o