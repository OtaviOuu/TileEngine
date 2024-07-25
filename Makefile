build:
	g++ -w -std=c++14 \
	./src/*.cpp \
	-o game \
	-I"./lib/lua" \
	-L"./lib/lua" \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;

clean:
	rm ./game;

run:
	./game;
