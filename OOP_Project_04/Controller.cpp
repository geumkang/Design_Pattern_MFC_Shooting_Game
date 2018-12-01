#include "Controller.h"



Controller::Controller()
{
}


Controller::~Controller()
{
}

void Controller::doAttack()
{
}

void Controller::doSpecial()
{
}

void Controller::doLeft()
{
}

void Controller::doRight()
{
}

void Controller::doUp()
{
	upCommand->execute();
}

void Controller::doDown()
{
}

void Controller::setUpCommand(Command * command)
{
	this->upCommand = command;
}

void Controller::setDownCommand(Command * command)
{
	this->downCommand = command;
}

void Controller::setLeftCommand(Command * command)
{
	this->leftCommand = command;
}

void Controller::setRightCommand(Command * command)
{
	this->rightCommand = command;
}

void Controller::setAttackCommand(Command * command)
{
	this->attackCommand = command;
}

void Controller::setSpecialCommand(Command * command)
{
	this->specialCommand = command;
}
