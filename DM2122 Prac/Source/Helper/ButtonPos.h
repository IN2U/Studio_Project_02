#pragma once

class Button
{
private:
	// Buttons position
	double ButtonMinPosX;
	double ButtonMaxPosX;
	double ButtonMinPosY[4];
	double ButtonMaxPosY[4];

	static Button* instance;

	Button();
public:
	~Button();

	double getButtonMinPosX() const;
	double getButtonMaxPosX() const;

	double getButton1MinPosY() const;
	double getButton1MaxPosY() const;
						 
	double getButton2MinPosY() const;
	double getButton2MaxPosY() const;
						 
	double getButton3MinPosY() const;
	double getButton3MaxPosY() const;

	double getButton4MinPosY() const;
	double getButton4MaxPosY() const;

	void updateButtonPos();

	static Button* getInstance();
};