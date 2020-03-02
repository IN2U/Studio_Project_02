#include "Collision.h"
#include "raceCar.h"

Collisions::Collisions() {}

Collisions::~Collisions() {}

void Collisions::verticesCalc(Object* Objects) { // Calculating vertices of a hitbox

	for (int i = 0; i < Objects->getHitboxLib().size(); i++) {
		std::vector<Mtx44> temp;
		temp.clear();
		Hitbox* currHitbox = Objects->getHitboxLib()[i];
		Vector3 pos = Objects->getPos() + currHitbox->getDisplacement();
		Mtx44 temp2;

		temp2.SetToTranslation(pos.x + currHitbox->getDimensions().x, pos.y + currHitbox->getDimensions().y, pos.z + currHitbox->getDimensions().z);
		temp.push_back(temp2);
		temp2.SetToTranslation(pos.x + currHitbox->getDimensions().x, pos.y + currHitbox->getDimensions().y, pos.z - currHitbox->getDimensions().z);
		temp.push_back(temp2);
		temp2.SetToTranslation(pos.x - currHitbox->getDimensions().x, pos.y + currHitbox->getDimensions().y, pos.z + currHitbox->getDimensions().z);
		temp.push_back(temp2);
		temp2.SetToTranslation(pos.x - currHitbox->getDimensions().x, pos.y + currHitbox->getDimensions().y, pos.z - currHitbox->getDimensions().z);
		temp.push_back(temp2);
		temp2.SetToTranslation(pos.x + currHitbox->getDimensions().x, pos.y - currHitbox->getDimensions().y, pos.z + currHitbox->getDimensions().z);
		temp.push_back(temp2);
		temp2.SetToTranslation(pos.x + currHitbox->getDimensions().x, pos.y - currHitbox->getDimensions().y, pos.z - currHitbox->getDimensions().z);
		temp.push_back(temp2);
		temp2.SetToTranslation(pos.x - currHitbox->getDimensions().x, pos.y - currHitbox->getDimensions().y, pos.z + currHitbox->getDimensions().z);
		temp.push_back(temp2);
		temp2.SetToTranslation(pos.x - currHitbox->getDimensions().x, pos.y - currHitbox->getDimensions().y, pos.z - currHitbox->getDimensions().z);
		temp.push_back(temp2);

		for (int a = 0; a < temp.size(); a++) {

			temp2.SetToScale(Objects->getScale().x, Objects->getScale().y, Objects->getScale().z);
			temp[a] = temp[a] * temp2;
			if (Objects->getRotateDegrees() != 0.f) {
				temp2.SetToRotation(Objects->getRotateDegrees(), Objects->getRotate().x, Objects->getRotate().y, Objects->getRotate().z);
				temp[a] = temp[a] * temp2;
			}
			if (currHitbox->getDegrees() != 0.f) {
				temp2.SetToRotation(currHitbox->getDegrees(), currHitbox->getRotate().x, currHitbox->getRotate().y, currHitbox->getRotate().z);
				temp[a] = temp[a] * temp2;
			}
		}

		Objects->getHitboxLib()[i]->setVertices(temp);
	}

}

void Collisions::axisCalc(Object* Objects) {

	for (int i = 0; i < Objects->getHitboxLib().size(); i++) {
		Mtx44 axes[3];
		Mtx44 temp;
		axes[0].SetToTranslation(1, 0, 0);
		if (Objects->getRotateDegrees() != 0) {
			temp.SetToRotation(Objects->getRotateDegrees(), Objects->getRotate().x, Objects->getRotate().y, Objects->getRotate().z);
			axes[0] = axes[0] * temp;
		}
		if (Objects->getHitboxLib()[i]->getDegrees() != 0) {
			temp.SetToRotation(Objects->getHitboxLib()[i]->getDegrees(), Objects->getHitboxLib()[i]->getRotate().x, Objects->getHitboxLib()[i]->getRotate().y, Objects->getHitboxLib()[i]->getRotate().z);
			axes[0] = axes[0] * temp;
		}

		axes[1].SetToTranslation(0, 1, 0);
		if (Objects->getRotateDegrees() != 0) {
			temp.SetToRotation(Objects->getRotateDegrees(), Objects->getRotate().x, Objects->getRotate().y, Objects->getRotate().z);
			axes[1] = axes[1] * temp;
		}
		if (Objects->getHitboxLib()[i]->getDegrees() != 0) {
			temp.SetToRotation(Objects->getHitboxLib()[i]->getDegrees(), Objects->getHitboxLib()[i]->getRotate().x, Objects->getHitboxLib()[i]->getRotate().y, Objects->getHitboxLib()[i]->getRotate().z);
			axes[1] = axes[1] * temp;
		}

		axes[2].SetToTranslation(0, 0, 1);
		if (Objects->getRotateDegrees() != 0) {
			temp.SetToRotation(Objects->getRotateDegrees(), Objects->getRotate().x, Objects->getRotate().y, Objects->getRotate().z);
			axes[2] = axes[2] * temp;
		}
		if (Objects->getHitboxLib()[i]->getDegrees() != 0) {
			temp.SetToRotation(Objects->getHitboxLib()[i]->getDegrees(), Objects->getHitboxLib()[i]->getRotate().x, Objects->getHitboxLib()[i]->getRotate().y, Objects->getHitboxLib()[i]->getRotate().z);
			axes[2] = axes[2] * temp;
		}

		Objects->getHitboxLib()[i]->setAxes(axes);

	}
}

