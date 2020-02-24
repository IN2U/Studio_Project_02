#pragma once

#include "Vector3.h"

class Minimap
{
public:
	Vector3 position;
	Vector3 target;
	Vector3 up;

	Minimap();
	~Minimap();
	
	void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	void Update(double dt);
	void Reset();
};