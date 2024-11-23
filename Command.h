#pragma once
#include<iostream>

#ifndef _COMMAND_
#define _COMMAND_

class Command {
public:
	virtual ~Command() {}
	virtual void excecute() = 0;
};

class HelloCommand: public Command {
public:
	virtual void excecute() { std::cout << "Hello!" << std::endl; }
};

class QuestCommand : public Command {
public:
	virtual void excecute() { std::cout << "How are you?" << std::endl; }
};

class ByeCommand : public Command {
public:
	virtual void excecute() { std::cout << "Good bye!" << std::endl; }
};

class FineCommand : public Command {
public:
	virtual void excecute() { std::cout << "I'm fine!" << std::endl; }
};

#endif // !_COMMAND_
