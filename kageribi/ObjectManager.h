#ifndef OBJECTMANAGER_HEADER
#define OBJECTMANAGER_HEADER
#include <vector>


class OBJECTMANAGER
{
public:
	OBJECTMANAGER();
	~OBJECTMANAGER();

	virtual void Update();
	virtual void Draw();

private:

	std::vector<OBJECTMANAGER*> instance_list;

	void Entry(OBJECTMANAGER* instance);
	void Exit(int number);

};

#endif // !OBJECTMANAGER_HEADER
