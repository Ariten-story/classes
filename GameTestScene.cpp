#include "GameTestScene.h"
#include "GameMaker.h"

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

	auto layer = GameMaker::create();

	scene->addChild(layer, 0);

	return scene;
}