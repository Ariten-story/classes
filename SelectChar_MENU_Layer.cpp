#include "SelectChar_MENU_Layer.h"
#include "CharSlotScene.h"
#include "INNScene.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 40;
bool clickcheck[3] = { false, false, false };
/*
SelectChar_MENU::SelectChar_MENU()
{
}
SelectChar_MENU::~SelectChar_MENU()
{
}
*/
bool SelectChar_MENU::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto pLabel1 = LabelTTF::create("Knight", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel2 = LabelTTF::create("Assassin", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel3 = LabelTTF::create("Archer", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel4 = LabelTTF::create("Back", "fonts/Paint Boy.ttf", FONTSIZE);

	auto MenuItem1 = MenuItemLabel::create(pLabel1, CC_CALLBACK_1(SelectChar_MENU::charButton, this));
	auto MenuItem2 = MenuItemLabel::create(pLabel2, CC_CALLBACK_1(SelectChar_MENU::charButton, this));
	auto MenuItem3 = MenuItemLabel::create(pLabel3, CC_CALLBACK_1(SelectChar_MENU::charButton, this));
	auto MenuItem4 = MenuItemLabel::create(pLabel4, CC_CALLBACK_1(SelectChar_MENU::backButton, this));

	MenuItem1->setColor(Color3B(0, 0, 0));
	MenuItem2->setColor(Color3B(0, 0, 0));
	MenuItem3->setColor(Color3B(0, 0, 0));
	MenuItem4->setColor(Color3B(0, 0, 0));

	MenuItem1->setTag(1);
	MenuItem2->setTag(2);
	MenuItem3->setTag(3);
	
	MenuItem4->setAnchorPoint(Point(1.0, 0.0));
	auto backMenu = Menu::create(MenuItem4, NULL);
	backMenu->setPosition(Point(winSize.width, 0));

	auto charMenu = Menu::create(MenuItem1, MenuItem2, MenuItem3, NULL);
	charMenu->alignItemsHorizontallyWithPadding(INTERVAL);
	charMenu->setPosition(Point(winSize.width / 2, winSize.height / 4));

	this->addChild(backMenu);
	this->addChild(charMenu);
	return true;
}

void SelectChar_MENU::charButton(Object* pSender)
{
	auto tItem = (MenuItem *)pSender;
	int i = tItem->getTag();

	Size winSize = Director::getInstance()->getWinSize();

	if (i == 1)
	{
		if (clickcheck[0] == false)
		{
			clickcheck[0] = true;
			clickcheck[1] = false;
			clickcheck[2] = false;
			this->removeChildByTag(12);
			this->removeChildByTag(13);
			this->removeChildByTag(4);

			auto SpriteKnight = Sprite::create("Knight.png");
			SpriteKnight->setPosition(Point((winSize.width) / 2, (winSize.height) / 2 + 100));
			SpriteKnight->setTag(11);

			auto pLabel5 = LabelTTF::create("OK", "fonts/Paint Boy.ttf", FONTSIZE);
			auto MenuItem5 = MenuItemLabel::create(pLabel5, CC_CALLBACK_1(SelectChar_MENU::selectButton, this));
			MenuItem5->setColor(Color3B(0, 0, 0));
			MenuItem5->setAnchorPoint(Point(0.5, 0.0));

			auto okMenu = Menu::create(MenuItem5, NULL);
			okMenu->setPosition(Point(winSize.width / 2, 0));
			okMenu->setTag(4);

			this->addChild(okMenu);
			this->addChild(SpriteKnight);

			log("Knight click");
		}
	}
	else if (i == 2)
	{
		if (clickcheck[1] == false)
		{
			clickcheck[0] = false;
			clickcheck[1] = true;
			clickcheck[2] = false;
			this->removeChildByTag(11);
			this->removeChildByTag(13);
			this->removeChildByTag(4);

			auto SpriteAssassin = Sprite::create("Assassin.png");
			SpriteAssassin->setPosition(Point((winSize.width) / 2, (winSize.height) / 2 + 100));
			SpriteAssassin->setTag(12);

			auto pLabel5 = LabelTTF::create("OK", "fonts/Paint Boy.ttf", FONTSIZE);
			auto MenuItem5 = MenuItemLabel::create(pLabel5, CC_CALLBACK_1(SelectChar_MENU::selectButton, this));
			MenuItem5->setColor(Color3B(0, 0, 0));
			MenuItem5->setAnchorPoint(Point(0.5, 0.0));

			auto okMenu = Menu::create(MenuItem5, NULL);
			okMenu->setPosition(Point(winSize.width / 2, 0));
			okMenu->setTag(4);

			this->addChild(okMenu);
			this->addChild(SpriteAssassin);

			log("Assassin click");
		}
	}
	else
	{
		if (clickcheck[2] == false)
		{
			clickcheck[0] = false;
			clickcheck[1] = false;
			clickcheck[2] = true;
			this->removeChildByTag(11);
			this->removeChildByTag(12);
			this->removeChildByTag(4);

			auto SpriteArcher = Sprite::create("Archer.png");
			SpriteArcher->setPosition(Point((winSize.width) / 2, (winSize.height) / 2 + 100));
			SpriteArcher->setTag(13);

			auto pLabel5 = LabelTTF::create("OK", "fonts/Paint Boy.ttf", FONTSIZE);
			auto MenuItem5 = MenuItemLabel::create(pLabel5, CC_CALLBACK_1(SelectChar_MENU::selectButton, this));
			MenuItem5->setColor(Color3B(0, 0, 0));
			MenuItem5->setAnchorPoint(Point(0.5, 0.0));

			auto okMenu = Menu::create(MenuItem5, NULL);
			okMenu->setPosition(Point(winSize.width / 2, 0));
			okMenu->setTag(4);

			this->addChild(okMenu);
			this->addChild(SpriteArcher);

			log("Archer click");
		}
	}
}
void SelectChar_MENU::backButton(Object* pSender)
{
	log("Back click");
	auto *pScene = CharSlot::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void SelectChar_MENU::selectButton(Object* pSender)
{
	log("OK click");
	auto *pScene = INN::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}