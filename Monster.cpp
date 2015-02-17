#include "Monster.h"

Monster::Monster()
{
	monsterBody = NULL;
	//hp라벨
	labelHP = NULL;
	maxEnergy = 0;
	curEnergy = 0;
	isEnemy = true;
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
	monster->setIsEnemy(true);

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

		labelHP->setString(StringUtils::format("%d/%d", maxEnergy, curEnergy));
	}
	else
	{
		labelHP->setString(StringUtils::format("%d/%d", maxEnergy, curEnergy));
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
void Monster::setIsEnemy(bool check)
{
	isEnemy = check;
}

//몬스터 식별 반환 함수.
bool Monster::getIsEnemy()
{
	return isEnemy;
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
	//라벨초기화
	labelHP = Label::createWithSystemFont("", "", 40);
	labelHP->setAnchorPoint(Point(0.5, 0));
	labelHP->setPosition(Point(monsterBody->getContentSize().width / 2, monsterBody->getContentSize().height));
	labelHP->setColor(Color3B::BLACK);
	labelHP->setString(StringUtils::format("%d/%d", maxEnergy, curEnergy));
	monsterBody->addChild(labelHP);
}