#include "Object.h"

Object::Object() {
	translate = Vector3(0, 0, 0);
	scale = Vector3(1, 1, 1);
	rotateAxis = Vector3(0, 1, 0);
	rotateDegrees = 0.f;
	this->ID = ID;
	mesh = nullptr;
	enableLight = false;
	parent = nullptr;
}

Object::Object(std::string ID, Mesh* object, bool light) {
	translate = Vector3(0, 0, 0);
	scale = Vector3(1, 1, 1);
	rotateAxis = Vector3(0, 1, 0);
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
	rotateAxis = Vector3(0, 1, 0);
	rotateDegrees = 0.f;
	this->ID = ID;
	mesh = object;
	enableLight = light;
	parent = parent;
	pos = parent->translate;
}

Object::~Object() {
	mesh = nullptr;
	for (int i = 0; i < HitboxLib.size(); i++) {
		delete HitboxLib[i];
	}
	HitboxLib.clear();
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
		modelStack.Translate(translate.x, translate.y, translate.z);
		modelStack.Scale(parent->scale.x, parent->scale.y, parent->scale.z);
		modelStack.Scale(scale.x, scale.y, scale.z);
		if (parent->rotateDegrees != 0) {
			modelStack.Rotate(parent->rotateDegrees, parent->rotateAxis.x, parent->rotateAxis.y, parent->rotateAxis.z);
		}
	}
	else {
		modelStack.Scale(scale.x, scale.y, scale.z);
		modelStack.Translate(translate.x, translate.y, translate.z);
		if (rotateDegrees != 0) {
			modelStack.Rotate(rotateDegrees, rotateAxis.x, rotateAxis.y, rotateAxis.z);
		}
	}
}

void Object::AddHitbox(Vector3 translate, Vector3 size) {
	Hitbox* box = new Hitbox(translate, size);
	HitboxLib.push_back(box);
}

void Object::AddHitbox(Vector3 translation, Vector3 size, float degrees, Vector3 rotation) {
	Hitbox* box = new Hitbox(translation, size, degrees, rotation);
	HitboxLib.push_back(box);
}

std::vector<Hitbox*> Object::getHitboxLib() {
	return HitboxLib;
}

Vector3 Object::getPos() {
	return pos;
}

void Object::setPos(Vector3 posi) {
	pos = posi;
}

Vector3 Object::getScale() {
	return scale;
}

Vector3 Object::getRotate() {
	return rotateAxis;
}

float Object::getRotateDegrees() {
	return rotateDegrees;
}

void Object::setRotate(Vector3 rotate) {
	rotateAxis = rotate;
}

void Object::setRotateDegrees(float degrees) {
	rotateDegrees = degrees;
}
