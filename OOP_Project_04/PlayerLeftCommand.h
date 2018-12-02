#pragma once
#include "Command.h"

class CUpdater;

class PlayerLeftCommand : public Command
{
	CUpdater* updater;
public:
	PlayerLeftCommand(CUpdater* updater);
	~PlayerLeftCommand();

	virtual void execute();
};

