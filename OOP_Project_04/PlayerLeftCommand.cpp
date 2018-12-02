#include "PlayerLeftCommand.h"
#include "CPlayerUpdater.h"

PlayerLeftCommand::PlayerLeftCommand(CUpdater* update)
{
	this->updater = update;
}


PlayerLeftCommand::~PlayerLeftCommand()
{
}

void PlayerLeftCommand::execute() {
	((CPlayerUpdater*)updater)->pushLeft();
}
