#include "ObjectManager.h"

void OBJECTMANAGER::Update()
{

}

void OBJECTMANAGER::Draw()
{

}

void OBJECTMANAGER::Entry(char* instance)
{
	this->instance.push_back(instance);
}

void OBJECTMANAGER::Exit(int number)
{
	this->instance.erase(this->instance.begin() + number);
}

OBJECTMANAGER::OBJECTMANAGER()
{

}

OBJECTMANAGER::~OBJECTMANAGER()
{

}