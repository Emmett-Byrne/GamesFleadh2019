#pragma once

enum Menu
{
	StateSplash,
	StateLicense,
	StateMainMenu,
	StateOptions,
	StateGame,
	StateCredits,
	StateQuit
};

struct Options
{
	int musicVol;
	int soundVol;
	bool mute;
	int animSpeed;
	int fontSize;
};