#include "loader.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <GL/glew.h>
#include <vector>

void LoaderObj::readfile(const char* filename)
{
    std::string s;
    std::ifstream fin(filename);
    if (!fin) {
        std::cout << "error open file.." << std::endl;
        return;
    }

    int u = 0;
    //int ve = 0;
    while (fin >> s)
    {
        std::cout << s << std::endl;
        if (s == "v")
        {
            vertex v;
            fin >> v.x >> v.y >> v.z;
            this->vetexes.push_back(v);
            vert[ve][0] = v.x;
            vert[ve][1] = v.y;
            vert[ve][2] = v.z;
            ve++;
            std::cout << "vertex detect" << std::endl;
            std::cout << v.x <<" "<<v.y <<" "<< v.z << std::endl;
            //break;
        }
        else if (s == "vn")
        {
            vertex v;
            fin >> v.x >> v.y >> v.z;
            this->vetexes.push_back(v);
            vnormal[vn][0] = v.x;
            vnormal[vn][1] = v.y;
            vnormal[vn][2] = v.z;
            vn++;
        }
        else if(s == "f")
        {
            face f;
            fin >> f.v1 >> f.v2 >> f.v3;
            this->faces.push_back(f);
            std::cout << f.v1 << std::endl;
            std::cout << f.v2 << std::endl;
            std::cout << f.v3 << std::endl;

            facee[u][0] = f.v1;
            facee[u][1] = f.v2;
            facee[u][2] = f.v3;
            u++;

            kapasitas = u;
        }
        else {
            std::cout << "pass" << std::endl;
        }
        
        std::cout << "loop" << std::endl;
    }
    for (int s = 0; s < kapasitas; s++) {
        for (int d = 0; d < 3; d++) {
            std::cout << facee[s][d] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << kapasitas << std::endl;

}

void LoaderObj::draw()
{
    int loc;
    int locn;
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < kapasitas; i++)
    {
        for (int s = 0; s < 3; s++) {
            loc = verte[i][s][0] - 1;
            locn = verte[i][s][2]- 1;
            glVertex3f(vert[loc][0], vert[loc][1], vert[loc][2]);
            glNormal3f(vnormal[locn][0], vnormal[locn][1], vnormal[locn][2]);
        }
    }
    glEnd();
}

void LoaderObj::getObjVec() {
    //static unsigned int verte[100][3][3];
    for (int s = 0; s < kapasitas; s++) {
        for (int ss = 0; ss < 3; ss++) {
            std::string tampung = facee[s][ss];
            //std::cout << tampung.at(1) << std::endl;
            if (tampung.at(1) == '/') {
                verte[s][ss][0] = atoi(tampung.substr(0, 1).c_str());

                if (tampung.at(3) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(2, 1).c_str());

                    if (tampung.length() == 5) {
                        verte[s][ss][2] = atoi(tampung.substr(4, 1).c_str());
                    }
                    else if (tampung.length() == 6) {
                        verte[s][ss][2] = atoi(tampung.substr(4, 2).c_str());
                    }
                }
                else if (tampung.at(4) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(2, 2).c_str());

                    if (tampung.length() == 6) {
                        verte[s][ss][2] = atoi(tampung.substr(5, 1).c_str());
                    }
                    else if (tampung.length() == 7) {
                        verte[s][ss][2] = atoi(tampung.substr(5, 2).c_str());
                    }
                    else if (tampung.length() == 8) {
                        verte[s][ss][2] = atoi(tampung.substr(5, 3).c_str());
                    }
                }
                else if (tampung.at(5) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(2, 3).c_str());

                    if (tampung.length() == 7) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 1).c_str());
                    }
                    else if (tampung.length() == 8) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 2).c_str());
                    }
                    else if (tampung.length() == 9) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 3).c_str());
                    }
                }
            }
            else if (tampung.at(2) == '/') {
                verte[s][ss][0] = atoi(tampung.substr(0, 2).c_str());

                if (tampung.at(4) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(3, 1).c_str());

                    if (tampung.length() == 6) {
                        verte[s][ss][2] = atoi(tampung.substr(5, 1).c_str());
                    }
                    else if (tampung.length() == 7) {
                        verte[s][ss][2] = atoi(tampung.substr(5, 2).c_str());
                    }
                    else if (tampung.length() == 8) {
                        verte[s][ss][2] = atoi(tampung.substr(5, 3).c_str());
                    }
                }

                else if (tampung.at(5) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(3, 2).c_str());

                    if (tampung.length() == 7) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 1).c_str());
                    }
                    else if (tampung.length() == 8) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 2).c_str());
                    }
                    else if (tampung.length() == 9) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 3).c_str());
                    }
                }
                else if (tampung.at(6) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(3, 3).c_str());

                    if (tampung.length() == 8) {
                        verte[s][ss][2] = atoi(tampung.substr(7, 1).c_str());
                    }
                    else if (tampung.length() == 9) {
                        verte[s][ss][2] = atoi(tampung.substr(7, 2).c_str());
                    }
                    else if (tampung.length() == 10) {
                        verte[s][ss][2] = atoi(tampung.substr(7, 3).c_str());
                    }
                }
            }

            else if (tampung.at(3) == '/') {
                verte[s][ss][0] = atoi(tampung.substr(0, 3).c_str());

                if (tampung.at(5) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(4, 1).c_str());

                    if (tampung.length() == 7) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 1).c_str());
                    }
                    else if (tampung.length() == 8) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 2).c_str());
                    }
                    else if (tampung.length() == 9) {
                        verte[s][ss][2] = atoi(tampung.substr(6, 3).c_str());
                    }
                }

                else if (tampung.at(6) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(4, 2).c_str());

                    if (tampung.length() == 8) {
                        verte[s][ss][2] = atoi(tampung.substr(7, 1).c_str());
                    }
                    else if (tampung.length() == 9) {
                        verte[s][ss][2] = atoi(tampung.substr(7, 2).c_str());
                    }
                    else if (tampung.length() == 10) {
                        verte[s][ss][2] = atoi(tampung.substr(7, 3).c_str());
                    }
                }
                else if (tampung.at(7) == '/') {
                    verte[s][ss][1] = atoi(tampung.substr(4, 3).c_str());

                    if (tampung.length() == 9) {
                        verte[s][ss][2] = atoi(tampung.substr(8, 1).c_str());
                    }
                    else if (tampung.length() == 10) {
                        verte[s][ss][2] = atoi(tampung.substr(8, 2).c_str());
                    }
                    else if (tampung.length() == 11) {
                        verte[s][ss][2] = atoi(tampung.substr(8, 3).c_str());
                    }
                }
            }
        }
    }

    for (int j = 0; j < kapasitas; j++) {
        for (int i = 0; i < 3; i++){
            std::cout << verte[j][i][0] << "   " << verte[j][i][1] << "   " << verte[j][i][2] << std::endl;
        }
    }
    std::cout << verte[0][0][0] << std::endl;
    std::cout << verte[0][0][1] << std::endl;
    std::cout << verte[0][0][2] << std::endl;
}

