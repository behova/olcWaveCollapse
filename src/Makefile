CC = g++
CFLAGS = -g

all: clean waveCollapse

clean:
	#clean waveCollapse and any .o files
	rm -f waveCollapse *.o

olc.o:
	$(CC) olcPixelGameEngine.cpp -c -o olc.o

tiles.o: olc.o
	$(CC) tiles.cpp -c -o tiles.o

main.o: olc.o tiles.o
	$(CC) main.cpp -c -o main.o

waveCollapse: olc.o tiles.o main.o
	$(CC) olc.o tiles.o main.o -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -o waveCollapse 
