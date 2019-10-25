#ifndef _OBJECTMANAGER_
#define _OBJECTMANAGER_
#include <vector>

using namespace std;

class OBJECTMANAGER
{
public:
	OBJECTMANAGER();
	~OBJECTMANAGER();

	virtual void Update();
	virtual void Draw();

private:

	vector<char*> instance;

	void Entry(char* instance);
	void Exit(int number);

};

#endif // !_OBJECTMANAGER_

