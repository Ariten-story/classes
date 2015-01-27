#include "GameTestScene.h"
#include "GameIntro_BG_Layer.h"
#include "Controller.h"

USING_NS_CC;

GameTestScene::GameTestScene()
{
}

GameTestScene::~GameTestScene()
{
}

Scene* GameTestScene::createScene()
{
	auto scene = Scene::create();

	auto layer_BG = GameIntro_BG::create();
	auto layer_controller = Controller::create();

	scene->addChild(layer_BG, 0);
	scene->addChild(layer_controller, 1);

	return scene;
}