#ifndef INPUT_H
#define INPUT_H

#include <iostream>

struct InputState
{
	bool W{ false };
	bool A{ false };
	bool S{ false };
	bool D{ false };
	bool Space{ false };
};

class Input
{
public:
	Input();
	~Input();

	InputState m_current;
	InputState m_previous;

	void update();
};
#endif