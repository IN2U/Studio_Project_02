#include "raceCar.h"
#include "Collision.h"

raceCar::raceCar() {
	mass = 0;
	Force = acceleration = deccelaration = momentum = velocity = Vector3(0, 0, 0);
	rotation.SetToIdentity();
}

raceCar::raceCar(float mass) {
	this->mass = mass;
	acceleration = Force = deccelaration = momentum = velocity = Vector3(0, 0, 0);
	this->setPos(Vector3(27, -4, 0));
	rotation.SetToIdentity();
}

raceCar::~raceCar() {

}

void raceCar::Accelerate(Vector3 force) {
	Force = force;
	Physics();
}

void raceCar::Physics() {
	acceleration = Vector3(Force.x / mass, Force.y / mass, Force.z / mass);
}

void raceCar::Update(double dt, ObjectManager* Objects) {
	if (Objects->getLib().size() != 0) {
		if (Collisions::colliCheck(Objects->getObject("Car"), Objects->getObject("Track")) == true) {
			this->setPos(PrevPos);
		}
		else {
			PrevPos = this->getPos();
			velocity += (acceleration * dt);
			if (velocity.x != 0 || velocity.y != 0 || velocity.z != 0) {
				acceleration = acceleration * 0.6;
			}
			Vector3 position = this->getPos();
			Mtx44 temp;
			temp.SetToTranslation(velocity.x, velocity.y, velocity.z);
			temp = this->getRotation() * temp;

			position.x += (temp.a[12] * dt) - (0.5 * acceleration.x * dt * dt);
			position.y += (temp.a[13] * dt) - (0.5 * acceleration.y * dt * dt);
			position.z += (temp.a[14] * dt) - (0.5 * acceleration.z * dt * dt);
			this->setPos(position);
			Force = Vector3(0, 0, 0);
		}
	}
}

void raceCar::setRotation(Mtx44 rotation) {
	this->rotation = rotation;
}

Mtx44 raceCar::getRotation() {
	return rotation;
}
