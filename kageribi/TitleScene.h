#ifndef TITLESCENE_HEADER
#define TITLESCENE_HEADER

#include "Scene.h"

class TITLE :public SCENE
{
public:

	TITLE();
	~TITLE();
	virtual void UpdataScene();

private:

	virtual void Loading();
	virtual void Processing();
	virtual void Draw();
	virtual void Release();
};


#endif // !TITLESCENE_HEADER