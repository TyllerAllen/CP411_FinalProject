/*
 * board.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "Board.hpp"

extern Vehicle* myVehicles[13];
extern bool loaded[13];

extern GLint selected;
extern GLint topX, topY, bottomX, bottomY;

extern World myWorld;
extern Camera myCamera;

Board::Board() {
	complete = false;
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i == 0 || j == 0) || (i == 7 || j == 7)) {
				matrix[i][j] = 1;
			} else {
				matrix[i][j] = 0;
			}
		}
	}

	matrix[3][7] = 0;	// Escape block

	/*-------Base Plate-------*/
	vertex[0][0] = -4;vertex[0][1] = -1;vertex[0][2] = -4; // Back left bottom
	vertex[1][0] = -4;vertex[1][1] = 0;vertex[1][2] = -4; // Back left top
	vertex[2][0] = 4;vertex[2][1] = 0;vertex[2][2] = -4; // Back right top
	vertex[3][0] = 4;vertex[3][1] = -1;vertex[3][2] = -4; // Back right bottom

	vertex[4][0] = -4;vertex[4][1] = -1;vertex[4][2] = 4; // Front left bottom
	vertex[5][0] = -4;vertex[5][1] = 0;vertex[5][2] = 4; // Front left top
	vertex[6][0] = 4;vertex[6][1] = 0;vertex[6][2] = 4; // Front right top
	vertex[7][0] = 4;vertex[7][1] = -1;vertex[7][2] = 4; // Front right bottom

	/*-------Top Wall-------*/

	// Back left bottom -- vertex[1][]
	vertex[8][0] = -4;vertex[8][1] = 1;vertex[8][2] = -4; // Back left top
	vertex[9][0] = 4;vertex[9][1] = 1;vertex[9][2] = -4; // Back right top
	// Back right bottom -- vertex[2][]

	vertex[10][0] = -4;vertex[10][1] = 0;vertex[10][2] = -3; // Front left bottom
	vertex[11][0] = -4;vertex[11][1] = 1;vertex[11][2] = -3; // Front left top
	vertex[12][0] = 4;vertex[12][1] = 1;vertex[12][2] = -3; // Front right top
	vertex[13][0] = 4;vertex[13][1] = 0;vertex[13][2] = -3; // Front right bottom

	/*-------Bottom Wall-------*/

	vertex[14][0] = -4;vertex[14][1] = 0;vertex[14][2] = 3; // Back left bottom
	vertex[15][0] = -4;vertex[15][1] = 1;vertex[15][2] = 3; // Back left top
	vertex[16][0] = 4;vertex[16][1] = 1;vertex[16][2] = 3; // Back right top
	vertex[17][0] = 4;vertex[17][1] = 0;vertex[17][2] = 3; // Back right bottom

	// Front left bottom -- vertex[5][]
	vertex[18][0] = -4;vertex[18][1] = 1;vertex[18][2] = 4; // Front left top
	vertex[19][0] = 4;vertex[19][1] = 1;vertex[19][2] = 4; // Front right top
	// Front right bottom -- vertex[6][]

	/*-------Left Wall-------*/

	// Back left bottom -- vertex[10][]
	// Back left top -- vertex[11][]
	vertex[20][0] = -3;vertex[20][1] = 1;vertex[20][2] = -3; // Back right top
	vertex[21][0] = -3;vertex[21][1] = 0;vertex[21][2] = -3; // Back right bottom

	// Front left bottom -- vertex[14][]
	// Front left top -- vertex[15][]
	vertex[22][0] = -3;vertex[22][1] = 1;vertex[22][2] = 3; // Front right top
	vertex[23][0] = -3;vertex[23][1] = 0;vertex[23][2] = 3; // Front right bottom

	/*-------Right Top Wall-------*/

	vertex[24][0] = 3;vertex[24][1] = 0;vertex[24][2] = -3; // Back left bottom
	vertex[25][0] = 3;vertex[25][1] = 1;vertex[25][2] = -3; // Back left top
	// Back right top -- vertex[12][]
	// Back right bottom -- vertex[13][]

	vertex[26][0] = 3;vertex[26][1] = 0;vertex[26][2] = -1; // Front left bottom
	vertex[27][0] = 3;vertex[27][1] = 1;vertex[27][2] = -1; // Front left top
	vertex[28][0] = 4;vertex[28][1] = 1;vertex[28][2] = -1; // Front right top
	vertex[29][0] = 4;vertex[29][1] = 0;vertex[29][2] = -1; // Front right bottom

	/*-------Right Bottom Wall-------*/

	vertex[30][0] = 3;vertex[30][1] = 0;vertex[30][2] = 0; // Back left bottom
	vertex[31][0] = 3;vertex[31][1] = 1;vertex[31][2] = 0; // Back left top
	vertex[32][0] = 4;vertex[32][1] = 1;vertex[32][2] = 0; // Back right top
	vertex[33][0] = 4;vertex[33][1] = 0;vertex[33][2] = 0; // Back right bottom

	vertex[34][0] = 3;vertex[34][1] = 0;vertex[34][2] = 3; // Front left bottom
	vertex[35][0] = 3;vertex[35][1] = 1;vertex[35][2] = 3; // Front left top
	// Front right top -- vertex[16][]
	// Front right bottom -- vertex[17][]

	/*-------Base Plate-------*/
	face[0][0] = 1;face[0][1] = 2;face[0][2] = 6;face[0][3] = 5; // Top
	face[1][0] = 0;face[1][1] = 3;face[1][2] = 7;face[1][3] = 4; // Bottom
	face[2][0] = 6;face[2][1] = 2;face[2][2] = 3;face[2][3] = 7; // Right
	face[3][0] = 1;face[3][1] = 5;face[3][2] = 4;face[3][3] = 0; // Left
	face[4][0] = 5;face[4][1] = 6;face[4][2] = 7;face[4][3] = 4; // Front
	face[5][0] = 1;face[5][1] = 2;face[5][2] = 3;face[5][3] = 0; // Back

	cube_face_norm_mc[0][0] = 0.0,cube_face_norm_mc[0][1] = 1.0,cube_face_norm_mc[0][2] = 0.0,
	cube_face_norm_mc[1][0] = 0.0, cube_face_norm_mc[1][1] = -1.0, cube_face_norm_mc[1][2] = 0.0;
	cube_face_norm_mc[2][0] = 1.0, cube_face_norm_mc[2][1] = 0.0, cube_face_norm_mc[2][2] = 0.0;
	cube_face_norm_mc[3][0] = -1.0, cube_face_norm_mc[3][1] = 0.0, cube_face_norm_mc[3][2] = 0.0;
	cube_face_norm_mc[4][0] = 0.0, cube_face_norm_mc[4][1] = 0.0, cube_face_norm_mc[4][2] = 1.0;
	cube_face_norm_mc[5][0] = 0.0, cube_face_norm_mc[5][1] = 0.0, cube_face_norm_mc[5][2] = -1.0;

	/*-------Top Wall-------*/
	face[6][0] = 8;face[6][1] = 9;face[6][2] = 12;face[6][3] = 11; // Top
	face[7][0] = 1;face[7][1] = 2;face[7][2] = 13;face[7][3] = 10; // Bottom
	face[8][0] = 12;face[8][1] = 9;face[8][2] = 2;face[8][3] = 13; // Right
	face[9][0] = 8;face[9][1] = 11;face[9][2] = 10;face[9][3] = 1; // Left
	face[10][0] = 11;face[10][1] = 12;face[10][2] = 13;face[10][3] = 10; // Front
	face[11][0] = 8;face[11][1] = 9;face[11][2] = 2;face[11][3] = 1; // Back

	cube_face_norm_mc[6][0] = 0.0,cube_face_norm_mc[6][1] = 1.0,cube_face_norm_mc[6][2] = 0.0,
	cube_face_norm_mc[7][0] = 0.0, cube_face_norm_mc[7][1] = -1.0, cube_face_norm_mc[7][2] = 0.0;
	cube_face_norm_mc[8][0] = 1.0, cube_face_norm_mc[8][1] = 0.0, cube_face_norm_mc[8][2] = 0.0;
	cube_face_norm_mc[9][0] = -1.0, cube_face_norm_mc[9][1] = 0.0, cube_face_norm_mc[9][2] = 0.0;
	cube_face_norm_mc[10][0] = 0.0, cube_face_norm_mc[10][1] = 0.0, cube_face_norm_mc[10][2] = 1.0;
	cube_face_norm_mc[11][0] = 0.0, cube_face_norm_mc[11][1] = 0.0, cube_face_norm_mc[11][2] = -1.0;

	/*-------Bottom Wall-------*/
	face[12][0] = 15;face[12][1] = 16;face[12][2] = 19;face[12][3] = 18; // Top
	face[13][0] = 14;face[13][1] = 17;face[13][2] = 6;face[13][3] = 5; // Bottom
	face[14][0] = 19;face[14][1] = 16;face[14][2] = 17;face[14][3] = 6; // Right
	face[15][0] = 15;face[15][1] = 18;face[15][2] = 5;face[15][3] = 14; // Left
	face[16][0] = 18;face[16][1] = 19;face[16][2] = 6;face[16][3] = 5; // Front
	face[17][0] = 15;face[17][1] = 16;face[17][2] = 17;face[17][3] = 14; // Back

	cube_face_norm_mc[12][0] = 0.0,		cube_face_norm_mc[12][0] = 1.0,		cube_face_norm_mc[12][0] = 0.0,
	cube_face_norm_mc[13][0] = 0.0, 	cube_face_norm_mc[13][0] = -1.0, 	cube_face_norm_mc[13][0] = 0.0;
	cube_face_norm_mc[14][0] = 1.0, 	cube_face_norm_mc[14][0] = 0.0, 	cube_face_norm_mc[14][0] = 0.0;
	cube_face_norm_mc[15][0] = -1.0, 	cube_face_norm_mc[15][0] = 0.0, 	cube_face_norm_mc[15][0] = 0.0;
	cube_face_norm_mc[16][0] = 0.0, 	cube_face_norm_mc[16][0] = 0.0, 	cube_face_norm_mc[16][0] = 1.0;
	cube_face_norm_mc[17][0] = 0.0, 	cube_face_norm_mc[17][0] = 0.0, 	cube_face_norm_mc[17][0] = -1.0;

	/*-------Left Wall-------*/
	face[18][0] = 11;face[18][1] = 20;face[18][2] = 22;face[18][3] = 15; // Top
	face[19][0] = 10;face[19][1] = 21;face[19][2] = 23;face[19][3] = 14; // Bottom
	face[20][0] = 22;face[20][1] = 20;face[20][2] = 21;face[20][3] = 23; // Right
	face[21][0] = 11;face[21][1] = 15;face[21][2] = 14;face[21][3] = 10; // Left
	face[22][0] = 15;face[22][1] = 22;face[22][2] = 23;face[22][3] = 14; // Front
	face[23][0] = 11;face[23][1] = 20;face[23][2] = 21;face[23][3] = 10; // Back

	cube_face_norm_mc[18][0] = 0.0,		cube_face_norm_mc[18][0] = 1.0,		cube_face_norm_mc[18][0] = 0.0,
	cube_face_norm_mc[19][0] = 0.0, 	cube_face_norm_mc[19][0] = -1.0, 	cube_face_norm_mc[19][0] = 0.0;
	cube_face_norm_mc[20][0] = 1.0, 	cube_face_norm_mc[20][0] = 0.0, 	cube_face_norm_mc[20][0] = 0.0;
	cube_face_norm_mc[21][0] = -1.0, 	cube_face_norm_mc[21][0] = 0.0, 	cube_face_norm_mc[21][0] = 0.0;
	cube_face_norm_mc[22][0] = 0.0, 	cube_face_norm_mc[22][0] = 0.0, 	cube_face_norm_mc[22][0] = 1.0;
	cube_face_norm_mc[23][0] = 0.0, 	cube_face_norm_mc[23][0] = 0.0, 	cube_face_norm_mc[23][0] = -1.0;

	/*-------Right Top Wall-------*/
	face[24][0] = 25;face[24][1] = 12;face[24][2] = 28;face[24][3] = 27; // Top
	face[25][0] = 24;face[25][1] = 13;face[25][2] = 29;face[25][3] = 26; // Bottom
	face[26][0] = 28;face[26][1] = 12;face[26][2] = 13;face[26][3] = 29; // Right
	face[27][0] = 25;face[27][1] = 27;face[27][2] = 26;face[27][3] = 24; // Left
	face[28][0] = 27;face[28][1] = 28;face[28][2] = 29;face[28][3] = 26; // Front
	face[29][0] = 25;face[29][1] = 12;face[29][2] = 13;face[29][3] = 24; // Back

	cube_face_norm_mc[24][0] = 0.0,		cube_face_norm_mc[24][0] = 1.0,		cube_face_norm_mc[24][0] = 0.0,
	cube_face_norm_mc[25][0] = 0.0, 	cube_face_norm_mc[25][0] = -1.0, 	cube_face_norm_mc[25][0] = 0.0;
	cube_face_norm_mc[26][0] = 1.0, 	cube_face_norm_mc[26][0] = 0.0, 	cube_face_norm_mc[26][0] = 0.0;
	cube_face_norm_mc[27][0] = -1.0, 	cube_face_norm_mc[27][0] = 0.0, 	cube_face_norm_mc[27][0] = 0.0;
	cube_face_norm_mc[28][0] = 0.0, 	cube_face_norm_mc[28][0] = 0.0, 	cube_face_norm_mc[28][0] = 1.0;
	cube_face_norm_mc[29][0] = 0.0, 	cube_face_norm_mc[29][0] = 0.0, 	cube_face_norm_mc[29][0] = -1.0;

	/*-------Right Bottom Wall-------*/
	face[30][0] = 31;face[30][1] = 32;face[30][2] = 16;face[30][3] = 35; // Top
	face[31][0] = 30;face[31][1] = 33;face[31][2] = 17;face[31][3] = 34; // Bottom
	face[32][0] = 16;face[32][1] = 32;face[32][2] = 33;face[32][3] = 17; // Right
	face[33][0] = 31;face[33][1] = 35;face[33][2] = 34;face[33][3] = 30; // Left
	face[34][0] = 35;face[34][1] = 16;face[34][2] = 17;face[34][3] = 34; // Front
	face[35][0] = 31;face[35][1] = 32;face[35][2] = 33;face[35][3] = 30; // Back

	cube_face_norm_mc[30][0] = 0.0,		cube_face_norm_mc[30][0] = 1.0,		cube_face_norm_mc[30][0] = 0.0,
	cube_face_norm_mc[31][0] = 0.0, 	cube_face_norm_mc[31][0] = -1.0, 	cube_face_norm_mc[31][0] = 0.0;
	cube_face_norm_mc[32][0] = 1.0, 	cube_face_norm_mc[32][0] = 0.0, 	cube_face_norm_mc[32][0] = 0.0;
	cube_face_norm_mc[33][0] = -1.0, 	cube_face_norm_mc[33][0] = 0.0, 	cube_face_norm_mc[33][0] = 0.0;
	cube_face_norm_mc[34][0] = 0.0, 	cube_face_norm_mc[34][0] = 0.0, 	cube_face_norm_mc[34][0] = 1.0;
	cube_face_norm_mc[35][0] = 0.0, 	cube_face_norm_mc[35][0] = 0.0, 	cube_face_norm_mc[35][0] = -1.0;
}

