#include "CharSlotScene.h"
#include "CharSlot_BG_Layer.h"
#include "CharSlot_MENU_Layer.h"

USING_NS_CC;

CharSlot::CharSlot()
{
}

CharSlot::~CharSlot()
{
}

Scene* CharSlot::createScene()
{
	auto scene = Scene::create();

	auto layer_BG = CharSlot_BG::create();
	auto layer_MENU = CharSlot_MENU::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_MENU);

	return scene;
}
