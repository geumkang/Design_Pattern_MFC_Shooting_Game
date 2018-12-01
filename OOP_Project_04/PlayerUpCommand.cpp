#include "PlayerUpCommand.h"
#include "CPlayerUpdater.h"


PlayerUpCommand::PlayerUpCommand(CPlayerUpdater* updater)
{
	this->updater = updater;
}


PlayerUpCommand::~PlayerUpCommand()
{
}

void PlayerUpCommand::execute()
{
	updater->pushUp();
}
