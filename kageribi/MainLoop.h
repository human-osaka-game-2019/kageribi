#ifndef MAINLOOP_HEADER
#define MAINLOOP_HEADER

#include "TitleScene.h"
#include "Game.h"
#include "ResultScene.h"

class LOOP
{
public:
	void UpdateScene();

private:
	TITLE title;
	GAME game;
	RESULT result;

	enum SCENE_STATUS
	{
		Title,
		Game,
		Result
	};

	SCENE_STATUS state = Title;




};

#endif // !MAINLOOP_HEADER

