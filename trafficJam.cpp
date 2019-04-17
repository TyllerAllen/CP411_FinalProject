//============================================================================
// Name        : trafficJam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gl/glut.h>
#include<windows.h>

#include "Board.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Menu.hpp"
#include "Vehicle.hpp"
using namespace std;

//Global Variables
GLint winWidth = 700;
GLint winHeight = 700;
GLint xbegin = 0;
Board *myBoard;	// Game board
Vehicle* myVehicles[13];
GLint numVehicles = 0;
GLint numMoves=0;
bool loaded[13];

GLint selected = 1;	// Selected vehicle (from color menu) -- Default = Red Car
GLint moving = 0;
GLint movingDir = 0;
GLint topX, topY, bottomX, bottomY; // Top and bottom (left/right if dir == 0) coordinates of selected vehicle

World myWorld;
Camera myCamera;

void init() {

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Traffic Jam");
	glClearColor(0.0, 0.0, 0.0, 1.0);  //Set display-window color to black
	myCamera.setProjectionMatrix();

}

void drawWords(GLfloat x, GLfloat y, GLfloat z, char* s){
	glColor3f( 1,1,1);
	glRasterPos3f(x,y,z);
	int len = (int) strlen(s);
	for (int i = 0; i < len; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	}

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	//if board is not done (red car is in exit)
	if(myBoard->getComplete() == false){
		//print world
		myWorld.drawWorld();
		char move[50];
		sprintf(move, "MOVES: %d", numMoves);
		drawWords(-3,-25,-1, move);
	}
	//else
	else{
		//display WINNER and the number of moves
		char *winString = "WINNER!";
		drawWords(-0.75,8,-1,winString);
		char moves[50];
		sprintf(moves, "MOVES: %d", numMoves);
		drawWords(-1,5,-1,moves);
		glFlush();
			glutSwapBuffers();
		Sleep(3000);
		levelSelect(0);
		myBoard->setComplete(false);
		numMoves = 0;
	}

	glFlush();
	glutSwapBuffers();
}



void mouseAction(int button, int action, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (action == GLUT_DOWN) {
			moving = 1;
			xbegin = x;
		} else if (action == GLUT_UP) {
			moving = 0;
		}
	}
}

void mouseMotion(GLint x, GLint y) {
	GLfloat rx, ry, rz, theta;
	Shape *sshapep = NULL;
	sshapep = myWorld.list[selected];
	myBoard->getSides();

	if (moving) {

		if (movingDir == 0) {	// Translate x
			theta = (xbegin - x > 0) ? 1 : -1;
			if((theta == 1 && (myBoard->getCell(bottomY, bottomX + 1) == 0))
					|| (theta == -1 && (myBoard->getCell(topY, topX - 1) == 0))){
				rx = theta;
				ry = 0;
				rz = 0;
				sshapep->translate(rx, ry, rz);
				myBoard->update(theta);
				numMoves++;
			}
		}

		else {	// Translate Z
			theta = (xbegin - x > 0) ? 1 : -1;
			if((theta == 1 && (myBoard->getCell(topY - 1, topX) == 0))
					|| (theta == -1 && (myBoard->getCell(bottomY + 1, bottomX) == 0))){
				rx = 0;
				ry = 0;
				rz = -theta;
				sshapep->translate(rx, ry, rz);
				myBoard->update(theta);
				numMoves++;
			}
		}

		sshapep->getMC().normalize();
		glutPostRedisplay();
	}

}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	setvbuf(stderr, NULL, _IONBF, 0);

	glutInit(&argc, argv);
	menu();	// initialize menu
	init(); // initialize window

	myBoard = new Board(); // initialize board
	myWorld.insert(myBoard, 0); // initialize world

	for(int i = 0; i < 13; i++){
		loaded[i] = false;
	}

	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;

}
