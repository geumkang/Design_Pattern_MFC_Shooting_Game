#pragma once
#include "Command.h"

class CUpdater;

class PlayerDownCommand : public Command
{
	CUpdater* updater;
public:
	PlayerDownCommand(CUpdater* updater);
	~PlayerDownCommand();

	virtual void execute();
};

