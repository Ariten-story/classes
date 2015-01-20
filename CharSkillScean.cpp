#include "CharSkillScean.h"
#include "CharSkill_BG_Layer.h"
#include "CharSkill_HERO_Layer.h"
#include "CharSkill_SKILLMENU_Layer.h"

USING_NS_CC;

Scene* CharSkill::createScene()
{
	auto scene = Scene::create();

	auto layer_BG = CharSkill_BG::create();
	auto layer_Hero = CharSkill_Hero::create();
	auto layer_SKILLMenu = CharSkill_SKILLMENU::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_Hero);
	scene->addChild(layer_SKILLMenu);

	return scene;
}
