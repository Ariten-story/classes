#include "Defence_UI_Layer.h"
//#include "Defence_BG_Layer.h"
//#include "DefenceGameScene.h"


USING_NS_CC;

bool Defence_UI::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto UI_bg = Sprite::create("Defence_UI_bg.png");
	auto UI_catlehp = Sprite::create("Defence_UI_catlehp.png");
	auto UI_minimap = Sprite::create("Defence_UI_minimap.png");
	auto charUI_bg = Sprite::create("Defence_charUI_bg.png");
	auto charUI_hpmp = Sprite::create("Defence_charUI_hpmp.png");
	auto charUI_btn_skill = Sprite::create("Defence_charUI_btn_skill.png");

	auto charUI_rudder = Sprite::create("Defence_charUI_rudder.png");
	



	//if (!UI_bg && !UI_catlehp && !UI_minimap && !charUI_bg && !charUI_hpmp && !charUI_btn_skill && !charUI_rudder)
	if (!UI_bg && !UI_catlehp && !UI_minimap && !charUI_bg && !charUI_hpmp && !charUI_btn_skill)
	{
		return false;
	}
	UI_bg->setPosition(Point(winSize.width / 2, winSize.height / 2));
	UI_catlehp->setPosition(Point(winSize.width*5 / 32, winSize.height*91 / 100));
	UI_minimap->setPosition(Point(winSize.width*53  / 64, winSize.height*17  / 20));
	charUI_bg->setPosition(Point(winSize.width / 2, winSize.height / 9));
	charUI_hpmp->setPosition(Point(winSize.width*89 / 200, winSize.height / 10));
	charUI_btn_skill->setPosition(Point(winSize.width*39 / 50, winSize.height / 9));
	//charUI_rudder->setPosition(Point(winSize.width / 6, winSize.height / 9));

	this->addChild(UI_bg);
	this->addChild(UI_catlehp);
	this->addChild(UI_minimap);
	this->addChild(charUI_bg);
	this->addChild(charUI_hpmp);
	this->addChild(charUI_btn_skill);
	//this->addChild(charUI_rudder);

	//방향키 테스트 테스트
	auto charUI_rudder_s = Sprite::create("rudder_s.png");
	auto item_1 = MenuItemSprite::create(charUI_rudder, charUI_rudder_s, CC_CALLBACK_1(Defence_UI::Rudder, this));

	auto menu = Menu::create(item_1, NULL);
	//menu->alignItemsVerticallyWithPadding(20);
	menu->setPosition(Point(winSize.width / 6, winSize.height / 9));
	this->addChild(menu);
	//방향키 테스트 테스트
	
	return true;
}

void Defence_UI::Rudder(Object* pSender)
{
	pDefence_bg = dynamic_cast< Defence_BG* >(getParent()->getChildByTag(0));
	//부모 포인터에서 자식중에 태그가 0인 bg 포인터 받아와서
	pDefence_bg->chbg_direction();
	//배경화면 방향 바꾸기 함수 호출하는데 안된다고?
}
