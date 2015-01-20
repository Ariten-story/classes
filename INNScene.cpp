#include "INNScene.h"
#include "INN_MENU_Layer.h"
#include "INN_BG_Layer.h"
#include "INN_CHAR_Layer.h"


USING_NS_CC;


Scene* INN::createScene()
{
	auto scene = Scene::create();

	auto layer_MENU = INN_MENU::create();
	auto layer_BG = INN_BG::create();
	auto layer_CHAR = INN_CHAR::create();

	scene->addChild(layer_BG,0);
	scene->addChild(layer_CHAR,1);
	scene->addChild(layer_MENU,2);
	

	return scene;
}