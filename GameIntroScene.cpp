#include "GameIntroScene.h"
#include "GameIntro_BG_Layer.h"
#include "GameIntro_MENU_Layer.h"
#include "GameIntro_Ani_Layer.h"

USING_NS_CC;

GameIntro::GameIntro()
{
}

GameIntro::~GameIntro()
{
}

Scene* GameIntro::createScene()
{
    auto scene = Scene::create();
 	
	auto layer_MENU = GameIntro_MENU::create();
	auto layer_BG = GameIntro_BG::create();
	auto layer_ANI = GameIntro_ANI::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_MENU);
	scene->addChild(layer_ANI);

	return scene;
}