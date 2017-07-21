#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>

struct point {
    //position
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

class Mesh {
    public:
        Mesh(const unsigned int X, const unsigned int Y, const unsigned int Z);
        virtual ~Mesh();
        void BackGround(float r, float g, float b, float a);
        void Draw();
        void PolygonMode();
    protected:

    private:
        int X, Y, Z;
        int numIndices, numPoints;
        GLuint VBO, VAO, EBO;
        point *malla;
        GLushort *indices;
        void CreateMesh();
        void CreateIndeces();
};

#endif // MESH_H
