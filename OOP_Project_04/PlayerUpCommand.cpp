#include "PlayerUpCommand.h"
#include "CUpdater.h"
#include "CPlayerUpdater.h"


PlayerUpCommand::PlayerUpCommand(CUpdater* updater)
{
	this->updater = updater;
}


PlayerUpCommand::~PlayerUpCommand()
{
}

void PlayerUpCommand::execute()
{
	((CPlayerUpdater*)updater)->pushUp();
}