bool Collisions::colliCheck(Object* first, Object* second) {

	verticesCalc(first);
	axisCalc(first);
	verticesCalc(second);
	axisCalc(second);

	for (int i = 0; i < first->getHitboxLib().size(); i++) {
		Hitbox* firstHB = first->getHitboxLib()[i]; // 1st Hitbox

		for (int b = 0; b < second->getHitboxLib().size(); b++) {
			Hitbox* secondHB = second->getHitboxLib()[b]; // 2nd Hitbox

			int axisCollide = 6;

			for (int c = 0; c < 3; c++) { // Hitbox 1 axes
				Vector3 axis = Vector3(firstHB->getAxes(c).a[12], firstHB->getAxes(c).a[13], firstHB->getAxes(c).a[14]);
				float firstHBMin = 0;
				float firstHBMax = 0;
				float secondHBMin = 0;
				float secondHBMax = 0;
				int firstHBMinV = 0;
				int firstHBMaxV = 0;
				int secondHBMinV = 0;
				int secondHBMaxV = 0;
				// Hitbox 1 - MinMax
				for (int e = 0; e < firstHB->getVerticeLib().size(); e++) {
					Vector3 vertex = Vector3(firstHB->getVertices(e).a[12], firstHB->getVertices(e).a[13], firstHB->getVertices(e).a[14]);
					float temp = vertex.Dot(axis);
					if (e != 0) {
						if (temp > firstHBMax) {
							firstHBMax = temp;
							firstHBMaxV = e;
						}
						if (temp < firstHBMin) {
							firstHBMin = temp;
							firstHBMinV = e;
						}
					}
					else {
						firstHBMax = firstHBMin = temp;
						firstHBMinV = firstHBMaxV = e;
					}
				}
				// Hitbox 2 - MinMax
				for (int f = 0; f < secondHB->getVerticeLib().size(); f++) {
					Vector3 vertex = Vector3(secondHB->getVertices(f).a[12], secondHB->getVertices(f).a[13], secondHB->getVertices(f).a[14]);
					float temp = vertex.Dot(axis);
					if (f != 0) {
						if (temp > secondHBMax) {
							secondHBMax = temp;
							secondHBMaxV = f;
						}
						if (temp < secondHBMin) {
							secondHBMin = temp;
							secondHBMinV = f;
						}
					}
					else {
						secondHBMax = secondHBMin = temp;
						secondHBMinV = secondHBMaxV = f;
					}
				}

				if (secondHBMax < firstHBMin || firstHBMax < secondHBMin) { // Collision

					axisCollide--;
				}
			}

			for (int i = 0; i < 3; i++) { // Hitbox 2 axes
				Vector3 axis = Vector3(secondHB->getAxes(i).a[12], secondHB->getAxes(i).a[13], secondHB->getAxes(i).a[14]);
				float firstHBMin = 0;
				float firstHBMax = 0;
				float secondHBMin = 0;
				float secondHBMax = 0;
				// Hitbox 1 - MinMax
				for (int e = 0; e < firstHB->getVerticeLib().size(); e++) {
					Vector3 vertex = Vector3(firstHB->getVertices(e).a[12], firstHB->getVertices(e).a[13], firstHB->getVertices(e).a[14]);
					float temp = vertex.Dot(axis);
					if (e != 0) {
						if (temp > firstHBMax) {
							firstHBMax = temp;
						}
						if (temp < firstHBMin) {
							firstHBMin = temp;
						}
					}
					else {
						firstHBMax = firstHBMin = temp;
					}
				}
				// Hitbox 2 - MinMax
				for (int f = 0; f < secondHB->getVerticeLib().size(); f++) {
					Vector3 vertex = Vector3(secondHB->getVertices(f).a[12], secondHB->getVertices(f).a[13], secondHB->getVertices(f).a[14]);
					float temp = vertex.Dot(axis);
					if (f != 0) {
						if (temp > secondHBMax) {
							secondHBMax = temp;
						}
						if (temp < secondHBMin) {
							secondHBMin = temp;
						}
					}
					else {
						secondHBMax = secondHBMin = temp;
					}
				}
				if (secondHBMax < firstHBMin || firstHBMax < secondHBMin) { // Collision

					axisCollide--;
				}
			}

			if (axisCollide == 6) {
				return true;
			}
		}
	}
	return false;
}