#pragma once
#include "Command.h"

class CPlayerUpdater;

class PlayerDownCommand : public Command
{
	CPlayerUpdater* updater;
public:
	PlayerDownCommand(CPlayerUpdater* updater);
	~PlayerDownCommand();

	virtual void execute();
};

