/*
 * board.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <GL/glut.h>
#include <stdio.h>
#include "Vehicle.hpp"
#include "World.hpp"
#include "Camera.hpp"

class Board:public Shape{
protected:
	GLfloat vertex[36][3]; // [vertex index][x,y,z]
	GLint face[36][4]; // [face index][v1,v2,v3,v4]
	GLfloat cube_face_norm_mc[36][3];  // normal for each face in MC
	GLint matrix[8][8];
	GLboolean complete;
public:
	Board();
	~Board();
	int getCell(int i, int j); // Check if a cell is full (collision detection)
	void getSides(); // Finds top and bottom coordinates of selected vehicle
	void setComplete(GLboolean b); // sets complete value to b
	GLboolean getComplete(); //Checks if puzzle is complete
	bool isBackface(int faceindex);
	void update(GLfloat t); // Update the board with each move
	void setLevel(GLint mat[6][6]);
	void drawFace(GLint f, GLint l); // l is to draw an outline
	void draw();
};


#endif /* BOARD_HPP_ */
