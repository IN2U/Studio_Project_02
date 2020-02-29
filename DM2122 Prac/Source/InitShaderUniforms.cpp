#include "Scene.h"
#include "SceneMenu.h"
#include "SceneText.h"
#include "../../glew/include/GL/glew.h"

void Scene::InitShaderUniforms()
{
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");

	//Get a handle for our "colorTexture" uniform
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");
	// Get a handle for our "textColor" uniform
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");
}

void SceneText::InitLightShaderUniforms()
{
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");

	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");

	// Building light
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

	// Sun
	m_parameters[U_LIGHT_SUN_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT_SUN_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT_SUN_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT_SUN_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT_SUN_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT_SUN_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	m_parameters[U_LIGHT_SUN_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT_SUN_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT_SUN_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT_SUN_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT_SUN_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	// Car1
	m_parameters[U_CAR1_SPOTLIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
	m_parameters[U_CAR1_SPOTLIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
	m_parameters[U_CAR1_SPOTLIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
	m_parameters[U_CAR1_SPOTLIGHT1_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
	m_parameters[U_CAR1_SPOTLIGHT1_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
	m_parameters[U_CAR1_SPOTLIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
	m_parameters[U_CAR1_SPOTLIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
	m_parameters[U_CAR1_SPOTLIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
	m_parameters[U_CAR1_SPOTLIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
	m_parameters[U_CAR1_SPOTLIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
	m_parameters[U_CAR1_SPOTLIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");
	
	m_parameters[U_CAR1_SPOTLIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[3].position_cameraspace");
	m_parameters[U_CAR1_SPOTLIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[3].color");
	m_parameters[U_CAR1_SPOTLIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[3].power");
	m_parameters[U_CAR1_SPOTLIGHT2_KC] = glGetUniformLocation(m_programID, "lights[3].kC");
	m_parameters[U_CAR1_SPOTLIGHT2_KL] = glGetUniformLocation(m_programID, "lights[3].kL");
	m_parameters[U_CAR1_SPOTLIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[3].kQ");
	m_parameters[U_CAR1_SPOTLIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[3].type");
	m_parameters[U_CAR1_SPOTLIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[3].spotDirection");
	m_parameters[U_CAR1_SPOTLIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[3].cosCutoff");
	m_parameters[U_CAR1_SPOTLIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[3].cosInner");
	m_parameters[U_CAR1_SPOTLIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[3].exponent");
	// ~Car1

	// Car2
	m_parameters[U_CAR2_SPOTLIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[4].position_cameraspace");
	m_parameters[U_CAR2_SPOTLIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[4].color");
	m_parameters[U_CAR2_SPOTLIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[4].power");
	m_parameters[U_CAR2_SPOTLIGHT1_KC] = glGetUniformLocation(m_programID, "lights[4].kC");
	m_parameters[U_CAR2_SPOTLIGHT1_KL] = glGetUniformLocation(m_programID, "lights[4].kL");
	m_parameters[U_CAR2_SPOTLIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[4].kQ");
	m_parameters[U_CAR2_SPOTLIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[4].type");
	m_parameters[U_CAR2_SPOTLIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[4].spotDirection");
	m_parameters[U_CAR2_SPOTLIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[4].cosCutoff");
	m_parameters[U_CAR2_SPOTLIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[4].cosInner");
	m_parameters[U_CAR2_SPOTLIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[4].exponent");

	m_parameters[U_CAR2_SPOTLIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[5].position_cameraspace");
	m_parameters[U_CAR2_SPOTLIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[5].color");
	m_parameters[U_CAR2_SPOTLIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[5].power");
	m_parameters[U_CAR2_SPOTLIGHT2_KC] = glGetUniformLocation(m_programID, "lights[5].kC");
	m_parameters[U_CAR2_SPOTLIGHT2_KL] = glGetUniformLocation(m_programID, "lights[5].kL");
	m_parameters[U_CAR2_SPOTLIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[5].kQ");
	m_parameters[U_CAR2_SPOTLIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[5].type");
	m_parameters[U_CAR2_SPOTLIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[5].spotDirection");
	m_parameters[U_CAR2_SPOTLIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[5].cosCutoff");
	m_parameters[U_CAR2_SPOTLIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[5].cosInner");
	m_parameters[U_CAR2_SPOTLIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[5].exponent");
	// ~Car2

	// Car3
	m_parameters[U_CAR3_SPOTLIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[6].position_cameraspace");
	m_parameters[U_CAR3_SPOTLIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[6].color");
	m_parameters[U_CAR3_SPOTLIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[6].power");
	m_parameters[U_CAR3_SPOTLIGHT1_KC] = glGetUniformLocation(m_programID, "lights[6].kC");
	m_parameters[U_CAR3_SPOTLIGHT1_KL] = glGetUniformLocation(m_programID, "lights[6].kL");
	m_parameters[U_CAR3_SPOTLIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[6].kQ");
	m_parameters[U_CAR3_SPOTLIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[6].type");
	m_parameters[U_CAR3_SPOTLIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[6].spotDirection");
	m_parameters[U_CAR3_SPOTLIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[6].cosCutoff");
	m_parameters[U_CAR3_SPOTLIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[6].cosInner");
	m_parameters[U_CAR3_SPOTLIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[6].exponent");

	m_parameters[U_CAR3_SPOTLIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[7].position_cameraspace");
	m_parameters[U_CAR3_SPOTLIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[7].color");
	m_parameters[U_CAR3_SPOTLIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[7].power");
	m_parameters[U_CAR3_SPOTLIGHT2_KC] = glGetUniformLocation(m_programID, "lights[7].kC");
	m_parameters[U_CAR3_SPOTLIGHT2_KL] = glGetUniformLocation(m_programID, "lights[7].kL");
	m_parameters[U_CAR3_SPOTLIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[7].kQ");
	m_parameters[U_CAR3_SPOTLIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[7].type");
	m_parameters[U_CAR3_SPOTLIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[7].spotDirection");
	m_parameters[U_CAR3_SPOTLIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[7].cosCutoff");
	m_parameters[U_CAR3_SPOTLIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[7].cosInner");
	m_parameters[U_CAR3_SPOTLIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[7].exponent");
	// ~Car3

	// Car4
	m_parameters[U_CAR4_SPOTLIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[8].position_cameraspace");
	m_parameters[U_CAR4_SPOTLIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[8].color");
	m_parameters[U_CAR4_SPOTLIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[8].power");
	m_parameters[U_CAR4_SPOTLIGHT1_KC] = glGetUniformLocation(m_programID, "lights[8].kC");
	m_parameters[U_CAR4_SPOTLIGHT1_KL] = glGetUniformLocation(m_programID, "lights[8].kL");
	m_parameters[U_CAR4_SPOTLIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[8].kQ");
	m_parameters[U_CAR4_SPOTLIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[8].type");
	m_parameters[U_CAR4_SPOTLIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[8].spotDirection");
	m_parameters[U_CAR4_SPOTLIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[8].cosCutoff");
	m_parameters[U_CAR4_SPOTLIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[8].cosInner");
	m_parameters[U_CAR4_SPOTLIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[8].exponent");

	m_parameters[U_CAR4_SPOTLIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[9].position_cameraspace");
	m_parameters[U_CAR4_SPOTLIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[9].color");
	m_parameters[U_CAR4_SPOTLIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[9].power");
	m_parameters[U_CAR4_SPOTLIGHT2_KC] = glGetUniformLocation(m_programID, "lights[9].kC");
	m_parameters[U_CAR4_SPOTLIGHT2_KL] = glGetUniformLocation(m_programID, "lights[9].kL");
	m_parameters[U_CAR4_SPOTLIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[9].kQ");
	m_parameters[U_CAR4_SPOTLIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[9].type");
	m_parameters[U_CAR4_SPOTLIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[9].spotDirection");
	m_parameters[U_CAR4_SPOTLIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[9].cosCutoff");
	m_parameters[U_CAR4_SPOTLIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[9].cosInner");
	m_parameters[U_CAR4_SPOTLIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[9].exponent");
	// ~Car4

	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
}
