#include "PlayerAttackCommand.h"
#include "CUpdater.h"
#include "CPlayerUpdater.h"


PlayerAttackCommand::PlayerAttackCommand(CUpdater* updater)
{
	this->updater = updater;
}


PlayerAttackCommand::~PlayerAttackCommand()
{
}

void PlayerAttackCommand::execute()
{
	((CPlayerUpdater*)this->updater)->pushAttack();
}
