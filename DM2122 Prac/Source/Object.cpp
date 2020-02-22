#include "Object.h"

Object::Object() {
	translate = Vector3(0, 0, 0);
	scale = Vector3(1, 1, 1);
	rotateAxis = Vector3(0, 0, 0);
	rotateDegrees = 0.f;
	this->ID = ID;
	mesh = nullptr;
	enableLight = false;
	parent = nullptr;
}

Object::Object(std::string ID, Mesh* object, bool light) {
	translate = Vector3(0, 0, 0);
	scale = Vector3(1, 1, 1);
	rotateAxis = Vector3(0, 0, 0);
	rotateDegrees = 0.f;
	this->ID = ID;
	mesh = object;
	enableLight = light;
	parent = nullptr;
	pos = Vector3(0, 0, 0);
}

Object::Object(std::string ID, Mesh* object, bool light, Object* parent) {
	translate = Vector3(0, 0, 0);
	scale = Vector3(1, 1, 1);
	rotateAxis = Vector3(0, 0, 0);
	rotateDegrees = 0.f;
	this->ID = ID;
	mesh = object;
	enableLight = light;
	parent = parent;
	pos = parent->translate;
}

Object::~Object() {
	mesh = nullptr;
}

std::string Object::getID() {
	return ID;
}

Object* Object::getParent() {
	return parent;
}

Mesh* Object::getMesh() {
	return mesh;
}

bool Object::getLight() {
	return enableLight;
}


void Object::Transform(char type, float x, float y, float z) {

	if (type == 'T') {
		translate = Vector3(x, y, z);
		pos = pos + translate;

	}
	else if (type == 'S') {
		scale = Vector3(x, y, z);
	}
	else {
		return;
	}
}

void Object::Transform(float degrees, float x, float y, float z) {

	rotateAxis = Vector3(x, y, z);
	rotateDegrees = degrees;
}

void Object::Render(MS& modelStack) {
	if (this->getParent() != nullptr) {
		modelStack.Translate(parent->translate.x, parent->translate.y, parent->translate.z);
		modelStack.Scale(parent->scale.x, parent->scale.y, parent->scale.z);
		if (parent->rotateDegrees != 0) {
			modelStack.Rotate(parent->rotateDegrees, parent->rotateAxis.x, parent->rotateAxis.y, parent->rotateAxis.z);
		}
	}
	modelStack.Translate(translate.x, translate.y, translate.z);
	modelStack.Scale(scale.x, scale.y, scale.z);
	if (rotateDegrees != 0) {
		modelStack.Rotate(rotateDegrees, rotateAxis.x, rotateAxis.y, rotateAxis.z);
	}
}
