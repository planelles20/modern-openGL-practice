#include "mesh.h"

Mesh::Mesh(const unsigned int X, const unsigned int Y, const unsigned int Z) {
    //
    this->X = X;
    this->Y = Y;
    this->Z = Z;

    this->numPoints = X*Y*Z;
    this->numIndices = (2*3*(this->X-1)*(this->Y-1)*this->Z)
                      +(2*3*this->X*(this->Y-1)*(this->Z-1))
                      +(2*3*(this->X-1)*this->Y*(this->Z-1));

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
    glBindVertexArray(0);             // Unbind VAO
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
    for(int k=0; k<this->Z; k++){
        float auxk = k/(float(this->Z-1)/2.0)-1.0;
        for(int j=0; j<this->Y; j++){
            float auxj = j/(float(this->Y-1)/2.0)-1.0;
            for(int i=0; i<this->X; i++){
                float auxi = i/(float(this->X-1)/2.0)-1.0;
                //poition
                this->malla[i+j*this->X+k*this->X*this->Y].x = auxi;
                this->malla[i+j*this->X+k*this->X*this->Y].y = auxj;
                this->malla[i+j*this->X+k*this->X*this->Y].z = auxk;
            }
        }
    }
}

void Mesh::CreateIndeces(){
    int l = 0;
    //normal to z
	for (int k = 0; k<(this->Z); k++) {
    	for (int j = 0; j<(this->Y-1); j++) {
    		for (int i = 0; i<(this->X-1); i++) {
                //down triangles
    			this->indices[l++] = i+j*this->X+k*this->X*this->Y;
    			this->indices[l++] = i+1+j*this->X+k*this->X*this->Y;
    			this->indices[l++] = i+(j+1)*this->X+k*this->X*this->Y;
                //up triangles
                this->indices[l++] = i+1+(j+1)*this->X+k*this->X*this->Y;
    			this->indices[l++] = i+(j+1)*this->X+k*this->X*this->Y;
    			this->indices[l++] = i+1+j*this->X+k*this->X*this->Y;
    		}
        }
	}
    //normal to x
    for (int i = 0; i<(this->X); i++) {
        for (int k = 0; k<(this->Z-1); k++) {
    	       for (int j = 0; j<(this->Y-1); j++) {
                //down triangles
    			this->indices[l++] = i+(j+1)*this->X+(k+1)*this->X*this->Y;
    			this->indices[l++] = i+j*this->X+k*this->X*this->Y;
    			this->indices[l++] = i+(j+1)*this->X+k*this->X*this->Y;
                //up triangles
                this->indices[l++] = i+(j+1)*this->X+(k+1)*this->X*this->Y;
    			this->indices[l++] = i+j*this->X+(k+1)*this->X*this->Y;
    			this->indices[l++] = i+j*this->X+k*this->X*this->Y;
    		}
        }
	}
    //normal to y
    for (int j = 0; j<(this->Y); j++) {
        for (int k = 0; k<(this->Z-1); k++) {
            for (int i = 0; i<(this->X-1); i++) {
                //down triangles
    			this->indices[l++] = i+1+j*this->X+(k+1)*this->X*this->Y;
    			this->indices[l++] = i+j*this->X+k*this->X*this->Y;
    			this->indices[l++] = i+1+j*this->X+k*this->X*this->Y;
                //up triangles
                this->indices[l++] = i+1+j*this->X+(k+1)*this->X*this->Y;
    			this->indices[l++] = i+j*this->X+(k+1)*this->X*this->Y;
    			this->indices[l++] = i+j*this->X+k*this->X*this->Y;
    		}
        }
	}
}

void Mesh::PolygonMode(){
    //this call will result in wireframe polygons.
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
