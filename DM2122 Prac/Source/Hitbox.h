#ifndef HITBOX_H
#define HITBOX_H

#include "..\..\Common\Source\Vector3.h"
#include "..\..\Common\Source\Mtx44.h"
#include <vector>


class Hitbox
{
private:
	Vector3 displacement;
	Vector3 rotateAxis;
	float rotateDegrees;
	Vector3 dimensions; // x - width, y - height, z - depth
	std::vector<Mtx44> vertices;
	Mtx44 axes[3];

public:
	Hitbox();
	Hitbox(Vector3 translation, Vector3 size);
	Hitbox(Vector3 translation, Vector3 size, float degrees, Vector3 rotation);
	~Hitbox();
	void setDisplacement(Vector3 translate);
	void setDimensions(Vector3 size);
	void setRotate(Vector3 rotate);
	void setDegrees(float degrees);
	Vector3 getDisplacement();
	Vector3 getDimensions();
	Vector3 getRotate();
	float getDegrees();
	void setVertices(std::vector<Mtx44> vertice);
	std::vector<Mtx44> getVerticeLib();
	Mtx44 getVertices(int i);
	void setAxes(Mtx44 axis[3]);
	Mtx44 getAxes(int axis);

};

#endif