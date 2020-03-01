#ifndef COLLISION_H
#define COLLISION_H

#include "Hitbox.h"
#include "ObjectManager.h"
#include <vector>
#include <string>

class Collisions
{
private:

public:

	Collisions();
	~Collisions();

	static void verticesCalc(Object* Objects);
	static void axisCalc(Object* Objects);
	static bool colliCheck(Object* first, Object* second);

};
#endif