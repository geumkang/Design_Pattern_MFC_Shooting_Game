#include "PlayerRightCommand.h"
#include "CPlayerUpdater.h"


PlayerRightCommand::PlayerRightCommand(CUpdater* updater)
{
	this->updater = updater;
}


PlayerRightCommand::~PlayerRightCommand()
{
}

void PlayerRightCommand::execute() {
	((CPlayerUpdater*)updater)->pushRight();
}
