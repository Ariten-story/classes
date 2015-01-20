#include "ShopScean.h"
#include "Shop_BG_Layer.h"
#include "Shop_Host_Layer.h"
#include "Shop_MENU_Layer.h"

USING_NS_CC;

Scene* Shop::createScene()
{
	auto scene = Scene::create();

	auto layer_BG = Shop_BG::create();
	auto layer_Host = Shop_Host::create();
	auto layer_Menu = Shop_MENU::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_Host);
	scene->addChild(layer_Menu);

	return scene;
}
