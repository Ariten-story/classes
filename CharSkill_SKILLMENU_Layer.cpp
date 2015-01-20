#include "CharSkill_SKILLMENU_Layer.h"
#include "INNScene.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 40;

bool CharSkill_SKILLMENU::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}
	
	Size winSize = Director::getInstance()->getWinSize();

	auto spr_Skill_BG = Sprite::create("images/CharSkill/SkillBG.png");
	auto Skill_1 = Sprite::create("images/charskill/skill1.png");
	auto Skill_2 = Sprite::create("images/charskill/skill2.png");
	auto Skill_3 = Sprite::create("images/charskill/skill3.png");


	//Skill _ BG
	spr_Skill_BG->setAnchorPoint(Point(0.5, 0.5));
	spr_Skill_BG->setPosition(Point(winSize.width /2 + winSize.width/4, winSize.height/2));
	spr_Skill_BG->setScaleY(winSize.height / spr_Skill_BG->getContentSize().height / 2 + winSize.height / spr_Skill_BG->getContentSize().height / 4);
	spr_Skill_BG->setScaleX(winSize.width / spr_Skill_BG->getContentSize().width *0.4);


	//Skill _ P

	Size BGSize = spr_Skill_BG->getContentSize();

	auto pLabel1 = LabelTTF::create("Skill Point", "fonts/Paint Boy.ttf", FONTSIZE);
	pLabel1->setPosition(Point(BGSize.width / 4, BGSize.height + 20));

	auto item_1 = MenuItemSprite::create(Skill_1, Skill_1, CC_CALLBACK_1(CharSkill_SKILLMENU::SkillClick, this));
	auto item_2 = MenuItemSprite::create(Skill_2, Skill_2, CC_CALLBACK_1(CharSkill_SKILLMENU::SkillClick, this));
	auto item_3 = MenuItemSprite::create(Skill_3, Skill_3, CC_CALLBACK_1(CharSkill_SKILLMENU::SkillClick, this));

	auto SkillMenu_1 = Menu::create(item_1, item_2, item_3, NULL);
	SkillMenu_1->alignItemsHorizontallyWithPadding(INTERVAL);
	SkillMenu_1->setPosition(Point(BGSize.width / 2 , BGSize.height*0.8 ));
	
	
	
	//Insert
	
	this->addChild(spr_Skill_BG);
	spr_Skill_BG->addChild(SkillMenu_1);
	spr_Skill_BG->addChild(pLabel1);

	///Back
	auto pLabel4 = LabelTTF::create("Back", "fonts/Paint Boy.ttf", FONTSIZE);

	auto MenuItem4 = MenuItemLabel::create(pLabel4, CC_CALLBACK_1(CharSkill_SKILLMENU::BackButton, this));

	
	MenuItem4->setColor(Color3B(255, 255, 255));
	MenuItem4->setPosition(Point(winSize.width, 0));
	MenuItem4->setAnchorPoint(Point(1.0, 0.0));
	auto BackMenu = Menu::create(MenuItem4, NULL);
	BackMenu->setPosition(Point::ZERO);



	this->addChild(BackMenu);


	return true;
}


void CharSkill_SKILLMENU::BackButton(Object* pSender)
{
	auto pScene = INN::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}

void CharSkill_SKILLMENU::SkillClick(Object* pSender)
{
	log("SkillClick");
}