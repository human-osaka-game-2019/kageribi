#ifndef _MAINLOOP_
#define _MAINLOOP_


struct LOOP
{
	enum SCENE_STATUS
	{
		Title,
		Game,
		Result
	};

	SCENE_STATUS state = Title;

	void UpdateScene();



};

#endif // !_MAINLOOP_

