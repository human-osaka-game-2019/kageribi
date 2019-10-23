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

	enum SCENE_STATUS
	{
		Title,
		Game,
		Result
	};

	//STEP Step = LoadStep;

	virtual void UpdataScene();


protected:
	virtual void LoadStep();
	virtual void processing();
	virtual void Draw();
	virtual void Release();

};

#endif // !_SCENE_
