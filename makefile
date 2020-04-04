LIBS=SDL2

SDLTutorial: main.cpp
	g++ main.cpp -o SDLTutorial -l $(LIBS)