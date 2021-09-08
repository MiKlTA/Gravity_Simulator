#include "calcTransformMatFunc.h"



glm::mat4 calcTransformMat(
        float horShift, float verShift,
        float objectPosX, float objectPosY
                           )
{
    glm::mat4 model(
                glm::translate(
                    glm::mat4(1.0f), glm::vec3(objectPosX, objectPosY, 0.0f)
                               )
                );
//    model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(0.1f, 0.1f, 1.0f));
    const glm::mat4 view(
                glm::translate(
                    glm::mat4(1.0f), -glm::vec3(horShift, verShift, 0.0f)
                    )
                );
    const glm::mat4 projection(
                glm::ortho(
                    -ORTHO_WIDTH / 2.0f, ORTHO_WIDTH / 2.0f,
                    -ORTHO_HEIGHT / 2.0f, ORTHO_HEIGHT / 2.0f
                    )
                );
    
    return projection * view * model;
}
