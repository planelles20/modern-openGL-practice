#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>

#include <GLFW/glfw3.h>


class Display {
    public:
        //build our window
        Display(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string& title);
        virtual ~Display();
        void PollEvents();
        void SwapWindows();
        bool State();
        void Instructions();

    private:
        GLFWwindow* window;
};

#endif // DISPLAY_H