Board::~Board() {

}

//Gets the value at cell [i,j]
int Board::getCell(int i, int j){
	return matrix[i][j];
}

//gets the
void Board::getSides(){
	int i, j;
	bool found = false;

	i = 0;
	while(!found && i < 8){
		j = 0;
		while(!found && j < 8){
			if(matrix[i][j] == selected + 1){
				found = true;
				topX = j;
				topY = i;
				if(myVehicles[selected - 1]->getDir()){ // if vertical
					bottomX = j;
					bottomY = i + myVehicles[selected - 1]->getLength() - 1;
				}
				else{ // if horizontal
					bottomX = j + myVehicles[selected - 1]->getLength() - 1;
					bottomY = i;
				}
			}
			j++;
		}
		i++;
	}
}

//Sets the board to either complete or not complete
void Board::setComplete(GLboolean b){
	complete = b;
}

//Checks if board is complete
GLboolean Board::getComplete(){
	return complete;
}

//checks if a given face is a backface
bool Board::isBackface(int faceindex) {
	GLfloat v[4];
    v[0] = cube_face_norm_mc[faceindex][0];
    v[1] = cube_face_norm_mc[faceindex][1];
    v[2] = cube_face_norm_mc[faceindex][2];
    v[3] = 0.0;
    this->mc.multiplyVector(v);

    return (myCamera.ref.x-myCamera.eye.x)*v[0] + (myCamera.ref.y - myCamera.eye.y)*v[1] + (myCamera.ref.z - myCamera.eye.z)*v[2] > 0;
}

