#pragma once
#include "Command.h"

#ifndef _INPUTHANDLER_
#define _INPUTHANDLER_

class InputHandler {
private:
	Command* _A;
	Command* _B;
	Command* _X;
	Command* _Y;

	int temp;

	bool swapping;
public:
	InputHandler() :
		_A(nullptr), _B(nullptr), _X(nullptr), _Y(nullptr), swapping(false), temp(-1) {
	}

	Command* handle_input(int input);

	void config_A(Command* A) { _A = A; }
	void config_B(Command* B) { _B = B; }
	void config_X(Command* X) { _X = X; }
	void config_Y(Command* Y) { _Y = Y; }

	void Swap(int input = -1);
};

#endif // !_INPUTHANDLER_
