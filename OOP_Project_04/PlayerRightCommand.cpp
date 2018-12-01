#include "PlayerRightCommand.h"
#include "CPlayerUpdater.h"


PlayerRightCommand::PlayerRightCommand(CPlayerUpdater* updater)
{
	this->updater = updater;
}


PlayerRightCommand::~PlayerRightCommand()
{
}

void PlayerRightCommand::execute() {
	updater->pushRight();
}