//Updates the board's matrix after a move
void Board::update(GLfloat t){
	int i, j;
	bool found = false;

	i = 0;
	while(!found && i < 8){
		j = 0;
		while(!found && j < 8){
			if(matrix[i][j] == selected + 1){
				found = true;
				if(myVehicles[selected - 1]->getDir()){ // if vertical
					if(t == 1){ // if moving up
						matrix[topY - 1][topX] = selected + 1;
						matrix[bottomY][bottomX] = 0;
					}
					else{	// if moving down
						matrix[topY][topX] = 0;
						matrix[bottomY + 1][bottomX] = selected + 1;
					}
				}
				else{ // if horizontal
					if(t == 1){ // if moving right
						matrix[topY][topX] = 0;
						matrix[bottomY][bottomX + 1] = selected + 1;
					}
					else{	// if moving left
						matrix[topY][topX - 1] = selected + 1;
						matrix[bottomY][bottomX] = 0;
					}
				}
			}
			j++;
		}
		i++;
	}
	if(matrix[3][7] == 2){
		complete = true;
	}
}

//Sets the board to a given level
void Board::setLevel(GLint mat[6][6]) {
	complete = false;
	int id, i, j;

	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			matrix[i][j] = mat[i - 1][j - 1];
		}
	}

	for (i = 1; i < 7; i++) {
		for (j = 1; j < 7; j++) {
			id = matrix[i][j];
			//printf("[%d][%d] = %d\n", i,j,id);
			if (id > 1 && !loaded[id - 2]) {
				//printf("Drawing %d\n", myVehicles[id-2]->getID());
				myVehicles[id - 2]->draw();
				myVehicles[id - 2]->translate(j - 4, 0, i - 4);
				loaded[id - 2] = true;
				myWorld.insert(myVehicles[id-2], id - 1);
			}
		}
	}
}

//Draws a face of the board
void Board::drawFace(GLint f, GLint l) {
	if (f < 6) {
		glColor3f(0.5, 0.5, 0.5);
	} else {
		glColor3f(0.4, 0.3, 0.2);
	}
	glBegin(GL_POLYGON);
	glVertex3fv(vertex[face[f][0]]);
	glVertex3fv(vertex[face[f][1]]);
	glVertex3fv(vertex[face[f][2]]);
	glVertex3fv(vertex[face[f][3]]);
	glEnd();

	if (l) {
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex3fv(vertex[face[f][0]]);
		glVertex3fv(vertex[face[f][1]]);
		glVertex3fv(vertex[face[f][2]]);
		glVertex3fv(vertex[face[f][3]]);
		glEnd();
	}
}

//Draws the board
void Board::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(s, s, s);
	int i;

	for (i = 0; i < 36; i++) {
		if(!isBackface(i)){
			if (i != 0 && (i % 6 == 0 || i == 10 || i == 17 || i == 20 || i == 27 || i == 28 || i == 33 || i == 37)) {
				drawFace(i, 1);
			} else {
				drawFace(i, 0);
			}
		}
	}

	glPopMatrix();
}

