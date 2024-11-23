#include<iostream>
#include<allegro5/allegro5.h>
#include <allegro5/allegro.h>

#include "InputHandler.h"
#include "Command.h"

int main() {

	al_init();
	al_install_joystick();
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_joystick_event_source());

	HelloCommand* hello = new HelloCommand();
	QuestCommand* quest = new QuestCommand();
	FineCommand* fine = new FineCommand();
	ByeCommand* bye = new ByeCommand();

	InputHandler* handler = new InputHandler();
	handler->config_A(hello);
	handler->config_B(bye);
	handler->config_X(quest);
	handler->config_Y(fine);

	while (true) {
        ALLEGRO_EVENT event;
		if (al_get_next_event(event_queue, &event)) {
			if (event.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN) {
				Command* command = handler->handle_input(event.joystick.button);
				if (command) command->excecute();
			}
		}
	}

	al_destroy_event_queue(event_queue);
	al_uninstall_joystick();

	return 0;
}