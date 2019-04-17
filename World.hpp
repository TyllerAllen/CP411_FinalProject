/*
 * HBF
 */
#ifndef CWORLD_HPP
#define CWORLD_HPP
#include <iostream>
#include <list>
#include <vector>
#include "Board.hpp"
#include "Vehicle.hpp"

class World {

public:
	GLint counter;
	Shape *list[14];
	World();
	~World();
	void insert(Shape *v, int i);
	void drawWorld();  // draw all objects in the world
	void resetWorld(); //resets all objects
};

#endif
