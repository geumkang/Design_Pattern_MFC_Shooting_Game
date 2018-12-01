#pragma once
#include "Command.h"

class CPlayerUpdater;

class PlayerLeftCommand : public Command
{
	CPlayerUpdater* updater;
public:
	PlayerLeftCommand(CPlayerUpdater* updater);
	~PlayerLeftCommand();

	virtual void execute();
};

