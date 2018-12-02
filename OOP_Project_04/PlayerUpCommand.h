#pragma once
#include "Command.h"

class CUpdater;

class PlayerUpCommand : public Command
{
	CUpdater* updater;
public:
	PlayerUpCommand(CUpdater* updater);
	~PlayerUpCommand();

	virtual void execute();
};

