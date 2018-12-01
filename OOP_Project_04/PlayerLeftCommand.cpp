#include "PlayerLeftCommand.h"
#include "CPlayerUpdater.h"

PlayerLeftCommand::PlayerLeftCommand(CPlayerUpdater* update)
{
	this->updater = update;
}


PlayerLeftCommand::~PlayerLeftCommand()
{
}

void PlayerLeftCommand::execute() {
	updater->pushLeft();
}
