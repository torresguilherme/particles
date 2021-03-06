#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <texture.hpp>

struct Particle {
    glm::vec4 position;
    glm::vec4 velocity;
    glm::vec4 acceleration;
    float life;
    glm::vec3 padding;
};

struct ParticleSource {
    GLuint vao;
    Texture texture;
    Texture noise;
    GLuint texture_buffer;
    GLuint noise_buffer;
    GLuint compute_program;
    GLuint ssbo;
    int work_x;

    std::vector<Particle> particles;

    glm::vec3 position;
    glm::vec3 rotation;

    bool mode_gpu;
    int number_of_particles;
    float cycle;
    double cycle_timer;
    float point_size;
    float explosiveness;
    float emission_radius;
    int particle_index;
    int particles_left;

    glm::vec4 initial_velocity;
    float velocity_randomness;
    glm::vec4 initial_acceleration;
    float acceleration_randomness;

    ParticleSource();
    void cleanup();
    void update(double delta_time);
    void update_cpu(double delta_time);
    void update_gpu(double delta_time);
    void send_uniform_struct(double delta_time, int new_particles);
    
    void update_buffer_sizes();
    void setup_texture(const Texture& m_texture,
        GLuint& buffer, GLint flag, GLint dimension);
    void generate_gpu_compute();
    void bind_buffers();
    void draw();

    float random_uniform(float scale);
    float random_throw();
    glm::vec4 spawn_position();
    glm::vec4 spherical_to_xyz(float r, float theta, float phi);
};