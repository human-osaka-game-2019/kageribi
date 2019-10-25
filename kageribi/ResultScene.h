#ifndef _RESULTSCENE_
#define _RESULTSCENE_

#include "Scene.h"

class RESULT :public SCENE
{
public:

	RESULT();
	~RESULT();

	virtual void UpdataScene();
	virtual void Loading();
	virtual void Processing();
	virtual void Draw();
	virtual void Release();
};

#endif // !_RESULTSCENE_

