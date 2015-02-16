#include "PopScene.h"
#include "Pop_Layer.h"

USING_NS_CC;

Pop::Pop()
{
}
Pop::~Pop()
{
}

Scene* Pop::createScene()
{
	auto scene = Scene::create();

	auto layer_Pop = PopLayer::create();
	

	scene->addChild(layer_Pop);
	
	return scene;
}
