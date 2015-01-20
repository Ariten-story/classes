#include "CHARINVEN_MENU_Layer.h"
#include "INNScene.h"



USING_NS_CC;

const int FONTSIZE = 20;
const int INTERVAL = 10;

bool CharInven_MENU::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}
	auto spr_1_n = Sprite::create("inven-btn-back-n.png");
	auto spr_1_s = Sprite::create("inven-btn-back-s.png");

	auto item_1 = MenuItemSprite::create(spr_1_n, spr_1_s, CC_CALLBACK_1(CharInven_MENU::BackButton, this));

	Size winSize = Director::getInstance()->getWinSize();

	auto menu = Menu::create(item_1, NULL);
	menu->alignItemsVerticallyWithPadding(INTERVAL);
	//menu->alignItemsVertically();

	menu->setPosition(Point(winSize.width * 18 / 20, winSize.height / 25));
	this->addChild(menu);

	return true;
}

void CharInven_MENU::BackButton(Object* pSender)
{
	auto *pScene = INN::createScene();
	Director::getInstance()->replaceScene(createTransition(17, 1.0, pScene));
}


TransitionScene* CharInven_MENU::createTransition(int nIndex, float t, Scene* s)
{
	Director::getInstance()->setDepthTest(false);
	switch (nIndex)
	{

	case 0:
		return TransitionJumpZoom::create(t, s);

	case 17:
		return TransitionFade::create(t, s);

	case 18:
		return TransitionFade::create(t, s, Color3B::WHITE);
	}
}