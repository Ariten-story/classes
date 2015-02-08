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

//���� ���� �Լ�.
void Monster::release()
{
	if (monsterBody != NULL)
	{
		monsterBody->removeFromParentAndCleanup(true);
		monsterBody = NULL;
	}
}

//Ÿ�Ժ� ���� ���� �Լ�.
Monster* Monster::createWithType(int Type)
{
	const char *fileName;

	Monster* monster = new Monster();

	//�̺κ� ���Ŀ� if~else�� ����.
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

//���� max������ ���� �Լ�.
void Monster::setEnergey(float max)
{
	maxEnergy = curEnergy = max;
}

//���� �޴�����ó�� �Լ�.
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

//���� sprite ���� �Լ�.
void Monster::setMonsterBody(Sprite* sprite)
{
	monsterBody = sprite;
}

//���� sprite ��ȯ �Լ�.
Sprite* Monster::getMonsterBody()
{
	return monsterBody;
}

//���� �ĺ� ���� �Լ�.
void Monster::setIsEnermy(bool check)
{
	isEnermy = check;
}

//���� �ĺ� ��ȯ �Լ�.
bool Monster::getIsEnermy()
{
	return isEnermy;
}

//���� ���� ���� �Լ�.
void Monster::setDefensivePower(float defensive)
{
	defensivePower = defensive;
}

//���� ���� ��ȯ �Լ�.
float Monster::getDefensivePower()
{
	return defensivePower;
}

//���� �̵��ӵ� ���� �Լ�.
void Monster::setSpeedOfMove(float speed)
{
	speedOfMove = speed;
}

//���� �̵��ӵ� ��ȯ �Լ�.
float Monster::getSpeedOfMove()
{
	return speedOfMove;
}

//���� �������� ���� �Լ�.
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