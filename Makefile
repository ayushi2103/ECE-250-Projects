all: playlistdriver

playlistdriver: playlistdriver.cpp Playlist.h Playlist.cpp
	g++ -std=c++11 -o playlistdriver playlistdriver.cpp Playlist.cpp

run: playlistdriver
	./playlistdriver < test.in > test.out

clean:
	rm playlistdriver