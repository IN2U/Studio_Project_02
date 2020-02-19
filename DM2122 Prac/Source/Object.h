#ifndef OBJECT_H
#define OBJECT_H

#include "Mesh.h"
#include "../../Common/Source/MatrixStack.h"
#include <vector>
#include <string>

class Object
{
private:

	std::string ID;
	Mesh* mesh;
	Object* parent;
	Vector3 translate;
	Vector3 scale;
	Vector3 rotateAxis;
	Vector3 pos;
	std::vector<Vector3> hitBox;
	float rotateDegrees;
	bool enableLight;

public:

	Object();
	Object(std::string ID, Mesh* object, bool light);
	Object(std::string ID, Mesh* object, bool light, Object* parentID);
	~Object();
	std::string getID();
	Object* getParent();
	Mesh* getMesh();
	bool getLight();
	void AddHitBox();
	void Transform(char type, float x, float y, float z);
	void Transform(float degrees, float x, float y, float z);
	void Render(MS &modelStack);

};
#endif