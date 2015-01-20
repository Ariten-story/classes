#include "OptionScene.h"
#include "Option_BG_Layer.h"
#include "Option_MENU_Layer.h"

USING_NS_CC;

Option::Option()
{
}

Option::~Option()
{
}

Scene* Option::createScene()
{
	auto scene = Scene::create();

	auto layer_MENU = Option_MENU::create();
	auto layer_BG = Option_BG::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_MENU);

	return scene;
}