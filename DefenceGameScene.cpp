#include "Defence_UI_Layer.h"
#include "Defence_BG_Layer.h"
#include "DefenceGameScene.h"

USING_NS_CC;


Scene* Defence::createScene()
{
	auto scene = Scene::create();

	auto layer_BG = Defence_BG::create();
	auto layer_UI = Defence_UI::create();

	scene->addChild(layer_BG);
	scene->addChild(layer_UI);

	return scene;
}
