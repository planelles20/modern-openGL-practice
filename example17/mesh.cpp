#include "mesh.h"

Mesh::Mesh(const unsigned int X, const unsigned int Y) {
    //
    this->X = X;
    this->Y = Y;

    this->numPoints = 8;
    this->numIndices = 3*2*6;

    this->malla = new point[this->numPoints];
    this->indices = new GLushort[this->numIndices];

    //create mesh (init)
    this->CreateMesh();
    this->CreateIndeces();

    //vertex array object
    glGenVertexArrays(1, &this->VAO);
    //Create vertex buffer object
    glGenBuffers(1, &this->VBO);
    //Create Element Buffer Objects
    glGenBuffers(1, &this->EBO);

    //Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(*this->malla)*this->numPoints, this->malla, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(*this->indices)*this->numIndices, this->indices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(*this->malla), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //unbind EBO
    glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind VBO
    glBindVertexArray(0); // Unbind VAO
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
}

void Mesh::BackGround(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Mesh::Draw(){

    glBindVertexArray(this->VAO);
    //glDrawArrays(GL_POINTS, 0, X*Y);

	glDrawElements(GL_TRIANGLES, this->numIndices, GL_UNSIGNED_SHORT, 0);

    glBindVertexArray(0);
}

void Mesh::CreateMesh(){
    //point 0
    this->malla[0].x = -1.0;
    this->malla[0].y = -1.0;
    this->malla[0].z = -1.0;
    //point 1
    this->malla[1].x = 1.0;
    this->malla[1].y = -1.0;
    this->malla[1].z = -1.0;
    //point 2
    this->malla[2].x = 1.0;
    this->malla[2].y = 1.0;
    this->malla[2].z = -1.0;
    //point 3
    this->malla[3].x = -1.0;
    this->malla[3].y = 1.0;
    this->malla[3].z = -1.0;
    //point 4
    this->malla[4].x = -1.0;
    this->malla[4].y = -1.0;
    this->malla[4].z = 1.0;
    //point 5
    this->malla[5].x = 1.0;
    this->malla[5].y = -1.0;
    this->malla[5].z = 1.0;
    //point 6
    this->malla[6].x = 1.0;
    this->malla[6].y = 1.0;
    this->malla[6].z = 1.0;
    //point 7
    this->malla[7].x = -1.0;
    this->malla[7].y = 1.0;
    this->malla[7].z = 1.0;
}

void Mesh::CreateIndeces(){
    //face 0
    //triangle 0
    this->indices[0] = 0;
    this->indices[1] = 1;
    this->indices[2] = 2;
    //triangle 1
    this->indices[3] = 0;
    this->indices[4] = 2;
    this->indices[5] = 3;
    //face 1
    //triangle 2
    this->indices[6] = 5;
    this->indices[7] = 1;
    this->indices[8] = 6;
    //triangle 3
    this->indices[9] = 6;
    this->indices[10] = 1;
    this->indices[11] = 2;
    //face 2
    //triangle 4
    this->indices[12] = 6;
    this->indices[13] = 2;
    this->indices[14] = 3;
    //triangle 5
    this->indices[15] = 6;
    this->indices[16] = 3;
    this->indices[17] = 7;
    //face 3
    //triangle 6
    this->indices[18] = 7;
    this->indices[19] = 3;
    this->indices[20] = 0;
    //triangle 7
    this->indices[21] = 7;
    this->indices[22] = 0;
    this->indices[23] = 4;
    //face 4
    //triangle 8
    this->indices[24] = 4;
    this->indices[25] = 0;
    this->indices[26] = 1;
    //triangle 9
    this->indices[27] = 4;
    this->indices[28] = 5;
    this->indices[29] = 1;
    //face 5
    //triangle 10
    this->indices[30] = 4;
    this->indices[31] = 5;
    this->indices[32] = 6;
    //triangle 11
    this->indices[33] = 7;
    this->indices[34] = 4;
    this->indices[35] = 6;
}

void Mesh::PolygonMode(){
    //this call will result in wireframe polygons.
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
