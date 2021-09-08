#include "openglInitFunc.h"



void openglInit(
        const char *vertexSS, const char *fragmentSS,
        GLuint &VBO, GLuint &VAO, GLuint &program
                )
{
    glewExperimental = GL_TRUE;
    glewInit();
    
    GLfloat vertices[] =
    {
        -0.05f,  -0.05f,  0.0f,
        0.0f,   0.05f,   0.0f,
        0.05f,   -0.05f,  0.0f
    };
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(
                GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertices, GL_STATIC_DRAW
                );
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glVertexAttribPointer(
                0, 3, GL_FLOAT, GL_FALSE,
                3 * sizeof(GLfloat), reinterpret_cast<GLvoid *>(0)
                          );
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    
    
    
    GLuint vertexS, fragmentS;
    vertexS = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexS, 1, &vertexSS, nullptr);
    glCompileShader(vertexS);
    
    fragmentS = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentS, 1, &fragmentSS, nullptr);
    glCompileShader(fragmentS);
    
    program = glCreateProgram();
    glAttachShader(program, vertexS);
    glAttachShader(program, fragmentS);
    glLinkProgram(program);
    
    glDeleteShader(vertexS);
    glDeleteShader(fragmentS);
}
