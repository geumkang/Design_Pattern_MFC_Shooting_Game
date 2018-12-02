#pragma once
#include "Command.h"

class CUpdater;

class PlayerAttackCommand : public Command
{
	CUpdater* updater;
public:
	PlayerAttackCommand(CUpdater* updater);
	~PlayerAttackCommand();

	void execute();
};

