#ifndef _TITLESCENE_
#define _TITLESCENE_

#include "Scene.h"

class TITLE :public SCENE
{
public:

	TITLE();
	~TITLE();

	virtual void UpdataScene();
	virtual void Loading();
	virtual void Processing();
	virtual void Draw();
	virtual void Release();
};


#endif // !_TITLESCENE_