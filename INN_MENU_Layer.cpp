#include "INN_MENU_Layer.h"
#include "CharInfoScene.h"
#include "CharInvenScene.h"
#include "CharSkillScean.h"
#include "ShopScean.h"
#include "GameIntroScene.h"
#include "DefenceGameScene.h"

USING_NS_CC;

const int FONTSIZE = 20;
const int INTERVAL = 10;

bool INN_MENU::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}

	auto spr_1_n = Sprite::create("inn-btn-info-n.png");
	auto spr_1_s = Sprite::create("inn-btn-info-s.png");
	auto spr_2_n = Sprite::create("inn-btn-inven-n.png");
	auto spr_2_s = Sprite::create("inn-btn-inven-s.png");
	auto spr_3_n = Sprite::create("inn-btn-skill-n.png");
	auto spr_3_s = Sprite::create("inn-btn-skill-s.png");
	auto spr_4_n = Sprite::create("inn-btn-shop-n.png");
	auto spr_4_s = Sprite::create("inn-btn-shop-s.png");
	auto spr_5_n = Sprite::create("inn-btn-missionstart-n.png");
	auto spr_5_s = Sprite::create("inn-btn-missionstart-s.png");
	auto spr_6_n = Sprite::create("inn-btn-exit-n.png");
	auto spr_6_s = Sprite::create("inn-btn-exit-s.png");

	auto item_1 = MenuItemSprite::create(spr_1_n, spr_1_s, CC_CALLBACK_1(INN_MENU::CharInfoButton, this));
	auto item_2 = MenuItemSprite::create(spr_2_n, spr_2_s, CC_CALLBACK_1(INN_MENU::CharInvenButton, this));
	auto item_3 = MenuItemSprite::create(spr_3_n, spr_3_s, CC_CALLBACK_1(INN_MENU::CharSkillButton, this));
	auto item_4 = MenuItemSprite::create(spr_4_n, spr_4_s, CC_CALLBACK_1(INN_MENU::ShopButton, this));
	auto item_5 = MenuItemSprite::create(spr_5_n, spr_5_s, CC_CALLBACK_1(INN_MENU::MissionStartButton, this));
	auto item_6 = MenuItemSprite::create(spr_6_n, spr_6_s, CC_CALLBACK_1(INN_MENU::ExitButton, this));

	Size winSize = Director::getInstance()->getWinSize();

	auto menu = Menu::create(item_1, item_2, item_3, item_4, item_5, item_6, NULL);
	menu->alignItemsVertically();

	menu->setPosition(Point(winSize.width*3 / 4, winSize.height / 2));
	this->addChild(menu);

	return true;
}

void INN_MENU::CharInfoButton(Object* pSender)
{
	log("Info click");
	auto *pScene = CharInfo::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void INN_MENU::CharInvenButton(Object* pSender)
{
	log("Inven click");
	auto *pScene = CharInven::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void INN_MENU::CharSkillButton(Object* pSender)
{
	log("Skill click");
	auto *pScene = CharSkill::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void INN_MENU::ShopButton(Object* pSender)
{
	log("Shop click");
	auto *pScene = Shop::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void INN_MENU::MissionStartButton(Object* pSender)
{
	log("Mission click");
	auto *pScene = Defence::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}

void INN_MENU::ExitButton(Object* pSender)
{
	log("Back click");
	auto *pScene = GameIntro::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}