#pragma once
#include "Command.h"

class CUpdater;

class PlayerRightCommand : public Command
{
	CUpdater* updater;
public:
	PlayerRightCommand(CUpdater* updater);
	~PlayerRightCommand();

	virtual void execute();
};

