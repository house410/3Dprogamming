#include <math.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}


int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(500, 500, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        double radius = 1.0;

        ////90도와 같이 각도로 연산하고 싶으면
        ////glm의 삼각함수는 radian 형식으로 입력을 받기 때문에 변환해서 넣어주어야한다.
        //glm::sin(glm::radians(90.0));  

        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        /*glBegin(GL_LINE_STRIP);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glEnd();*/

        glColor3f(0.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < 360; i++)
        {
            double angle, x, y;
            angle = i * 3.141592 / 180;
            x = radius * cos(angle);
            y = radius * sin(angle);

            glVertex2f(x, y);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

     exit(EXIT_SUCCESS);
}