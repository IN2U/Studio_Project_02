#pragma once

class Sun
{
private:
	float x;
	float y;
	float z;
	float angle;
	float intensity;
public:
	Sun();
	~Sun();

	float getX() const;
	float getY() const;
	float getZ() const;
	float getAngle() const;
	float getIntensity() const;

	void revolve(double dt);
};