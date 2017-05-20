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

// Camera
glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);

//keys pressed
bool keys[1024];

void printInstructions(void);

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void do_movement();

// Our main program
int main() {
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
    printInstructions();

    //this call will result in wireframe polygons.
    mesh.PolygonMode();

    // game loop
    while (display.State())
    {
        display.PollEvents();
        do_movement();

        mesh.BackGround(0.0, 0.0, 0.0, 1.0);

        // use our shader
        ourShader.Use();

        // Camera/View transformation
        glm::mat4 view;
        view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        glm::mat4 model;
        glm::mat4 projection;
        model = glm::rotate(model, -45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
        // Get their uniform location
        GLint modelLoc = glGetUniformLocation(ourShader.ThisProgram(), "model");
        GLint viewLoc = glGetUniformLocation(ourShader.ThisProgram(), "view");
        GLint projLoc = glGetUniformLocation(ourShader.ThisProgram(), "projection");
        // Pass them to the shaders
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        // Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        //draw mesh
        mesh.Draw();

        //Swap buffers
        display.SwapWindows();

    }

    //NOTE: glfwTerminate(); is call in display destructor
    return 0;
}

void printInstructions(void){
    std::cout << "w: move forward" << '\n';
    std::cout << "s: move backwards" << '\n';
    std::cout << "d: move right" << '\n';
    std::cout << "a: move left" << '\n';
}

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }
}

void do_movement() {
    // Camera controls
    GLfloat cameraSpeed = 0.001f;
    if (keys[GLFW_KEY_W])
        cameraPos += cameraSpeed * cameraFront;
    if (keys[GLFW_KEY_S])
        cameraPos -= cameraSpeed * cameraFront;
    if (keys[GLFW_KEY_A])
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (keys[GLFW_KEY_D])
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
