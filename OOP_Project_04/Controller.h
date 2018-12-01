#pragma once
#include "Command.h"

class Controller
{
public:

	Command* upCommand;
	Command* downCommand;
	Command* leftCommand;
	Command* rightCommand;
	Command* attackCommand;
	Command* specialCommand;

	Controller();
	~Controller();

	void doAttack();
	void doSpecial();
	void doLeft();
	void doRight();
	void doUp();
	void doDown();

	void setUpCommand(Command* command);
	void setDownCommand(Command* command);
	void setLeftCommand(Command* command);
	void setRightCommand(Command* command);
	void setAttackCommand(Command* command);
	void setSpecialCommand(Command* command);
};

