LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -ldl -pthread
LINKER_CLASS = ../common/display.cpp ../common/shader.cpp
COMPILER_FLAGS = -std=c++11
# The compiler
CC = g++

all:
	$(CC) $(COMPILER_FLAGS) -o example2.exe main.cpp $(LINKER_CLASS) mesh.cpp $(LINKER_FLAGS)

clean:
	rm *.exe
