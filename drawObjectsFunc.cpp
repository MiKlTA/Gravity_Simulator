#include "drawObjectsFunc.h"



void drawObjects(float *objects, GLuint transformLoc, GLuint colorLoc, GLuint objPosLoc,
                 GLuint shiftLoc, GLuint projectionLoc)
{
    for (int i = 0; i < c_objectsCount; ++i)
    {
        const float xPos = objects[c_objectArgsCount * i + 0];
        const float yPos = objects[c_objectArgsCount * i + 1];
        const float mass = objects[c_objectArgsCount * i + 4];
        
        const glm::mat4 projection(
                    glm::ortho(
                        -ORTHO_WIDTH / 2.0f, ORTHO_WIDTH / 2.0f,
                        -ORTHO_HEIGHT / 2.0f, ORTHO_HEIGHT / 2.0f
                        )
                    );
        
        glUniform2f(objPosLoc, xPos - g_horShift, yPos - g_verShift);
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &projection[0][0]);
        glUniform3f(colorLoc, 0.7f, mass / (2.0f * c_maxMass) + 0.5f, 0.5f);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}
