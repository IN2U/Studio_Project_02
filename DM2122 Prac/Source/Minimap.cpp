#include "Minimap.h"

Minimap::Minimap()
{
}

Minimap::~Minimap()
{
}

void Minimap::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = pos;
	this->target = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 10;
	right.Normalize();
	this->up = right.Cross(view).Normalized();
}

void Minimap::Update(double dt)
{

}