#include "windowRenderFunc.h"



void calcPositions(
        std::queue<float *, std::list<float *>> *objects,
        cl_command_queue command_queue, cl_mem buffer, cl_kernel kernel
        )
{
    while (true)
    {
        calcOneStep(objects, command_queue, buffer, kernel);
    }
}

void windowRender(
        GLFWwindow *window, GLuint VAO, GLuint VBO, GLuint program,
        cl_command_queue command_queue, cl_mem buffer, cl_kernel kernel
        )
{
    static const double fdelay = 0.0;
    std::queue<float *, std::list<float *>> *objects;
    objects = objectsInit();
    
    glClearColor(0.15f, 0.05f, 0.05f, 1.0f);
    glBindVertexArray(VAO);
    glUseProgram(program);
    
    GLuint objPosLoc = glGetUniformLocation(program, "objPos");
    GLuint shiftLoc = glGetUniformLocation(program, "shift");
    GLuint projectionLoc = glGetUniformLocation(program, "projection");
    GLuint colorLoc = glGetUniformLocation(program, "color");
    
    std::thread calcPositionsThread(
                calcPositions, objects, command_queue, buffer, kernel
                );
    calcPositionsThread.detach();
    
    while (!glfwWindowShouldClose(window))
    {
        double curTime = glfwGetTime();
        if (curTime - glfwGetTime() < fdelay)
        {
            // some non-rendering actions
            
//            std::this_thread::yield();
            
//            const float *top = objects->front();
//            for (int i = 0; i < c_owbjectsCount; ++i)
//            {
//                std::cout << i << " - x: " << top[5 * i]
//                          << " - y: " << top[5 * i + 1]
//                          << " - Vx: " << top[5 * i + 2]
//                          << " - Vy: " << top[5 * i + 3]
//                          << " - m: " << top[5 * i + 4]
//                          << std::endl;
//            }
            
            continue;
        }
        else
        {
            curTime = glfwGetTime();
        }
        
        glfwPollEvents();
        processInput();
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        
        const glm::mat4 projection(
                    glm::ortho(
                        -ORTHO_WIDTH / 2.0f, ORTHO_WIDTH / 2.0f,
                        -ORTHO_HEIGHT / 2.0f, ORTHO_HEIGHT / 2.0f
                        )
                    );
        
        glUniform2f(objPosLoc, 0.0f, 0.0f);
        glUniform2f(shiftLoc, g_horShift, g_verShift);
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);
        glUniform3f(colorLoc, 0.8f, 0.3f, 0.5f);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        
        
        drawObjects(objects->front(), 0, colorLoc,
                    objPosLoc, shiftLoc, projectionLoc);
        
        if (objects->size() > 1)
        {
            objects->pop();
        }
        
        glfwSwapBuffers(window);
        
        std::cout << curTime
                  << " - x:\t\t"
                  << g_horShift
                  << " | y:\t\t"
                  << g_verShift
                  << std::endl;
    }
    
}
