#include "Sun.h"
#include "SceneText.h" // For sin / cos

Sun::Sun()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	angle = 0.f;
	intensity = 0.f;
}

Sun::~Sun()
{
}

float Sun::getX() const
{
	return x;
}

float Sun::getY() const
{
	return y;
}

float Sun::getZ() const
{
	return z;
}

float Sun::getAngle() const
{
	return angle;
}

float Sun::getIntensity() const
{
	return intensity;
}

void Sun::revolve(double dt)
{
	// When revolution is not complete
	if (angle < 360)
	{
		angle += float(dt);

		if (angle < 70)
		{
			intensity += float(dt / 40000);
		}
		// Prevents intensity from increasing at noon
		else if (angle > 70 && angle < 110)
		{
			intensity = 0.f;
		}
		else if (angle > 110 && angle < 180)
		{
			intensity += float(dt / 40000);
		}
		// Set intensity to 0 at night
		else
		{
			intensity = 0.f;
		}
	}
	// When one revolution is completed
	else
	{
		angle = 0;
	}

	//pi / 180
	x = 50 * float(cos(angle * 0.01745329251));
	y = 50 * float(sin(angle * 0.01745329251));
}