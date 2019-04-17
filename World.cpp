#include "World.hpp"

World::World() {
	counter = 0;
	list[0] = (Shape*) malloc(sizeof(Shape*) * counter);

}

World::~World(){
	for (int i=0; i < counter; i++)
		delete list[i];
}

void World::insert(Shape *v, int i){
	if(counter < 14){
		list[i] = v;
		counter++;
	}
}

void World::drawWorld() {
	for (int i = 0; i < counter; i++){
		list[i]->draw();
	}
}

void World::resetWorld(){
	list[0]->reset();
}

