#include "PlayerDownCommand.h"
#include "CPlayerUpdater.h"

PlayerDownCommand::PlayerDownCommand(CUpdater* updater)
{
	this->updater = updater;
}


PlayerDownCommand::~PlayerDownCommand()
{
}

void PlayerDownCommand::execute()
{
	((CPlayerUpdater*)updater)->pushDown();
}
