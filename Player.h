#include "cocos2d.h"
using namespace cocos2d;

class Player
{
private:
	Player();
	~Player();
	static Player* inst;
	Sprite* PlayerChar;

public:
	
	static Player* getInstance();
	void setCharacter(Sprite* character);
	Sprite* getCharacter();
};

