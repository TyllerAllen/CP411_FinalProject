/*
 * menu.hpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Stephanie
 */

#ifndef MENU_HPP_
#define MENU_HPP_

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Board.hpp"
#include "Vehicle.hpp"
#include "World.hpp"

void menu();
void levelSelect(GLint option);
void colorSelect(GLint option);
void mainMenu(GLint option);


#endif /* MENU_HPP_ */
