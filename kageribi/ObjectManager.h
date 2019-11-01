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

	std::vector<char*> instance_list;

	void Entry(char* instance);
	void Exit(int number);

};

#endif // !_OBJECTMANAGER_

