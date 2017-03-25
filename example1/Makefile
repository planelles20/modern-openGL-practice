LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -ldl -pthread
COMPILER_FLAGS = -std=c++11
# The compiler
CC = g++

all:
	$(CC) $(COMPILER_FLAGS) -o example1.exe main.cpp display.cpp shader.cpp mesh.cpp $(LINKER_FLAGS)

clean:
	rm *.exe
