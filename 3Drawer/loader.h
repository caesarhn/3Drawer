#pragma once
#include <vector>
#include <string>


class LoaderObj {
    struct vertex {
        float x;
        float y;
        float z;
    };
    struct face {
        std::string v1;
        std::string v2;
        std::string v3;
    };
    std::vector<vertex> vetexes;
    std::vector<face> faces;
    std::string facee[1000][3];

    float vert[1000][3];
    int ve = 0;
    float verte[1000][3][3];

    float vnormal[1000][3];
    int vn = 0;

    unsigned int kapasitas = 0;

public:

    unsigned int bufferData;
    unsigned int VAo;
    void readfile(const char* filename);
    void draw();
    void getObjVec();
    void* arrayToBuffer(float* array);
    void selfBuffers();
    void selfDraw();
    int retVe();
    void print();
    void manualDraw();

};