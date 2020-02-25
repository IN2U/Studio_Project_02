#pragma once

class Button
{
private:
	double MenuMinPosX;
	double MenuMaxPosX;
	double MenuMinPosY[3];
	double MenuMaxPosY[3];

	double OptionsMinPosX;
	double OptionsMaxPosX;
	double OptionsMinPosY[3];
	double OptionsMaxPosY[3];

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

	double getOptionsMinPosX() const;
	double getOptionsMaxPosX() const;

	double getOptionsControlsMinPosY() const;
	double getOptionsControlsMaxPosY() const;

	double getOptionsAudioMinPosY() const;
	double getOptionsAudioMaxPosY() const;

	double getOptionsBackMinPosY() const;
	double getOptionsBackMaxPosY() const;

	void updateButtonPos();

	static Button* getInstance();
};