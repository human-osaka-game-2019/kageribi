#ifndef _SCENE_
#define _SCENE_

class SCENE
{
public:
	SCENE();
	~SCENE();

	enum STEP
	{
		LoadStep,
		MainStep,
		ReleaseStep
	};

	STEP step = LoadStep;

	virtual void UpdataScene() = 0;

	virtual void Loading() = 0;
	virtual void Processing() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;

};

#endif // !_SCENE_
