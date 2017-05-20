#ifndef STATEBASE_H
#define STATEBASE_H

#include <GLFW/glfw3.h>

class StateBase {
    virtual void keycallback(
        GLFWwindow *window,
        int key,
        int scancode,
        int action,
        int mode) = 0; /* purely abstract function */

    static StateBase *event_handling_instance;
    // technically setEventHandling should be finalized so that it doesn't
    // get overwritten by a descendant class.
    virtual void setEventHandling() { event_handling_instance = this; }

    static void GLFWCALL keycallback_dispatch(
        GLFWwindow *window,
        int key,
        int scancode,
        int action,
        int mode)
    {
        if(event_handling_instance)
            event_handling_instance->keycallback(window,key,scancode,action,mode);
    }
};

#endif // STATEBASE_H
