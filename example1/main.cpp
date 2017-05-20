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
const GLuint WIDTH = 800, HEIGHT = 600;
//mesh dimensions
const unsigned int Xmesh = 2, Ymesh = 2;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

// Our main program
int main()
{
    // create our window
    Display display = Display(WIDTH, HEIGHT, "LearnOpenGL Carlos Planelles", key_callback);

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

    // game loop
    while (display.State())
    {
        display.PollEvents();

        mesh.BackGround(0.0, 0.0, 0.0, 1.0);

        // use our shader
        ourShader.Use();

        // Update time
        GLfloat timeValue = glfwGetTime();
        GLint timeLocation = glGetUniformLocation(ourShader.ThisProgram(), "time");
        glUniform1f(timeLocation, timeValue);

        //draw mesh
        mesh.Draw();

        //Swap buffers
        display.SwapWindows();

    }

    //NOTE: glfwTerminate(); is call in display destructor
    return 0;
}
