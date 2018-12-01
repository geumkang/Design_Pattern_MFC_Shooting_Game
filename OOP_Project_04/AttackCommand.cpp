#include "AttackCommand.h"
#include "CPlayerUpdater.h"


AttackCommand::AttackCommand(CPlayerUpdater* updater)
{
	this->updater = updater;
}


AttackCommand::~AttackCommand()
{
}

void AttackCommand::execute()
{
}
