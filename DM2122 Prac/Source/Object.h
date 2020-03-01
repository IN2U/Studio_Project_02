#ifndef OBJECT_H
#define OBJECT_H

#include "Mesh_Generation/Mesh.h"
#include "Hitbox.h"
#include "../../Common/Source/MatrixStack.h"
#include <vector>
#include <string>

class Object
{
private:

	std::string ID;
	Mesh* mesh;
	Object* parent;
	Vector3 pos;
	Vector3 translate;
	Vector3 scale;
	Vector3 rotateAxis;
	float rotateDegrees;
	bool enableLight;
	std::vector<Hitbox*> HitboxLib;
public:

	Object();
	Object(std::string ID, Mesh* object, bool light);
	Object(std::string ID, Mesh* object, bool light, Object* parentID);
	~Object();
	std::string getID();
	Object* getParent();
	Mesh* getMesh();
	bool getLight();
	Vector3 getPos();
	void setPos(Vector3 posi);
	Vector3 getScale();
	Vector3 getRotate();
	float getRotateDegrees();
	void setRotate(Vector3 rotate);
	void setRotateDegrees(float degrees);
	void Transform(char type, float x, float y, float z);
	void Transform(float degrees, float x, float y, float z);
	void Render(MS &modelStack);
	void AddHitbox(Vector3 translate, Vector3 size);
	void AddHitbox(Vector3 translation, Vector3 size, float degrees, Vector3 rotation);
	std::vector<Hitbox*> getHitboxLib();

};
#endif