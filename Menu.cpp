 /*
 * menu.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#include "Menu.hpp"

extern Board *myBoard;
extern World myWorld;
extern Vehicle* myVehicles[13];
extern GLint numVehicles;
extern bool loaded[13];
extern GLint selected;
extern GLint movingDir;

void menu() {
	GLint levelMenu = glutCreateMenu(levelSelect);
	glutAddMenuEntry("Level 1", 1);
	glutAddMenuEntry("Level 2", 2);
	glutAddMenuEntry("Level 3", 3);
	glutAddMenuEntry("Test", 4);

	GLint colorMenu = glutCreateMenu(colorSelect);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Yellow", 2);
	glutAddMenuEntry("Turquoise", 3);
	glutAddMenuEntry("Cyan", 4);
	glutAddMenuEntry("Pink", 5);
	glutAddMenuEntry("Orange", 6);
	glutAddMenuEntry("Purple", 7);
	glutAddMenuEntry("Blue", 8);
	glutAddMenuEntry("Brown", 9);
	glutAddMenuEntry("Black", 10);
	glutAddMenuEntry("Grey", 11);
	glutAddMenuEntry("Green", 12);
	glutAddMenuEntry("Tan", 13);

	glutCreateMenu(mainMenu);
	glutAddSubMenu("Level Select", levelMenu);
	glutAddSubMenu("Color Select", colorMenu);
	glutAddMenuEntry("Quit", 1);

}
//Selects and sets u the board for a specificly given level
void levelSelect(GLint option) {
	for(int i = 0; i < numVehicles; i++){
		delete myVehicles[i];
		myWorld.counter--;
		loaded[i] = false;
	}
	GLint lvl[6][6];
	switch (option) {
	//http://www.puzzles.com/products/rushhour/rhfrommarkriedel/Jam.html?1
	case 0:
		numVehicles = 0;
		lvl[0][0] = 0;lvl[0][1] = 0;lvl[0][2] = 0;lvl[0][3] = 0;lvl[0][4] = 0;lvl[0][5] = 0;
		lvl[1][0] = 0;lvl[1][1] = 0;lvl[1][2] = 0;lvl[1][3] = 0;lvl[1][4] = 0;lvl[1][5] = 0;
		lvl[2][0] = 0;lvl[2][1] = 0;lvl[2][2] = 0;lvl[2][3] = 0;lvl[2][4] = 0;lvl[2][5] = 0;
		lvl[3][0] = 0;lvl[3][1] = 0;lvl[3][2] = 0;lvl[3][3] = 0;lvl[3][4] = 0;lvl[3][5] = 0;
		lvl[4][0] = 0;lvl[4][1] = 0;lvl[4][2] = 0;lvl[4][3] = 0;lvl[4][4] = 0;lvl[4][5] = 0;
		lvl[5][0] = 0;lvl[5][1] = 0;lvl[5][2] = 0;lvl[5][3] = 0;lvl[5][4] = 0;lvl[5][5] = 0;
		/*
		 * 0 0 0 0 0 0
		 * 0 0 0 0 0 0
		 * 0 0 0 0 0 0
		 * 0 0 0 0 0 0
		 * 0 0 0 0 0 0
		 * 0 0 0 0 0 0*/
		myBoard->setLevel(lvl);
		break;
	//Jam 1
	case 1:
		numVehicles = 8;
		myVehicles[0] = new Vehicle(2, 2, 0);
		myVehicles[1] = new Vehicle(2, 3, 0);
		myVehicles[2] = new Vehicle(3, 4, 1);
		myVehicles[3] = new Vehicle(3, 5, 1);
		myVehicles[4] = new Vehicle(3, 6, 1);
		myVehicles[5] = new Vehicle(2, 7, 1);
		myVehicles[6] = new Vehicle(2, 8, 0);
		myVehicles[7] = new Vehicle(3, 9, 0);

		lvl[0][0] = 3;lvl[0][1] = 3;lvl[0][2] = 0;lvl[0][3] = 0;lvl[0][4] = 0;lvl[0][5] = 4;
		lvl[1][0] = 5;lvl[1][1] = 0;lvl[1][2] = 0;lvl[1][3] = 6;lvl[1][4] = 0;lvl[1][5] = 4;
		lvl[2][0] = 5;lvl[2][1] = 2;lvl[2][2] = 2;lvl[2][3] = 6;lvl[2][4] = 0;lvl[2][5] = 4;
		lvl[3][0] = 5;lvl[3][1] = 0;lvl[3][2] = 0;lvl[3][3] = 6;lvl[3][4] = 0;lvl[3][5] = 0;
		lvl[4][0] = 7;lvl[4][1] = 0;lvl[4][2] = 0;lvl[4][3] = 0;lvl[4][4] = 8;lvl[4][5] = 8;
		lvl[5][0] = 7;lvl[5][1] = 0;lvl[5][2] = 9;lvl[5][3] = 9;lvl[5][4] = 9;lvl[5][5] = 0;
		/*
		 * 3 3 0 0 0 4
		 * 5 0 0 6 0 4
		 * 5 2 2 6 0 4
		 * 5 0 0 6 0 0
		 * 7 0 0 0 8 8
		 * 7 0 9 9 9 0
		 */
		myBoard->setLevel(lvl);
		break;
	//Jam 11
	case 2:
		numVehicles = 8;
		myVehicles[0] = new Vehicle(2, 2, 0);
		myVehicles[1] = new Vehicle(2, 3, 0);
		myVehicles[2] = new Vehicle(3, 4, 1);
		myVehicles[3] = new Vehicle(3, 5, 1);
		myVehicles[4] = new Vehicle(2, 6, 1);
		myVehicles[5] = new Vehicle(3, 7, 0);
		myVehicles[6] = new Vehicle(2, 8, 1);
		myVehicles[7] = new Vehicle(3, 9, 0);

		lvl[0][0] = 4;lvl[0][1] = 3;lvl[0][2] = 3; lvl[0][3] = 5;lvl[0][4] = 0;lvl[0][5] = 0;
		lvl[1][0] = 4;lvl[1][1] = 0;lvl[1][2] = 0; lvl[1][3] = 5;lvl[1][4] = 0;lvl[1][5] = 0;
		lvl[2][0] = 4;lvl[2][1] = 2;lvl[2][2] = 2; lvl[2][3] = 5;lvl[2][4] = 0;lvl[2][5] = 0;
		lvl[3][0] = 0;lvl[3][1] = 0;lvl[3][2] = 6; lvl[3][3] = 7;lvl[3][4] = 7;lvl[3][5] = 7;
		lvl[4][0] = 0;lvl[4][1] = 0;lvl[4][2] = 6; lvl[4][3] = 0;lvl[4][4] = 0;lvl[4][5] = 8;
		lvl[5][0] = 0;lvl[5][1] = 0;lvl[5][2] = 9; lvl[5][3] = 9;lvl[5][4] = 9;lvl[5][5] = 8;
		/*
		 * 4 3 3 5 0 0
		 * 4 0 0 5 0 0
		 * 4 2 2 5 0 0
		 * 0 0 6 7 7 7
		 * 0 0 6 0 0 8
		 * 0 0 9 9 9 8
		 */
		myBoard->setLevel(lvl);
		break;
	//Jam 21
	case 3:
		numVehicles = 7;
		myVehicles[0] = new Vehicle(2,2,0);
		myVehicles[1] = new Vehicle(2,3,0);
		myVehicles[2] = new Vehicle(2,4,1);
		myVehicles[3] = new Vehicle(3,5,1);
		myVehicles[4] = new Vehicle(3,6,1);
		myVehicles[5] = new Vehicle(3,7,0);
		myVehicles[6] = new Vehicle(3,8,0);

		lvl[0][0] = 3;lvl[0][1] = 3;lvl[0][2] = 4;lvl[0][3] = 6;lvl[0][4] = 0;lvl[0][5] = 0;
		lvl[1][0] = 5;lvl[1][1] = 0;lvl[1][2] = 4;lvl[1][3] = 6;lvl[1][4] = 0;lvl[1][5] = 0;
		lvl[2][0] = 5;lvl[2][1] = 2;lvl[2][2] = 2;lvl[2][3] = 6;lvl[2][4] = 0;lvl[2][5] = 0;
		lvl[3][0] = 5;lvl[3][1] = 7;lvl[3][2] = 7;lvl[3][3] = 7;lvl[3][4] = 0;lvl[3][5] = 0;
		lvl[4][0] = 0;lvl[4][1] = 0;lvl[4][2] = 0;lvl[4][3] = 0;lvl[4][4] = 0;lvl[4][5] = 0;
		lvl[5][0] = 0;lvl[5][1] = 0;lvl[5][2] = 0;lvl[5][3] = 8;lvl[5][4] = 8;lvl[5][5] = 8;

		/*
		 * 3 3 4 6 0 0
		 * 5 0 4 6 0 0
		 * 5 2 2 6 0 0
		 * 5 7 7 7 0 0
		 * 0 0 0 0 0 0
		 * 0 0 0 8 8 8
		 */
		myBoard->setLevel(lvl);
		break;
	case 4:
		numVehicles = 13;
		myVehicles[0] = new Vehicle(2, 2, 1);
		myVehicles[1] = new Vehicle(2, 3, 1);
		myVehicles[2] = new Vehicle(2, 4, 1);
		myVehicles[3] = new Vehicle(2, 5, 1);
		myVehicles[4] = new Vehicle(2, 6, 1);
		myVehicles[5] = new Vehicle(2, 7, 1);
		myVehicles[6] = new Vehicle(2, 8, 1);
		myVehicles[7] = new Vehicle(2, 9, 1);
		myVehicles[8] = new Vehicle(2, 10, 1);
		myVehicles[9] = new Vehicle(2, 11, 1);
		myVehicles[10] = new Vehicle(2, 12, 1);
		myVehicles[11] = new Vehicle(2, 13, 1);
		myVehicles[12] = new Vehicle(2, 14, 0);

		lvl[0][0] = 2;lvl[0][1] = 3;lvl[0][2] = 4; lvl[0][3] = 5;lvl[0][4] = 6;lvl[0][5] = 7;
		lvl[1][0] = 2;lvl[1][1] = 3;lvl[1][2] = 4; lvl[1][3] = 5;lvl[1][4] = 6;lvl[1][5] = 7;
		lvl[2][0] = 0;lvl[2][1] = 0;lvl[2][2] = 0; lvl[2][3] = 0;lvl[2][4] = 0;lvl[2][5] = 0;
		lvl[3][0] = 8;lvl[3][1] = 9;lvl[3][2] = 10; lvl[3][3] = 11;lvl[3][4] = 12;lvl[3][5] = 13;
		lvl[4][0] = 8;lvl[4][1] = 9;lvl[4][2] = 10; lvl[4][3] = 11;lvl[4][4] = 12;lvl[4][5] = 13;
		lvl[5][0] = 14;lvl[5][1] = 14;lvl[5][2] = 0; lvl[5][3] = 0;lvl[5][4] = 0;lvl[5][5] = 0;
		/*
		 * 2 3 4 5 6 7
		 * 2 3 4 5 6 7
		 * 0 0 0 0 0 0
		 * 8 9 10 11 12 13
		 * 8 9 10 11 12 13
		 * 14 14 0 0 0 0
		 */
		myBoard->setLevel(lvl);
	};
	glutPostRedisplay();
}
//Selects a car for moving, according to it's colour
void colorSelect(GLint option){
	if(!loaded[option - 1])
		selected = 1;
	else
		selected = option;
	movingDir = myVehicles[selected - 1]->getDir();
	glutPostRedisplay();
}
void mainMenu(GLint option) {
	switch (option) {
	case 1:
		exit(0);
		break;
	}
}
