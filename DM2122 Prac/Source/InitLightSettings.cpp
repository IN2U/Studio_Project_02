#include "SceneText.h"
#include "../../glew/include/GL/glew.h"

void SceneText::InitLightSettings()
{
	light[0].type = Light::LIGHT_POINT;
	light[0].position.Set(0, -50, 0);
	light[0].color.Set(0.5f, 0.5f, 0.5f);
	light[0].power = 10;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 3.f;
	light[0].spotDirection.Set(0.f, 1.f, 0.f);

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
	light[1].position.Set(sun.getX(), sun.getY(), sun.getZ());
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

	light[2].type = Light::LIGHT_SPOT;
	light[2].position.Set(5.25f, 0.5f, -15.f);
	light[2].color.Set(1.f, 1.f, 1.f);
	light[2].power = 0.f;
	light[2].kC = 1.f;
	light[2].kL = 0.01f;
	light[2].kQ = 0.001f;
	light[2].cosCutoff = cos(Math::DegreeToRadian(45));
	light[2].cosInner = cos(Math::DegreeToRadian(30));
	light[2].exponent = 3.f;
	light[2].spotDirection.Set(-1.f, -1.f, 0.f);

	glUniform1i(m_parameters[U_SPOTLIGHT1_TYPE], light[2].type);
	glUniform3fv(m_parameters[U_SPOTLIGHT1_COLOR], 1, &light[2].color.r);
	glUniform1f(m_parameters[U_SPOTLIGHT1_POWER], light[2].power);
	glUniform1f(m_parameters[U_SPOTLIGHT1_KC], light[2].kC);
	glUniform1f(m_parameters[U_SPOTLIGHT1_KL], light[2].kL);
	glUniform1f(m_parameters[U_SPOTLIGHT1_KQ], light[2].kQ);
	glUniform3fv(m_parameters[U_SPOTLIGHT1_SPOTDIRECTION], 1, &light[2].spotDirection.x);
	glUniform1f(m_parameters[U_SPOTLIGHT1_COSCUTOFF], light[2].cosCutoff);
	glUniform1f(m_parameters[U_SPOTLIGHT1_COSINNER], light[2].cosInner);
	glUniform1f(m_parameters[U_SPOTLIGHT1_EXPONENT], light[2].exponent);

	glUniform1i(m_parameters[U_NUMLIGHTS], 3);
}