#include "MainLoop.h"

void LOOP::UpdateScene()
{

	switch(state)
	{
	case SCENE_STATUS::Title:
		title.UpdataScene();
		break;
	case SCENE_STATUS::Game:
		game.UpdataScene();
		break;
	case SCENE_STATUS::Result:
		result.UpdataScene();
		break;

	default:
		break;
	}
}