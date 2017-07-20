LINKER_FLAGS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -ldl -pthread
COMPILER_FLAGS = -std=c++11
CLASS_LINK = ../common/display.cpp ../common/shader.cpp
# The compiler
CC = g++

all:
	$(CC) $(COMPILER_FLAGS) -o example18.exe main.cpp $(CLASS_LINK) mesh.cpp $(LINKER_FLAGS)

clean:
	rm *.exe
