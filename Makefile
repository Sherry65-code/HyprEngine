
build-linux: main.c window.h
	$(CC) -o main main.c -lglfw -lGLEW -lGL -lm

build-windows: main.c window.h
	$(CC) -o main main.c -lglfw -lGLEW -lGL -lm