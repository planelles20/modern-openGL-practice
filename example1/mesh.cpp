#include "mesh.h"

Mesh::Mesh(const unsigned int X, const unsigned int Y) {
    //
    this->X = X;
    this->Y = Y;

    this->numPoints = this->X*this->Y;
    this->numIndices = 2*3*(this->X-1)*(this->Y-1);

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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

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
    for (int j=0; j<this->Y; j++){
        float auxj = j/(float(this->Y-1)/2.0)-1.0;
        for (int i=0; i<this->X; i++) {
            float auxi = i/(float(this->X-1)/2.0)-1.0;
            //poition
            this->malla[j*this->X+i].x = auxi;
            this->malla[j*this->X+i].y = auxj;
            this->malla[j*this->X+i].z = 0.0;
            //color
            this->malla[j*this->X+i].r = auxi;
            this->malla[j*this->X+i].g = auxj;
            this->malla[j*this->X+i].b = 0.5;
        }
    }
}

void Mesh::CreateIndeces(){
    int i = 0;

	for (int y = 0; y < (this->Y-1); y++) {
		for (int x = 0; x < (this->X-1); x++) {
            //down triangles
			this->indices[i++] = x+y*this->X;
			this->indices[i++] = x+1+y*this->X;
			this->indices[i++] = x+(y+1)*this->X;
            //up triangles
            this->indices[i++] = x+y*X+1+X;
			this->indices[i++] = x+(y+1)*X;
			this->indices[i++] = x+1+y*X;
		}
	}
}

void Mesh::PolygonMode(){
    //this call will result in wireframe polygons.
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
