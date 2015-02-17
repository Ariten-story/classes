#include "Castle.h"

Castle::Castle()
{
	labelHP = NULL;
	castleBody = NULL; //Enemy Castle Sprite.
	maxEnergy = 0; //Castle Max HP.
	curEnergy = 0; //Castle Current HP.
	isEnemyCastle = true;
}
Castle::~Castle()
{
	log("delete castle");
	release();
}

//Delete Castle.
void Castle::release()
{
	if (castleBody != NULL)
	{
		castleBody->removeFromParentAndCleanup(true);
		castleBody = NULL;
	}
}
//Castle maker
Castle* Castle::createCastle(int Type)
{
	const char *fileName;

	Castle* castle = new Castle();

	if (Type == 0)
	{
		fileName = "Ecastle.png";
		castle->setIsEnemy(true);
	}
	else if (Type == 1)
	{
		fileName = "FCastle.png";
		castle->setIsEnemy(false);
	}
	castle->setEnergey(1000);

	auto castleBody = Sprite::create(fileName);
	castle->setCastleBody(castleBody);
	castle->setHpBar();

	return castle;

	CC_SAFE_DELETE(castle);
}

//Castle set Energey
void Castle::setEnergey(float max)
{
	maxEnergy = curEnergy = max;
}

//Castle attacked
float Castle::subEnergy(float damage)
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

//Castle Sprite
void Castle::setCastleBody(Sprite* sprite)
{
	castleBody = sprite;
}

//return Castle Sprite
Sprite* Castle::getCastleBody()
{
	return castleBody;
}

void Castle::setHpBar()
{
	//라벨초기화
	labelHP = Label::createWithSystemFont("", "", 40);
	labelHP->setAnchorPoint(Point(0.5, 0));
	labelHP->setPosition(Point(castleBody->getContentSize().width / 2, castleBody->getContentSize().height));
	labelHP->setColor(Color3B::BLACK);
	labelHP->setString(StringUtils::format("%d/%d", maxEnergy,curEnergy));
	castleBody->addChild(labelHP);
}
//set isEnemyCastle
void Castle::setIsEnemy(bool Enemy)
{
	isEnemyCastle = Enemy;
}
//get isEnemyCastle
bool Castle::getIsEnemy()
{
	return isEnemyCastle;
}