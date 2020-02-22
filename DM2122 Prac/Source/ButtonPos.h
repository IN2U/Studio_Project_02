#pragma once

class Button
{
private:
	double MenuMinPosX;
	double MenuMaxPosX;
	double MenuMinPosY[3];
	double MenuMaxPosY[3];

	Button();

	static Button* instance;
public:
	~Button();

	double getMenuMinPosX() const;
	double getMenuMaxPosX() const;

	double getMenuPlayMinPosY() const;
	double getMenuPlayMaxPosY() const;

	double getMenuOptionsMinPosY() const;
	double getMenuOptionsMaxPosY() const;

	double getMenuQuitMinPosY() const;
	double getMenuQuitMaxPosY() const;

	void updateButtonPos();

	static Button* getInstance();
};