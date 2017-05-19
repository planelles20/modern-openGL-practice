#include <iostream>
#include <math.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW (include in display class)
//#include <GLFW/glfw3.h>

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// our class includes
#include "../common/display.h"
#include "../common/shader.h"
#include "mesh.h"

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
//mesh dimensions
const unsigned int Xmesh = 10, Ymesh = 20;

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
    mesh.PolygonMode();

    // game loop
    while (display.State())
    {
        display.PollEvents();

        mesh.BackGround(0.0, 0.0, 0.0, 1.0);

        // use our shader
        ourShader.Use();

        // Create transformations
        glm::mat4 transform;
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (GLfloat)glfwGetTime() * 0.5f, glm::vec3(0.0f, 0.0f, 1.0f));

        // Get matrix's uniform location and set matrix
        GLint transformLoc = glGetUniformLocation(ourShader.ThisProgram(), "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        //draw mesh
        mesh.Draw();

        //Swap buffers
        display.SwapWindows();

    }

    //NOTE: glfwTerminate(); is call in display destructor
    return 0;
}
