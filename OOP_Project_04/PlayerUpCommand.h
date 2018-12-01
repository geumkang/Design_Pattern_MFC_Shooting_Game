#pragma once
#include "Command.h"

class CPlayerUpdater;

class PlayerUpCommand : public Command
{
	CPlayerUpdater* updater;
public:
	PlayerUpCommand(CPlayerUpdater* updater);
	~PlayerUpCommand();

	virtual void execute();
};

