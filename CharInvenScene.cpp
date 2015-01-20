#include "CharInvenScene.h"
#include "CharInven_BG_Layer.h"
#include "CharInven_CHAR_Layer.h"
#include "CharInven_EQUIP_Layer.h"
#include "CharInven_INVEN_Layer.h"
#include "CharInven_MENU_Layer.h"

USING_NS_CC;


Scene* CharInven::createScene()
{
	auto scene = Scene::create();

	auto layer_MENU = CharInven_MENU::create();
	auto layer_BG = CharInven_BG::create();
	auto layer_CHAR = CharInven_CHAR::create();
	auto layer_INVEN = CharInven_INVEN::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_CHAR);
	scene->addChild(layer_MENU);
	scene->addChild(layer_INVEN);


	return scene;
}