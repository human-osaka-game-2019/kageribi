#include "ObjectManager.h"

void OBJECTMANAGER::Update()
{

}

void OBJECTMANAGER::Draw()
{

}

void OBJECTMANAGER::Entry(OBJECTMANAGER* instance)
{
	this->instance_list.push_back(instance);
}

void OBJECTMANAGER::Exit(int number)
{
	this->instance_list.erase(this->instance_list.begin() + number);
}

OBJECTMANAGER::OBJECTMANAGER()
{

}

OBJECTMANAGER::~OBJECTMANAGER()
{

}
