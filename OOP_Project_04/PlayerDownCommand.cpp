#include "PlayerDownCommand.h"
#include "CPlayerUpdater.h"

PlayerDownCommand::PlayerDownCommand(CPlayerUpdater* updater)
{
	this->updater = updater;
}


PlayerDownCommand::~PlayerDownCommand()
{
}

void PlayerDownCommand::execute()
{
	updater->pushDown();
}
