#include "CharInfoScene.h"
#include "CharInfo_BG_Layer.h"
#include "CharInfo_Hero_Layer.h"
#include "CharInfo_Menu_Layer.h"

USING_NS_CC;

Scene* CharInfo::createScene()
{
	auto scene = Scene::create();

	auto layer_BG = CharInfo_BG::create();
	auto layer_Hero = CharInfo_Hero::create();
	auto layer_Menu = CharInfo_MENU::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_Hero);
	scene->addChild(layer_Menu);

	return scene;
}
