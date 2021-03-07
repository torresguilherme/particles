#pragma once

#include <imgui.h>
#include <particle_source.hpp>
#include <GLFW/glfw3.h>

struct Menu {
    bool show_demo_window;
    ImVec4 clear_color;

    Menu(GLFWwindow* window);
    void render(ParticleSource& source);
    void cleanup();
};