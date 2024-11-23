#include<unordered_map>

#include "InputHandler.h"
#include "JoyButtons.h"

Command* InputHandler::handle_input(int input) {
	if (swapping){
		Swap(input);
		return NULL;
	}

	if (input == BUTTON_A) return _A;
	else if (input == BUTTON_B) return _B;
	else if (input == BUTTON_X) return _X;
	else if (input == BUTTON_Y) return _Y;
	if (input == BUTTON_SELECT) Swap();

	return NULL;
}

void InputHandler::Swap(int input) {
	if (input == -1) {
		std::cout << "Swapping ";
		swapping = true;
		return;
	}

	if (temp != -1) {
		std::cout << input << std::endl;

		std::unordered_map<int, Command**> button_map = {
			{ BUTTON_A, &_A },
			{ BUTTON_B, &_B },
			{ BUTTON_X, &_X },
			{ BUTTON_Y, &_Y }
		};

		const std::unordered_map<int, Command**>::iterator exist = button_map.find(input);
		if (exist == button_map.end()) {
			temp = -1;
			swapping = false;

			return;
		}


		std::swap(*button_map[temp], *button_map[input]);

		temp = -1;
		swapping = false;

		return;
	}

	std::cout << input << " to ";

	temp = input;
}