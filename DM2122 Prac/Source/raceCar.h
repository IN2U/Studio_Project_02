#ifndef RACECAR_H
#define RACECAR_H

#include "Scene.h"
#include <MatrixStack.h>
#include "Camera2.h"
#include "Mesh_Generation/Mesh.h"
#include "Light.h"
#include "ObjectManager.h"
#include "Collision.h"

class raceCar : public Object
{
private:
	float mass;
	Vector3 acceleration;
	Vector3 deccelaration;
	Vector3 momentum;
	Vector3 velocity;
	Vector3 Force;
	Vector3 Friction;
	Mtx44 rotation;

public:
	raceCar();
	raceCar(float mass);
	~raceCar();

	void setRotation(Mtx44 rotate);
	Mtx44 getRotation();
	void Accelerate(Vector3 force);
	void Physics();
	void Update(double dt);

};

#endif