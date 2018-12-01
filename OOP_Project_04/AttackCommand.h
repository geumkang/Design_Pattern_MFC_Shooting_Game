#pragma once
#include "Command.h"

class CPlayerUpdater;

class AttackCommand :
	public Command
{
	CPlayerUpdater* updater;
public:
	AttackCommand(CPlayerUpdater* updater);
	~AttackCommand();

	virtual void execute();
};

