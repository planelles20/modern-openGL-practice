#include <iostream>
#include <math.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW (include in display class)
//#include <GLFW/glfw3.h>

// our class includes
#include "../common/display.h"
#include "../common/shader.h"
#include "mesh.h"

// Window dimensions
const GLuint WIDTH = 1200, HEIGHT = 800;
//mesh dimensions
const unsigned int Xmesh = 7, Ymesh = 7;

// Our main program
int main()
{
    // create our window
    Display display = Display(WIDTH, HEIGHT, "LearnOpenGL Carlos Planelles");

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;

    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);


    // Build and compile our shader program
    Shader ourShader = Shader("shader.vs", "shader.fs");

    // create our mesh grid class
    Mesh mesh = Mesh(Xmesh, Ymesh);

    // display keyboard instructions (like how to exit ...)
    display.Instructions();

    //this call will result in wireframe polygons.
    //mesh.PolygonMode();
    glPointSize(135.0);

    // game loop
    while (display.State())
    {
        display.PollEvents();

        mesh.BackGround(0.0, 0.0, 0.0, 1.0);

        // Update time
        GLfloat timeValue = glfwGetTime();
        GLint timeLocation = glGetUniformLocation(ourShader.ThisProgram(), "time");
        glUniform1f(timeLocation, timeValue);

        // use our shader
        ourShader.Use();

        //draw mesh
        mesh.Draw();

        //Swap buffers
        display.SwapWindows();

    }

    //NOTE: glfwTerminate(); is call in display destructor
    return 0;
}
