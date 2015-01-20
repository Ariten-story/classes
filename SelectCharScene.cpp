#include "SelectCharScene.h"
#include "SelectChar_BG_Layer.h"
#include "SelectChar_MENU_Layer.h"
#include "SelectChar_ANI_Layer.h"

USING_NS_CC;

SelectChar::SelectChar()
{
}
SelectChar::~SelectChar()
{
}

Scene* SelectChar::createScene()
{
	auto scene = Scene::create();

	auto layer_MENU = SelectChar_MENU::create();
	auto layer_BG = SelectChar_BG::create();
	auto layer_ANI = SelectChar_ANI::create();

	scene->addChild(layer_BG,0);
	scene->addChild(layer_MENU,2);
	scene->addChild(layer_ANI,1);

	return scene;
}

