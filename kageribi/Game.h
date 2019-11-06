#ifndef _GAME_
#define _GAME_

#include "Scene.h"

class GAME :public SCENE
{
public:

	GAME();
	~GAME();
	virtual void UpdataScene();

private:

	virtual void Loading();
	virtual void Processing();
	virtual void Draw();
	virtual void Release();
};

#endif // !_GAME_

