#include "race.h"
#include "raceCar.h"
#include "Application.h"

void SceneRace::carControls(double dt, raceCar* car) {
	if (Application::IsKeyPressed('W'))
	{
		Mtx44 force;
		force.SetToTranslation(0, 0, 150);
		Vector3 finalForce = Vector3(force.a[12], force.a[13], force.a[14]);
		Car->Accelerate(finalForce);
	}
	if (Application::IsKeyPressed('S'))
	{
		Mtx44 force;
		force.SetToTranslation(0, 0, -105);
		Vector3 finalForce = Vector3(force.a[12], force.a[13], force.a[14]);
		Car->Accelerate(finalForce);
	}
	if (Application::IsKeyPressed('A'))
	{
		Mtx44 temp = Car->getRotation();
		Mtx44 finalRotate;
		finalRotate.SetToRotation(5 * dt, 0, 1, 0);
		finalRotate = finalRotate * temp;
		Car->setRotation(finalRotate);
	}
	if (Application::IsKeyPressed('D'))
	{
		Mtx44 temp = Car->getRotation();
		Mtx44 finalRotate;
		finalRotate.SetToRotation(-5 * dt, 0, 1, 0);
		finalRotate = finalRotate * temp;
		Car->setRotation(finalRotate);
	}

}