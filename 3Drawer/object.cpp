#include "object.h"
#include <GL/glew.h>

void kubus::make() {

    float vertices1[216] = {
        //atas
        1.0f, 1.0f, 1.0f,      colorr, colorg, colorb,     1.0f, 1.0f, 2.0f,
         1.0f, -1.0f, 1.0f,      colorr, colorg, colorb,    1.0f, -1.0f, 2.0f,
         -1.0f, 1.0f, 1.0f,      colorr, colorg, colorb,    -1.0f, 1.0f, 2.0f,
         -1.0f, -1.0f, 1.0f,      colorr, colorg, colorb,   -1.0f, -1.0f, 2.0f,
         //bawah
         1.0f, 1.0f, -1.0f,      colorr, colorg, colorb,     1.0f, 1.0f, -2.0f,
          1.0f, -1.0f, -1.0f,      colorr, colorg, colorb,    1.0f, -1.0f, -2.0f,
          -1.0f, 1.0f, -1.0f,      colorr, colorg, colorb,    -1.0f, 1.0f, -2.0f,
          -1.0f, -1.0f, -1.0f,      colorr, colorg, colorb,   -1.0f, -1.0f, -2.0f,
          //kanan
          1.0f, 1.0f, 1.0f,      colorr, colorg, colorb,     2.0f, 1.0f, 1.0f,
          1.0f, -1.0f, 1.0f,      colorr, colorg, colorb,     2.0f, -1.0f, 1.0f,
          1.0f, 1.0f, -1.0f,      colorr, colorg, colorb,     2.0f, 1.0f, -1.0f,
          1.0f, -1.0f, -1.0f,      colorr, colorg, colorb,     2.0f, -1.0f, -1.0f,
          //kiri
          -1.0f, 1.0f, 1.0f,      colorr, colorg, colorb,     -2.0f, 1.0f, 1.0f,
          -1.0f, -1.0f, 1.0f,      colorr, colorg, colorb,    -2.0f, -1.0f, 1.0f,
          -1.0f, 1.0f, -1.0f,      colorr, colorg, colorb,    -2.0f, 1.0f, -1.0f,
          -1.0f, -1.0f, -1.0f,      colorr, colorg, colorb,   -2.0f, -1.0f, -1.0f,
          //depan
          1.0f, 1.0f, 1.0f,      colorr, colorg, colorb,     1.0f, 2.0f, 1.0f,
          -1.0f, 1.0f, 1.0f,      colorr, colorg, colorb,     -1.0f, 2.0f, 1.0f,
          1.0f, 1.0f, -1.0f,      colorr, colorg, colorb,     1.0f, 2.0f, -1.0f,
          -1.0f, 1.0f, -1.0f,      colorr, colorg, colorb,    -1.0f, 2.0f, -1.0f,
          //belakang
          1.0f, -1.0f, 1.0f,      colorr, colorg, colorb,     1.0f, -2.0f, 1.0f,
          -1.0f, -1.0f, 1.0f,      colorr, colorg, colorb,     -1.0f, -2.0f, 1.0f,
          1.0f, -1.0f, -1.0f,      colorr, colorg, colorb,     1.0f, -2.0f, -1.0f,
          -1.0f, -1.0f, -1.0f,      colorr, colorg, colorb,    -1.0f, -2.0f, -1.0f,

    };

    int indices[36] = {
        0, 1, 2,    1, 2, 3,
        4, 5, 6,    5, 6, 7,
        8, 9, 10,  9, 10, 11,
        12, 13, 14, 13, 14, 15,
        16, 17, 18, 17, 18, 19,
        20, 21, 22, 21, 22, 23
    };
    //unsigned int buff;
    glGenBuffers(1, &bufff);
    glBindBuffer(GL_ARRAY_BUFFER, bufff);
    glBufferData(GL_ARRAY_BUFFER, 216 * sizeof(float), vertices1, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &indc);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indc);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(int), indices, GL_DYNAMIC_DRAW);

    GLintptr color_offset = 3 * sizeof(float);
    GLintptr normal_offset = 6 * sizeof(float);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (GLvoid*)color_offset);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (GLvoid*)normal_offset);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void kubus::render() {
    glBindBuffer(GL_ARRAY_BUFFER, bufff);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indc);

    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 1.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    glPopMatrix();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void objectBase::lineColorInit(float colr, float colg, float colb) {
    colorLine[0] = colr;
    colorLine[1] = colg;
    colorLine[2] = colb;
}

void objectBase::lineObjectInit() {
    float vert[36] = {
        200.0f, 0.0f, 0.0f,     0.3f, 0.3f, 0.6f,     0.0f, 0.0f, 1.0f,
        -200.0f, 0.0f, 0.0f,    0.3f, 0.3f, 0.6f,   0.0f, 0.0f, 1.0f,

        0.0f, 200.0f, 0.0f,     0.3f, 0.6f, 0.3f,    0.0f, 0.0f, 1.0f,
        0.0f, -200.0f, 0.0f,    0.3f, 0.6f, 0.3f,    0.0f, 0.0f, 1.0f,
    };

    glGenVertexArrays(1, &VAOline);
    glBindVertexArray(VAOline);
    glGenBuffers(1, &lineBuff);
    glBindBuffer(GL_ARRAY_BUFFER, lineBuff);
    glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(float), vert, GL_STATIC_DRAW);

    GLintptr color_offset = 3 * sizeof(float);
    GLintptr normal_offset = 6 * sizeof(float);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (GLvoid*)color_offset);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (GLvoid*)normal_offset);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void objectBase::lineInit() {
    lineColorInit(0.9f, 0.9f, 0.9f);
    lineObjectInit();
}

void objectBase::lineRender() {
    glBindVertexArray(VAOline);
    glBindBuffer(GL_ARRAY_BUFFER, lineBuff);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indc);

    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 1.0f);
    glDrawArrays(GL_LINES, 0, 4);
    glPopMatrix();

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void objectBase::allInit() {
    lineInit();
}