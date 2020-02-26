#ifndef SCENEVENDING_H
#define SCENEVENDING_H

#include "Scene.h"
#include "Vending.h"

#include "Currency.h"
#include "Inventory.h"

class SceneVending : public Scene
{
private:
	enum GEOMETRY_TYPE
	{
		GEO_VENDING,
		VENDING_TEXT,
		NUM_GEOMETRY,
	}; 

	string itemChosen;
	string itemIssued;

	bool goingToBuyItem;
	bool itemBought;

	int buttonTrigger;
	double gameTime;
	double bounceTime;
	bool somethingHappened;

	Vending vending;

	Mesh* meshList[NUM_GEOMETRY];

	virtual void InitMeshList() override;

	void checkInput();

public:
	SceneVending();
	~SceneVending();

	virtual void Init() override;
	virtual void Update(double dt) override;
	virtual void Render() override;
	virtual void Exit() override;
};

#endif
