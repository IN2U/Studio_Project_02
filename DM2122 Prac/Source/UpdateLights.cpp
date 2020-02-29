#include "SceneText.h"
#include "GL/glew.h"

void SceneText::RevolveSun(double dt)
{
	// When revolution is not complete
	if (sunAngle < 360)
	{
		sunAngle += float(dt);

		if (sunAngle < 70)
		{
			light[1].power += float(dt / 30);
			glUniform1f(m_parameters[U_LIGHT_SUN_POWER], light[1].power);
		}
		// Prevents intensity from increasing at noon
		else if (sunAngle > 70 && sunAngle < 110)
		{

		}
		else if (sunAngle > 110 && sunAngle < 180)
		{
			light[1].power -= float(dt / 30);
			glUniform1f(m_parameters[U_LIGHT_SUN_POWER], light[1].power);
		}
		// Set intensity to 0 at night
		else
		{
			light[1].power = 0;
			glUniform1f(m_parameters[U_LIGHT_SUN_POWER], light[1].power);
		}
	}
	// When one revolution is completed
	else
	{
		sunAngle = 0;
	}

	// Updates sunlight pos
	light[1].position.Set(50 * float(cos(sunAngle * 0.01745329251)), 50 * float(sin(sunAngle * 0.01745329251)), 0.f);
}

void SceneText::UpdateSpotlights(double dt)
{
	// Night, start increasing brightness of spotlight until 1.f
	if (sunAngle > 160)
	{
		for (int i = 2; i < 10; ++i)
		{
			if (light[i].power < 1.f)
			{
				light[i].power += float(dt / 30);
			}
			//light[i].power = 1.f;
		}
		glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_POWER], light[2].power);
		glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_POWER], light[3].power);
		glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_POWER], light[4].power);
		glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_POWER], light[5].power);
		glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_POWER], light[6].power);
		glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_POWER], light[7].power);
		glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_POWER], light[8].power);
		glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_POWER], light[9].power);
	}
	// Morning, start decreasing brightness of spotlight until 0.f
	else if (sunAngle < 20.f)
	{
		for (int i = 2; i < 10; ++i)
		{
			if (light[i].power > 0.f)
			{
				light[i].power -= float(dt / 20);
			}
			else
			{
				light[i].power = 0.f;
			}
		}
		glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_POWER], light[2].power);
		glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_POWER], light[3].power);
		glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_POWER], light[4].power);
		glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_POWER], light[5].power);
		glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_POWER], light[6].power);
		glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_POWER], light[7].power);
		glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_POWER], light[8].power);
		glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_POWER], light[9].power);
	}

	spotlightAngle += 100 * float(dt);

	// Car1 spotlight
	light[2].position.Set(Car1X + dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));
	light[3].position.Set(Car1X - dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));

	// Car2 spotlight
	light[4].position.Set(Car2X + dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));
	light[5].position.Set(Car2X - dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));

	// Car3 spotlight
	light[6].position.Set(Car3X + dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));
	light[7].position.Set(Car3X - dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));

	// Car4 spotlight
	light[8].position.Set(Car4X + dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ + dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));
	light[9].position.Set(Car4X - dFromCarCentre * float(cos(spotlightAngle * 0.01745329251)), 10, CarZ - dFromCarCentre * float(sin(spotlightAngle * 0.01745329251)));
}