CC=g++
LIBS=SDL2

SDLTutorial: main.cpp
	$(CC) main.cpp -o SDLTutorial -l $(LIBS)

clean:
	rm SDLTutorial