void *LoaderObj::arrayToBuffer(float* array) {

    int lo;
    int lon;
    int plus = 0;
    for (int i = 0; i < kapasitas; i++)
    {
        for (int s = 0; s < 3; s++) {
            lo = verte[i][s][0] - 1;
            lon = verte[i][s][2] - 1;

            array[plus] = vert[lo][0];
            array[plus+1] = vert[lo][1];
            array[plus+2] = vert[lo][2];

            array[plus + 3] = 0.5f;
            array[plus + 4] = 0.5f;
            array[plus + 5] = 0.5f;

            array[plus + 6] = vnormal[lon][0];
            array[plus + 7] = vnormal[lon][1];
            array[plus + 8] = vnormal[lon][2];
            plus = plus + 9;
        }
    }

    return 0;
}

int LoaderObj::retVe() {
    return kapasitas;
}

void LoaderObj::print() {
    std::cout << vert[0][0] << "  " << vert[0][1] << "  " << vert[0][2] << std::endl ; 
}

void LoaderObj::selfBuffers() {
    const int a = this->kapasitas;
    float arrays[10000];

    int lo;
    int lon;
    int plus = 0;
    for (int i = 0; i < kapasitas; i++)
    {
        for (int s = 0; s < 3; s++) {
            lo = verte[i][s][0] - 1;
            lon = verte[i][s][2] - 1;

            arrays[plus] = vert[lo][0];
            arrays[plus + 1] = vert[lo][1];
            arrays[plus + 2] = vert[lo][2];

            arrays[plus + 3] = 0.5f;
            arrays[plus + 4] = 0.5f;
            arrays[plus + 5] = 0.5f;

            arrays[plus + 6] = vnormal[lon][0];
            arrays[plus + 7] = vnormal[lon][1];
            arrays[plus + 8] = vnormal[lon][2];
            plus = plus + 9;
        }
    }
    glGenBuffers(1, &bufferData);
    glGenVertexArrays(1, &VAo);

    glBindVertexArray(VAo);
    glBindBuffer(GL_ARRAY_BUFFER, bufferData);
    glBufferData(GL_ARRAY_BUFFER, 240 * sizeof(float), arrays, GL_STATIC_DRAW);

    GLintptr color_offset = 3 * sizeof(float);
    GLintptr normal_offset = 6 * sizeof(float);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (GLvoid*)color_offset);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (GLvoid*)normal_offset);

    glBindVertexArray(0);

    int ass = 0;
    for (int i = 0; i < 2200; i+=9) {
        
        std::cout << "dimulai cek" << std::endl;
        std::cout << ass << "  ";
        std::cout << arrays[i] << "   " << arrays[i+1]<< "   " << arrays[i+2] << "   --   " <<
                     arrays[i+3] << "   " << arrays[i + 4] << "   " << arrays[i + 5] << "  --  " <<
                     arrays[i+6] << "   " << arrays[i + 7] << "   " << arrays[i + 8] << std::endl;
        ass++;
    }

    std::cout << sizeof(arrays) << std::endl;
    std::cout << kapasitas << std::endl;

    float asd[10];
    std::cout << asd[15] << std::endl;
    
}

void LoaderObj::selfDraw() {
    glBindVertexArray(VAo);
    glBindBuffer(GL_ARRAY_BUFFER, bufferData);
    glDrawArrays(GL_TRIANGLES, 0, 33);
    glBindVertexArray(0);
}

void LoaderObj::manualDraw() {

}