#include "SceneText.h"
#include "../../glew/include/GL/glew.h"

void SceneText::InitLightSettings()
{
	light[0].type = Light::LIGHT_SPOT;
	light[0].position.Set(0.f, -15.f, -30.f);
	light[0].color.Set(0.5f, 0.5f, 0.5f);
	light[0].power = 10;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 3.f;
	light[0].spotDirection.Set(0.f, -1.f, 1.f);

	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &light[0].spotDirection.x);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

	light[1].type = Light::LIGHT_DIRECTIONAL;
	light[1].position.Set(0.f, 0.f, 0.f);
	light[1].color.Set(1.f, 1.f, 1.f);
	light[1].power = 0;
	light[1].kC = 1.f;
	light[1].kL = 0.01f;
	light[1].kQ = 0.001f;
	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
	light[1].cosInner = cos(Math::DegreeToRadian(30));
	light[1].exponent = 3.f;
	light[1].spotDirection.Set(0.f, 1.f, 0.f);

	glUniform1i(m_parameters[U_LIGHT_SUN_TYPE], light[1].type);
	glUniform3fv(m_parameters[U_LIGHT_SUN_COLOR], 1, &light[1].color.r);
	glUniform1f(m_parameters[U_LIGHT_SUN_POWER], light[1].power);
	glUniform1f(m_parameters[U_LIGHT_SUN_KC], light[1].kC);
	glUniform1f(m_parameters[U_LIGHT_SUN_KL], light[1].kL);
	glUniform1f(m_parameters[U_LIGHT_SUN_KQ], light[1].kQ);
	glUniform3fv(m_parameters[U_LIGHT_SUN_SPOTDIRECTION], 1, &light[1].spotDirection.x);
	glUniform1f(m_parameters[U_LIGHT_SUN_COSCUTOFF], light[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT_SUN_COSINNER], light[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT_SUN_EXPONENT], light[1].exponent);

	for (int i = 2; i < 10; ++i)
	{
		light[i].type = Light::LIGHT_SPOT;
		light[i].position.Set(0.f, 0.f, 0.f);
		light[i].color.Set(1.f, 1.f, 1.f);
		light[i].power = 0.f;
		light[i].kC = 1.f;
		light[i].kL = 0.01f;
		light[i].kQ = 0.001f;
		light[i].cosCutoff = cos(Math::DegreeToRadian(45));
		light[i].cosInner = cos(Math::DegreeToRadian(30));
		light[i].exponent = 3.f;

		if (i % 2 == 0)
		{
			light[i].spotDirection.Set(0.1f, 1.f, 0.f);
		}
		else
		{
			light[i].spotDirection.Set(-0.1f, 1.f, 0.f);
		}
	}

	// Car1
	glUniform1i(m_parameters[U_CAR1_SPOTLIGHT1_TYPE], light[2].type);
	glUniform3fv(m_parameters[U_CAR1_SPOTLIGHT1_COLOR], 1, &light[2].color.r);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_POWER], light[2].power);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_KC], light[2].kC);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_KL], light[2].kL);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_KQ], light[2].kQ);
	glUniform3fv(m_parameters[U_CAR1_SPOTLIGHT1_SPOTDIRECTION], 1, &light[2].spotDirection.x);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_COSCUTOFF], light[2].cosCutoff);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_COSINNER], light[2].cosInner);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT1_EXPONENT], light[2].exponent);

	glUniform1i(m_parameters[U_CAR1_SPOTLIGHT2_TYPE], light[3].type);
	glUniform3fv(m_parameters[U_CAR1_SPOTLIGHT2_COLOR], 1, &light[3].color.r);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_POWER], light[3].power);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_KC], light[3].kC);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_KL], light[3].kL);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_KQ], light[3].kQ);
	glUniform3fv(m_parameters[U_CAR1_SPOTLIGHT2_SPOTDIRECTION], 1, &light[3].spotDirection.x);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_COSCUTOFF], light[3].cosCutoff);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_COSINNER], light[3].cosInner);
	glUniform1f(m_parameters[U_CAR1_SPOTLIGHT2_EXPONENT], light[3].exponent);
	// ~Car1

	// Car2
	glUniform1i(m_parameters[U_CAR2_SPOTLIGHT1_TYPE], light[4].type);
	glUniform3fv(m_parameters[U_CAR2_SPOTLIGHT1_COLOR], 1, &light[4].color.r);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_POWER], light[4].power);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_KC], light[4].kC);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_KL], light[4].kL);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_KQ], light[4].kQ);
	glUniform3fv(m_parameters[U_CAR2_SPOTLIGHT1_SPOTDIRECTION], 1, &light[4].spotDirection.x);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_COSCUTOFF], light[4].cosCutoff);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_COSINNER], light[4].cosInner);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT1_EXPONENT], light[4].exponent);

	glUniform1i(m_parameters[U_CAR2_SPOTLIGHT2_TYPE], light[5].type);
	glUniform3fv(m_parameters[U_CAR2_SPOTLIGHT2_COLOR], 1, &light[5].color.r);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_POWER], light[5].power);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_KC], light[5].kC);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_KL], light[5].kL);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_KQ], light[5].kQ);
	glUniform3fv(m_parameters[U_CAR2_SPOTLIGHT2_SPOTDIRECTION], 1, &light[5].spotDirection.x);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_COSCUTOFF], light[5].cosCutoff);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_COSINNER], light[5].cosInner);
	glUniform1f(m_parameters[U_CAR2_SPOTLIGHT2_EXPONENT], light[5].exponent);
	// ~Car2

	// Car3
	glUniform1i(m_parameters[U_CAR3_SPOTLIGHT1_TYPE], light[6].type);
	glUniform3fv(m_parameters[U_CAR3_SPOTLIGHT1_COLOR], 1, &light[6].color.r);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_POWER], light[6].power);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_KC], light[6].kC);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_KL], light[6].kL);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_KQ], light[6].kQ);
	glUniform3fv(m_parameters[U_CAR3_SPOTLIGHT1_SPOTDIRECTION], 1, &light[6].spotDirection.x);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_COSCUTOFF], light[6].cosCutoff);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_COSINNER], light[6].cosInner);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT1_EXPONENT], light[6].exponent);

	glUniform1i(m_parameters[U_CAR3_SPOTLIGHT2_TYPE], light[7].type);
	glUniform3fv(m_parameters[U_CAR3_SPOTLIGHT2_COLOR], 1, &light[7].color.r);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_POWER], light[7].power);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_KC], light[7].kC);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_KL], light[7].kL);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_KQ], light[7].kQ);
	glUniform3fv(m_parameters[U_CAR3_SPOTLIGHT2_SPOTDIRECTION], 1, &light[7].spotDirection.x);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_COSCUTOFF], light[7].cosCutoff);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_COSINNER], light[7].cosInner);
	glUniform1f(m_parameters[U_CAR3_SPOTLIGHT2_EXPONENT], light[7].exponent);
	// ~Car3

	// Car4
	glUniform1i(m_parameters[U_CAR4_SPOTLIGHT1_TYPE], light[8].type);
	glUniform3fv(m_parameters[U_CAR4_SPOTLIGHT1_COLOR], 1, &light[8].color.r);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_POWER], light[8].power);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_KC], light[8].kC);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_KL], light[8].kL);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_KQ], light[8].kQ);
	glUniform3fv(m_parameters[U_CAR4_SPOTLIGHT1_SPOTDIRECTION], 1, &light[8].spotDirection.x);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_COSCUTOFF], light[8].cosCutoff);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_COSINNER], light[8].cosInner);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT1_EXPONENT], light[8].exponent);

	glUniform1i(m_parameters[U_CAR4_SPOTLIGHT2_TYPE], light[9].type);
	glUniform3fv(m_parameters[U_CAR4_SPOTLIGHT2_COLOR], 1, &light[9].color.r);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_POWER], light[9].power);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_KC], light[9].kC);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_KL], light[9].kL);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_KQ], light[9].kQ);
	glUniform3fv(m_parameters[U_CAR4_SPOTLIGHT2_SPOTDIRECTION], 1, &light[9].spotDirection.x);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_COSCUTOFF], light[9].cosCutoff);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_COSINNER], light[9].cosInner);
	glUniform1f(m_parameters[U_CAR4_SPOTLIGHT2_EXPONENT], light[9].exponent);
	// ~Car4

	// Setting this to > 8 breaks scene
	glUniform1i(m_parameters[U_NUMLIGHTS], 8);
}