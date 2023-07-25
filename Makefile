
build: main.c window.h
	$(CC) -o main main.c -lglfw -lGLEW -lGL -lm
