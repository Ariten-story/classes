#include "Castle.h"

Castle::Castle()
{
	EnemyCastleBody = NULL; //Enemy Castle Sprite.
	FriendCastleBody = NULL; //Friend Castle Sprite.
	FriendhpBar = NULL; //Friend hp Sprite.
	F_Castle_maxEnergy = 0; //Castle Max HP.
	F_Castle_curEnergy = 0; //Castle Current HP.

}
Castle::~Castle()
{
	log("delete castle");
	
}



//Castle maker
Castle* Castle::createCastle(int Type)
{
	const char *ffileName;
	const char *efileName;

	Castle* castle = new Castle();

	ffileName = "FCastle.png";
	efileName = "ECastle.png";
	castle->setEnergey(200);

	auto EnemyCastleBody = Sprite::create(efileName);
	auto FriendCastleBody = Sprite::create(ffileName);
	castle->setECastleBody(EnemyCastleBody);
	castle->setFCastleBody(FriendCastleBody);
	castle->setHpBar();

	return castle;

	CC_SAFE_DELETE(castle);
}

//Castle set Energey
void Castle::setEnergey(float max)
{
	F_Castle_maxEnergy = F_Castle_curEnergy = max;
}

//Castle attacked
float Castle::subEnergy(float damage)
{
	F_Castle_curEnergy -= damage;
	if (F_Castle_curEnergy < 0)
	{
		F_Castle_curEnergy = 0;
	}
	else
	{
		auto newWidth = (FriendhpBar->getContentSize().width*F_Castle_curEnergy) / F_Castle_maxEnergy;
		FriendhpBar->setTextureRect(Rect(0, 0, newWidth, 5));
	}
	return F_Castle_curEnergy;
}

//Castle Sprite
void Castle::setECastleBody(Sprite* sprite)
{
	EnemyCastleBody = sprite;
}

void Castle::setFCastleBody(Sprite* sprite)
{
	FriendCastleBody = sprite;
}


//return Castle Sprite
Sprite* Castle::getFCastleBody()
{
	return FriendCastleBody;
}

Sprite* Castle::getECastleBody()
{
	return EnemyCastleBody;
}


void Castle::setHpBar()
{
	auto hpSize = FriendCastleBody->getContentSize().width;
	FriendhpBar = Sprite::create("white-512x512.png");
	FriendhpBar->setTextureRect(Rect(0, 0, int(hpSize), 5));
	FriendhpBar->setColor(Color3B::RED);
	Size parentSize = FriendCastleBody->getContentSize();
	FriendhpBar->setPosition(Point(0, parentSize.height + 10));
	FriendhpBar->setAnchorPoint(Point(0.0, 0.5));
	FriendCastleBody->addChild(FriendhpBar);
}