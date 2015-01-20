#include "CharInfo_MENU_Layer.h"
#include "INNScene.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 70;

bool CharInfo_MENU::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto spr_Menu_1 = Sprite::create("images/Info/Info_First.png");
	auto spr_Menu_2 = Sprite::create("images/Info/Info_Second.png");
	auto spr_Menu_3 = Sprite::create("images/Info/Info_Third.png");
	auto spr_Menu_4 = Sprite::create("images/Info/Info_Out.png");

	auto MenuItem1 = MenuItemSprite::create(spr_Menu_1, spr_Menu_1, CC_CALLBACK_1(CharInfo_MENU::Info_First, this));
	auto MenuItem2 = MenuItemSprite::create(spr_Menu_2, spr_Menu_2, CC_CALLBACK_1(CharInfo_MENU::Info_Second, this));
	auto MenuItem3 = MenuItemSprite::create(spr_Menu_3, spr_Menu_3, CC_CALLBACK_1(CharInfo_MENU::Info_Third, this));
	auto MenuItem4 = MenuItemSprite::create(spr_Menu_4, spr_Menu_4, CC_CALLBACK_1(CharInfo_MENU::Info_Out, this));
	

	auto pMenu = Menu::create(MenuItem1, MenuItem2, MenuItem3,MenuItem4, NULL);
	pMenu->alignItemsVerticallyWithPadding(INTERVAL);
	pMenu->setPosition(Point(winSize.width/2 + winSize.width/3, winSize.height / 2));
	this->addChild(pMenu);

	return true;
}

void CharInfo_MENU::Info_First(Object* pSender)
{
	
}
void CharInfo_MENU::Info_Second(Object* pSender)
{
	
}
void CharInfo_MENU::Info_Third(Object* pSender)
{

}

void CharInfo_MENU::Info_Out(Object* pSender)
{
	auto *pScene = INN::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
