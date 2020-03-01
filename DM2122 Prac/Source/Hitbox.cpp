#include "Hitbox.h"

Hitbox::Hitbox() {

}

Hitbox::Hitbox(Vector3 translation, Vector3 size) {
	setDimensions(size);
	setDisplacement(translation);
	setDegrees(0.f);
	setRotate(Vector3(0, 0, 0));
}

Hitbox::Hitbox(Vector3 translation, Vector3 size, float degrees, Vector3 rotation) {
	setDimensions(size);
	setDisplacement(translation);
	setDegrees(degrees);
	setRotate(rotation);
}

Hitbox::~Hitbox() {

}

void Hitbox::setDisplacement(Vector3 translate) {
	displacement = translate;
}

void Hitbox::setDimensions(Vector3 size) {
	dimensions = size;
}

Vector3 Hitbox::getDisplacement() {
	return displacement;
}

Vector3 Hitbox::getDimensions() {
	return dimensions;
}

void Hitbox::setRotate(Vector3 rotate) {
	rotateAxis = rotate;
}

void Hitbox::setDegrees(float degrees) {
	rotateDegrees = degrees;
}

void Hitbox::setVertices(std::vector<Mtx44> vertices) {
	this->vertices = vertices;
}

Vector3 Hitbox::getRotate() {
	return rotateAxis;
}

float Hitbox::getDegrees() {
	return rotateDegrees;
}

std::vector<Mtx44> Hitbox::getVerticeLib() {
	return vertices;
}

Mtx44 Hitbox::getVertices(int i) {
	return vertices[i];
}

void Hitbox::setAxes(Mtx44 axis[3]) {
	for (int i = 0; i < 3; i++) {
		axes[i] = axis[i];
	}
}

Mtx44 Hitbox::getAxes(int axis) {
	return axes[axis];
}