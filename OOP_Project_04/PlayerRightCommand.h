#pragma once
#include "Command.h"

class CPlayerUpdater;

class PlayerRightCommand : public Command
{
	CPlayerUpdater* updater;
public:
	PlayerRightCommand(CPlayerUpdater* updater);
	~PlayerRightCommand();

	virtual void execute();
};

