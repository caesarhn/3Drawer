#include <Windows.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "object.h"

#include "shaders.h"
#include "camera.h"
#include "transform.h"
#include "gui.h"

// window size
int width = 1440;
int height = 720;
int left_window_width;
int left_window_height;
int right_window_width;
int right_window_height;
int bottom_window_width;
int bottom_window_height;

//int width = 1920;
//int height = 1080;

// Define Keyboards
int key_q, key_w, key_e, key_r, key_t, key_y, key_u, key_i, key_o, key_p,
    key_a, key_s, key_d, key_f, key_g, key_h, key_j, key_k, key_l,
    key_z, key_x, key_c, key_v, key_b, key_n, key_m;
int mouse_left, mouse_right, mouse_mid;

// Window Status
bool hideWindow = false;

double x = 0, y= 0;

double xpos, ypos;
float movex = 0.0f;
float movey = 0.0f;

int par = 1;
float parpar = 0.0f;

// Define Buffers
unsigned int VAO;
unsigned int bufffs;
unsigned int indcs;

int main_c();
void animation(unsigned int wad);

//LoaderObj obj;

//int pos_land_size = sizeof(pos_land)/sizeof(pos_land[0]);
std::string gerak = "naik";

int main() {
    main_c();

    return 0;
}

void animation(unsigned int wad) {
    glUniform3f(wad, 0.0f, 0.0f, 0.0f);
    if (par == 1) {
        parpar = parpar - 0.05f;
        glUniform3f(wad, 0.0f, 0.0f, parpar);
        if (parpar < -3.0f) {
            par = 0;
        }
    }
    else {
        parpar = parpar + 0.05f;
        glUniform3f(wad, 0.0f, 0.0f, parpar);
        if (parpar > 5.0f) {
            par = 1;
        }
    }
}

int main_c()
{
    left_window_height = height;
    left_window_width = width / 10;
    right_window_height = height;
    right_window_width = width / 5;
    bottom_window_height = height / 10;
    bottom_window_width = width;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
        std::cout << "Done Make Window" << std::endl;
    }
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Anjay_GLS", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    else {
        std::cout << "Make a Window .. " << std::endl;
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error !" << std::endl;
    }
    else {
        std::cout << "Done" << std::endl;
    }

    // Setup Dear ImGui context
    //IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    ShaderUtil shader;
    shader.Load("vs2.shader", "fs.shader");

    std::cout << "-------" << std::endl;

    unsigned int progeram = shader.Program();
    shader.Use();

    float deg = 0.0f;
    //terrain world;
    camera came;
    kubus kub;
    transform trans;
    objectBase obj;
    menuBar gui;
    resourceWindow reswin;

    kub.make();
    obj.allInit();
    trans.transformInit(progeram);
    
    unsigned int trslt = glGetUniformLocation(progeram, "translate");
    glUniform3f(trslt, 0.0f, 0.0f, 0.0f);

    unsigned int lght = glGetUniformLocation(progeram, "lght");
    glUniform3f(lght , 10.0f, 10.0f, 10.0f);

    int state;


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   
        glfwGetWindowSize(window, &width, &height);
        // perhitungan ukuran seluruh window
        left_window_height = height;
        left_window_width = width / 10;
        right_window_height = height;
        right_window_width = width / 5;
        bottom_window_height = height / 5;
        bottom_window_width = width;

        glfwGetWindowSize(window, &width, &height);

        //land();
        /* Render here */
        glViewport(left_window_width, bottom_window_height, (width - left_window_width), (height-bottom_window_height));
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
        glMatrixMode(GL_PROJECTION);
        ///glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH_TEST);
        glLoadIdentity();

        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        came.camcamera(width, height, progeram);
        //trans.transformInit(progeram);
        //obj.lineRender();

        deg = deg + 1.0f;
        glPushMatrix();
        animation(trslt);
        //trans.scaled(0.5f, 0.5f, 0.5f);
        kub.render();
        trans.defaultTransform();
        glPopMatrix();

        glPushMatrix();
        trans.tranlate(0.0f, 2.0f, -2.0f);
        trans.scaled(10.5f, 10.5f, 1.5f);
        kub.render();
        trans.defaultTransform();
        glPopMatrix();
        //animation(trslt);
        //trans.defaultTransform();

        obj.lineRender();

        // imgui Window
        ImGui::Begin("test");
        ImGui::Button("Hello!");
        ImGui::End();

        gui.menubarRender();
        reswin.resourceWindowRender(width, bottom_window_height, (height - bottom_window_height));

        // Render dear imgui into screen
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        mouse_left = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        key_w = glfwGetKey(window, GLFW_KEY_W);
        key_s = glfwGetKey(window, GLFW_KEY_S);

        // Handle the periperals input
        if (mouse_left == GLFW_PRESS) {
            came.setCameraCanMove(true);
            if (key_w == GLFW_PRESS) {
                came.setCameraMoveForward(true);
                //std::cout << "w pressed" << std::endl;
            }
            else if (key_s == GLFW_PRESS) {
                came.setCameraMoveBackward(true);
            }
            else {
                came.setCameraMoveForward(false);
                came.setCameraMoveBackward(false);
            }
            //came.cameraMovement(xpos, ypos);
            if (xpos > left_window_width && ypos < (height - bottom_window_height)) {
                came.cameraFpsRotation(0.03f, xpos, ypos);
            }
        }
        else {
            came.setCameraCanMove(false);
        }

        glfwGetCursorPos(window, &xpos, &ypos);

        /* Poll for and process events */
        glfwPollEvents();
    }
    //shader.Delete();
    glfwTerminate();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    return 0;
}