#include "Monster.h"

Monster::Monster()
{
	monsterBody = NULL;
	hpBar = NULL;
	maxEnergy = 0;
	curEnergy = 0;
	isEnermy = true;
	defensivePower = 0;
	speedOfMove = 0;
}
Monster::~Monster()
{
	log("delete monster");
	release();
}

//몬스터 삭제 함수.
void Monster::release()
{
	if (monsterBody != NULL)
	{
		monsterBody->removeFromParentAndCleanup(true);
		monsterBody = NULL;
	}
}

//타입별 몬스터 생성 함수.
Monster* Monster::createWithType(int Type)
{
	const char *fileName;

	Monster* monster = new Monster();

	//이부분 추후에 if~else로 구성.
	fileName = "Monster1.png";
	monster->setEnergey(200);
	monster->setDefensivePower(0);
	monster->setSpeedOfMove(70);
	monster->setIsEnermy(true);

	auto monsterBody = Sprite::create(fileName);
	monster->setMonsterBody(monsterBody);
	monster->setHpBar();

	return monster;

	CC_SAFE_DELETE(monster);
}

//몬스터 max에너지 설정 함수.
void Monster::setEnergey(float max)
{
	maxEnergy = curEnergy = max;
}

//몬스터 받는피해처리 함수.
float Monster::subEnergy(float damage)
{
	curEnergy -= damage;
	if (curEnergy < 0)
	{
		curEnergy = 0;
	}
	else
	{
		auto newWidth = (hpBar->getContentSize().width*curEnergy) / maxEnergy;
		hpBar->setTextureRect(Rect(0,0,newWidth,5));
	}
	return curEnergy;
}

//몬스터 sprite 설정 함수.
void Monster::setMonsterBody(Sprite* sprite)
{
	monsterBody = sprite;
}

//몬스터 sprite 반환 함수.
Sprite* Monster::getMonsterBody()
{
	return monsterBody;
}

//몬스터 식별 설정 함수.
void Monster::setIsEnermy(bool check)
{
	isEnermy = check;
}

//몬스터 식별 반환 함수.
bool Monster::getIsEnermy()
{
	return isEnermy;
}

//몬스터 방어력 설정 함수.
void Monster::setDefensivePower(float defensive)
{
	defensivePower = defensive;
}

//몬스터 방어력 반환 함수.
float Monster::getDefensivePower()
{
	return defensivePower;
}

//몬스터 이동속도 설정 함수.
void Monster::setSpeedOfMove(float speed)
{
	speedOfMove = speed;
}

//몬스터 이동속도 반환 함수.
float Monster::getSpeedOfMove()
{
	return speedOfMove;
}

//몬스터 에너지바 설정 함수.
void Monster::setHpBar()
{
	auto hpSize = monsterBody->getContentSize().width;
	hpBar = Sprite::create("white-512x512.png");
	hpBar->setTextureRect(Rect(0, 0, int(hpSize), 5));
	hpBar->setColor(Color3B::RED);
	Size parentSize = monsterBody->getContentSize();
	hpBar->setPosition(Point(0, parentSize.height + 10));
	hpBar->setAnchorPoint(Point(0.0, 0.5));
	monsterBody->addChild(hpBar);
}