#ifndef VEHICLE_HPP_
#define VEHICLE_HPP_

#include <GL/glut.h>
#include <stdio.h>
#include "Shape.hpp"
#include "Camera.hpp"
#include "Menu.hpp"

class Vehicle: public Shape {
protected:
	GLfloat vertex[8][3];	//[v]->[x][y][z]
	GLint face[6][4];		//[face][vertex index]
	GLfloat cube_face_norm_mc[6][3];  // normal for each face in MC
	GLfloat r, g, b;
	GLint direction;	// Horizontal = 0, Vertical = 1
	GLint id;
	GLint length;

public:
	Vehicle(GLint size, GLint id, GLint dir);
	Vehicle() = delete;
	~Vehicle();
	GLint getID();
	GLint getDir();
	GLint getLength();
	bool isBackface(int faceindex);
	void draw();
	void drawMC();

private:
	void draw_face(int i, int f);
};

#endif /* VEHICLE_HPP_ */
