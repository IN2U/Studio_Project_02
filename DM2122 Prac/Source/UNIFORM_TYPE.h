#pragma once

enum UNIFORM_TYPE
{
	U_MVP = 0,
	U_MODELVIEW,
	U_MODELVIEW_INVERSE_TRANSPOSE,

	U_MATERIAL_AMBIENT,
	U_MATERIAL_DIFFUSE,
	U_MATERIAL_SPECULAR,
	U_MATERIAL_SHININESS,

	U_LIGHT0_POSITION,
	U_LIGHT0_COLOR,
	U_LIGHT0_POWER,
	U_LIGHT0_KC,
	U_LIGHT0_KL,
	U_LIGHT0_KQ,
	U_LIGHT0_TYPE,
	U_LIGHT0_SPOTDIRECTION,
	U_LIGHT0_COSCUTOFF,
	U_LIGHT0_COSINNER,
	U_LIGHT0_EXPONENT,

	// Sun
	U_LIGHT_SUN_POSITION,
	U_LIGHT_SUN_COLOR,
	U_LIGHT_SUN_POWER,
	U_LIGHT_SUN_KC,
	U_LIGHT_SUN_KL,
	U_LIGHT_SUN_KQ,
	U_LIGHT_SUN_TYPE,
	U_LIGHT_SUN_SPOTDIRECTION,
	U_LIGHT_SUN_COSCUTOFF,
	U_LIGHT_SUN_COSINNER,
	U_LIGHT_SUN_EXPONENT,

	// Spotlight
	U_SPOTLIGHT1_POSITION,
	U_SPOTLIGHT1_COLOR,
	U_SPOTLIGHT1_POWER,
	U_SPOTLIGHT1_KC,
	U_SPOTLIGHT1_KL,
	U_SPOTLIGHT1_KQ,
	U_SPOTLIGHT1_TYPE,
	U_SPOTLIGHT1_SPOTDIRECTION,
	U_SPOTLIGHT1_COSCUTOFF,
	U_SPOTLIGHT1_COSINNER,
	U_SPOTLIGHT1_EXPONENT,

	U_LIGHTENABLED,
	U_NUMLIGHTS,

	// add these enum for texture
	U_COLOR_TEXTURE_ENABLED,
	U_COLOR_TEXTURE,

	U_TEXT_ENABLED,
	U_TEXT_COLOR,

	U_TOTAL,
};