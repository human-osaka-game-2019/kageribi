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

	STEP Step = LoadStep;

	virtual void UpdataScene() = 0;

	virtual void Loading() = 0;
	virtual void Processing() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;

private:
	int scene_state;
};

#endif // !_SCENE_
